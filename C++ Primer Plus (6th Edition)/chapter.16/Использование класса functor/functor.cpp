/* Здесь одно значение (ѵ) передается как аргумент функции, а второй аргумент (cutoff) устанавливается конструктором класса. 
Располагая таким определением, можно инициализировать разные объекты TooBig разными граничными значениями для их использования в вызовах remove_if(). 
Этот подход продемонстрирован в листинге 16.15. 
Листинг 16.15. functor.срр */
// functor.срр — использование класса functor 
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T> // класс функтора определяет operator()() 
class TooBig
{
    private:
        T cutoff;
    public:
        TooBig(const T & t) : cutoff(t) {}
        bool operator() (const T &v)
        {
            return v > cutoff;
        }
};
void outint(int n)
{
    std::cout << n << " ";
}

int main()
{
    using std::list;
    using std::cout;
    using std::endl;

    TooBig<int> f100(100);                      // предельное значение = 100 
    int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10);        // конструктор диапазона 
    list<int> etcetera(vals, vals + 10);

    // Вместо этого в C++11 можно использовать следующий код: 
    // list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201}; 
    // list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201}; 
    cout << "Original list:\n";                 // исходные списки 
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    yadayada.remove_if(f100);               // использование именованного функционального объекта 
    etcetera.remove_if(TooBig<int>(200));   // конструирование функционального объекта 
    cout << "Trimmed list:\n";              // усеченные списки 
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    return 0;
}
/*
Один из функторов (f100) является объявленным объектом, а второй (TooBig<int>(200)) — анонимным объектом, который создан вызовом конструктора. 
Предположим, что имеется шаблонная функция с двумя аргументами: 
template <class T> 
bool tooBig (const T & val, const T & lim) 
{ 
    return val > lim; 
} 
Чтобы преобразовать ее в функциональный объект с одним аргументом, можно использовать класс: 
template<class T> 
class TooBig2 
{ 
    private: 
        Т cutoff; 
    public: 
        TooBig2(const T & t) : cutoff(t) {} 
        bool operator()(const T & v) { return tooBig<T>(v, cutoff); } 
}; 
Это значит, что можно написать следующий код: 
T6oBig2<int> tBIOO(100); 
int x; 
cin >> х; 
if (tBIOO (x) ) // то же что и if (tooBig (x, 100) ) 
Таким образом, вызов tBIOO (100) эквивалентен tooBig(x,100), но функция с двумя аргументами преобразуется в функциональный объект с одним аргументом, а второй аргумент служит для конструирования функционального объекта. 
Короче говоря, функтор TooBig2 — это адаптер функции, приспосабливающий функцию к требованиям другого интерфейса. 
Как отмечено в листинге, средство списка инициализаторов C++11 упрощает инициализацию. Код 
intvals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201}; 
list<int> yadayada(vals, vals + 10); // конструктор диапазона 
list<int> etcetera(vals, vals + 10); 
можно заменить следующим: 
list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201}; 
list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201}; 
*/