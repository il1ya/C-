/* Использование нескольких параметров типа 
Допускается создание шаблонов с несколькими параметрами типа. Предположим, что требуется класс, содержащий два вида значений. 
Для этой цели можно создать шаблонный класс Pair. (Между прочим, STL содержит подобный шаблон, который называется pair.)
В листинге 14.19 приведен небольшой пример. В нем методы first() const и second() const выводят хранимые значения, а методы first() и 
second(), благодаря возврату ссылок на данные-члены класса Pair, позволяют присвоить хранимым величинам новые значения. 
Листинг 14.19. pairs.срр */
// pairs.срр — определение и использование шаблона Pair 
#include <iostream>
#include <string>

template <class T1, class T2>

class Pair
{
    private:
        T1 a;
        T2 b;
    public:
        T1 &first();
        T2 &second();
        T1 first() const {return a;}
        T2 second() const {return b;}
        Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) { }
        Pair() {}
};
template<class T1, class T2>
T1 &Pair<T1, T2>::first()
{
    return a;
}
template<class T1, class T2>
T2 &Pair<T1, T2>::second()
{
    return b;
}

int main()
{
    using std::cout;
    using std::endl;
    using std::string;Шаблоны-члены 


    Pair<string, int> ratings[4] = 
    {
        Pair<string, int>("The Purpled Duck", 5),
        Pair<string, int>("Jaquie's Frisco AL Fresco", 4),
        Pair<string, int>("Cafe Souffle", 5),
        Pair<string, int>("Bertie's Eats", 3),
    };

    int joints = sizeof(ratings) / sizeof(Pair<string, int>);

    cout << "Rating:\t Eatery\n";
    for(int i = 0; i < joints; i++)
        cout << ratings[i].second() << ":\t"
             << ratings[i].first() << endl;
        cout << "Oops! Revised rating:\n";
        ratings[3].first() = "Bertie's Fab Eats";
        ratings[3].second() = 6;
        cout << ratings[3].second() << ":\t"
             << ratings[3].first() << endl;
             return 0;
}
/*
Обратите внимание, что в листинге 14.19 в функции main () для вызова конструкторов и в качестве аргумента для sizeof необходимо выражение 
Pair<string, int> — поскольку именем класса является Pair<string, int>, а не Pair. 
A Pair<char *,double> представляет собой имя совершенно другого класса. 
*/