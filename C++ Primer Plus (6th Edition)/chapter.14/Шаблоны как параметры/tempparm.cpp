/* Шаблоны как параметры 
Мы уже видели, что шаблоны могут иметь параметры типа, такие как typename Т, и нетипизированные параметры вроде int n. 
Шаблоны также могут иметь параметры, которые сами являются шаблонами. 
Это еще одно дополнение, связанное с шаблонами, которое использовалось для реализации STL. 
В листинге 14.21 показан пример, который начинается со следующих строк: 
template <template <typename T> class Thing> 
class Crab 
Здесь template <typename T> class Thing — параметр-шаблон, причем template <typename T> class — тип, a Thing — параметр. 
Что это означает? Предположим, имеется объявление Crab<King> legs; 
Чтобы оно работало, аргумент шаблона King должен быть шаблонным классом, а его объявление должно соответствовать объявлению параметра-шаблона Thing: 
template <typename T> 
class King {...}; 
Класс Crab в листинге 14.21 объявляет два объекта: 
Thing<int> si; 
Thing<double> s2; 
Предыдущее объявление для legs привело бы к подстановке King<int> вместо Thing<int> и King<double> вместо Thing<double>. 
Однако в листинге 14.21 приведено следующее объявление: 
Crab<Stack> nebula; 
Поэтому в данном случае Thing<int> реализуется как Stack<int>, a Thing<double> — как Stack<double>. 
В общем, параметр шаблона Thing заменяется любым шаблонным типом, используемым в качестве аргумента шаблона в объявлении объекта Crab. 
Объявление класса Crab основано на трех предположениях о шаблонном классе, представленном параметром Thing. 
Этот класс должен содержать методы push() и pop(), а эти методы должны иметь определенный интерфейс. 
Класс Crab может использовать любой шаблонный класс, который соответствует типу Thing и содержит методы push() и pop(). 
В этой главе рассматривается один такой класс — шаблон Stack, определенный в stacktp.h. 
Этот класс и применяется в примере. 
Листинг 14.21. texnpparm.cpp */

// tempparm.cpp — шаблоны как параметры 
#include <iostream>
#include "stacktp.h"

template <template <typename T> class Thing>
class Crab
{
    private:
        Thing<int> s1;
        Thing<double> s2;
    public:
        Crab() {};
        // Предполагается, что класс thing имеет члены push() и pop () 
        bool push(int a, double x) { return s1.push(a) && s2.push(x); }
        bool pop(int &a, double &x) {return s1.pop(a) && s2.pop(x); }
};
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Crab<Stack> nebula;
    // Stack должен соответствовать шаблону template <typename T> class Thing 
    int ni;
    double nb;
    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
            // Ввод пар чисел int и double 
    while(cin >> ni >> nb && ni > 0 && nb > 0)
    {
        if(!nebula.push(ni, nb))
            break;
    }
    while(nebula.pop(ni, nb))
        cout << ni << ", " << nb << endl;
        cout << "Done.\n";
        return 0;
}
/*
Шаблонные параметры допускается смешивать с обычными параметрами.  
Например, объявление класса Crab может начинаться так: 
template <template <typename T> class Thing, typename U, typename V> 
class Crab 
{ 
private: 
Thing<U> si; 
Thing<V> s2; 
Сейчас типы, сохраняемые в членах si и s2, являются обобщенными, а не жестко закодированными типами. 
Поэтому в программе потребуется изменить определение nebula следующим образом: 
Crab<Stack, int, double> nebula; // T=Stack, U=int, V=double 
Шаблонный параметр Т является шаблонным типом, а параметры типов U и V — нешаблонными типами. 
*/