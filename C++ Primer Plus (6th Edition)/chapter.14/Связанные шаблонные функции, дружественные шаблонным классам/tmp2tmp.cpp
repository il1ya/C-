/* Связанные шаблонные функции, дружественные шаблонным классам 

Рассмотренный выше пример можно изменить, сделав дружественные функции также шаблонами. В частности, можно создать связанных друзей шаблона — чтобы каждая специализация класса получала соответствующую специализацию друга. 
Этот прием немного сложнее, чем в случае нешаблонных друзей, и состоит из трех шагов. 
На первом шаге перед определением класса необходимо объявить каждую шаблонную функцию: 
template <typename T> void counts(); 
template <typename T> void report(T &); 
Затем внутри функции нужно снова объявить шаблоны в качестве друзей. Вот операторы, которые объявляют специализации, основанные на типе параметра шаблонного класса: 
template <typename TT> 
class HasFriendT 
{ 
    friend void counts<TT>(); 
    friend void reporto(HasFriendT<TT> &); 
}; 
Угловые скобки о в объявлениях означают специализации шаблона. В случае report() скобки о могут быть пустыми, т.к. аргумент типа шаблона можно получить из аргумента функции 
HasFriendT<TT> 
Но возможен и такой вариант: 
report<HasFriendT<TT> >(HasFriendT<TT> &) 
Функция counts 0 не имеет параметров, поэтому для определения ее специализации нужно задействовать аргумент шаблона (<ТТ>). 
Обратите внимание, что ТТ — тип параметра для класса HasFriendT. Чтобы понять эти объявления, лучше представить, чем они станут при объявлении объекта конкретной специализации. 
Предположим, например, что объявлен такой объект: 
HasFriendT<int> squack; 
Компилятор подставит вместо ТТ тип int и сгенерирует следующее определение класса: 
class HasFriendT<int> 
{ 
    friend void counts<int>(); 
    friend void reporto(HasFriendT<int> &);
}
Одна специализация основана на типе ТТ, который преобразуется в int, а другая — на HasFriendT<TT>, который преобразуется в HasFriendT<int>. 
Таким образом, специализации шаблона counts<int> () и report<HasFriendT<int> > () объявлены как друзья класса HasFriendT<int>. 
Третье требование, которому должна удовлетворять программа — она должна содержать определения шаблонов для друзей. 
Все эти три аспекта демонстрируются в листинге 14.23. Обратите внимание, что в листинге 14.22 одна функция counts() является другом для всех классов HasFriend. 
А в листинге 14.23 имеются две функции counts (), но лишь одна из них является другом каждому созданному типу класса. 
Поскольку вызовы функции counts () не содержат параметров, из которых компилятор мог бы вывести требуемую специализацию, в этих вызовах используются формы count<int>() и count<double>(). 
Но в вызовах reports() компилятор может определять специализацию на основе типа аргумента. С тем же результатом можно использовать и форму <>: 
report<HasFriendT<int> >(hfi2); // эквивалентно report(hfi2); 
Листинг 14.23. tmp2tmp.cpp */
// tmp2tmp.cpp -- шаблонные друзья для шаблонного класса 
#include <iostream>
using std::cout;
using std::endl;

// Прототипы шаблонов 
template <typename T> void counts();
template <typename T> void report(T &);

// Шаблонный класс 
template <typename TT>
class HasFriendT
{
    private:
        TT item;
        static int ct;
    public:
        HasFriendT(const TT &i) : item(i) {ct++;}
        ~HasFriendT() { ct--;}
        friend void counts<TT>();
        friend void report<>(HasFriendT<TT> &);
};

template <typename T>
int HasFriendT<T>::ct = 0;

// Определения дружественных функций для шаблона 
template <typename T>
void counts()
{
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";     // размер шаблона 
    cout << "template counts(): " << HasFriendT<T>::ct << endl;     // counts() из шаблона 
}
template <typename T>
void report(T &hf)
{
    cout << hf.item << endl;
}

int main()
{
    counts<int>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    report(hfi1);       // генерирует report(HasFriendT<int> &) 
    report(hfi2);       // генерирует report(HasFriendT<int> &) 
    report(hfdb);       // генерирует report(HasFriendT<double> &) 

    cout << "counts<int>() output:\n";      // вывод из counts<int> () 
    counts<int>();
    cout << "counts<double>() output:\n";   // вывод из counts<double> () 
    counts<double>();
    return 0;
}

// Как видите, counts<double> сообщает размер шаблона, отличный от выводимого counts<int> — т.е. каждому типу Т соответствует собственная дружественная функция count(). 
