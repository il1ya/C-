/* HasFriend<int> hf; 
Компилятор заменит параметр шаблона Т на int, и объявление друга примет  
следующий вид: 
class HasFriend<int> 
{ 
friend void report(HasFriend<int> &); // связанный друг шаблона 
}; 
To есть функция report() с параметром HasFriend<int> становится дружественной для класса HasFriend<int>. 
Аналогично, функция report() с параметром HasFriend<double> будет перегруженной версией report(), которая является дружественной ДЛЯ класса HasFriend<double>. 
Обратите внимание, что report() — нешаблонная функция: шаблоном является лишь ее параметр. 
Это означает, что для использования друзей необходимо определить явные специализации: 
void report(HasFriend<short> &){...};   // явная специализация для short 
void report(HasFriend<int> &){...};     // явная специализация для int 
Эти моменты демонстрируются в листинге 14.22. В шаблоне HasFriend имеется статический член ct. 
Это означает, что любая конкретная специализация класса содержит собственный статический член. 
Метод counts(), являющийся другом для всех специализаций HasFriend, выводит значения ct из двух конкретных специализаций — HasFriend<int> и HasFriend<double>. 
В программе имеются также две функции reports(), каждая из которых является дружественной для одной конкретной специализации HasFriend. 
Листинг 14.22. frnd2tmp.cpp */
// frnd2tmp.cpp — шаблонный класс с нешаблонными друзьями 

#include <iostream>

using std::cout;
using std::endl;

template <typename T>

class HasFriend
{
    private:
        T item;
        static int ct;
    public:
        HasFriend(const T&i) : item(i) { ct++; }
        ~HasFriend() {ct--;}
        friend void counts();
        friend void reports(HasFriend<T> &);  // template parameter 
};
// Каждая специализация имеет собственный статический член данных 
template <typename T>
int HasFriend<T>::ct = 0;

// Нешаблонный друг для всех классов HasFriend<T> 
void counts()
{
    cout << "int count: "    << HasFriend<int>::ct << "; ";
    cout << "double count: " << HasFriend<double>::ct << endl;
}
// Нешаблонный друг для класса HasFriend<int> 
void reports(HasFriend<int> &hf)
{
    cout << "HasFriend<int>: " << hf.item << endl;
}

// Нешаблонный друг для класса HasFriend<double> 
void reports(HasFriend<double> &hf)
{
    cout << "HasFriend<double>: " << hf.item << endl;
}
int main()
{
    cout << "No objects declared: ";    // объекты пока не объявлены 
    counts();

    HasFriend<int> hfi1(10);
    cout << "After hfil declared: ";    // после объявления hfi1 
    counts();

    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";    // после объявления hfi2 
    counts();

    HasFriend<double> hfi3(10.5);
    cout << "After hfi3 declared: ";    // после объявления hfi3 
    counts();

    reports(hfi1);
    reports(hfi2);
    reports(hfi3);
    return 0;
}