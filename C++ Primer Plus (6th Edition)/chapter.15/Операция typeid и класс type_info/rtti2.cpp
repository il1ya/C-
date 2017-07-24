/* Операция typeid и класс type_info 
Операция typeid позволяет выяснить, совпадают ли типы объектов. Похожая на sizeof, она принимает аргументы двух видов: 
• имя класса; 
• выражение, которое вычисляется как тип объекта. 
Операция typeid возвращает ссылку на объект typeinfо, определенный в заголовочном файле typeinfо (ранее typeinfо.h). 
Класс typeinfo перегружает операции == и ! =, чтобы их можно было использовать для сравнения типов. 
Например, следующее выражение возвращает булевское значение true, если рд указывает на объект Magnificent, и false — в противном случае: 
typeid(Magnificent) == typeid(*pg) 
Если рд окажется нулевым указателем, программа сгенерирует исключение bad_ typeid. 
Этот тип исключения порожден от класса exception и определен в заголовочном файле typeinfo. 
Реализация класса type_inf о отличается у разных разработчиков компиляторов, но она обязательно содержит член name(), который возвращает зависящую от  
реализации строку, обычно (но не обязательно) содержащую имя класса. 
Например, приведенный ниже оператор отображает строку, определенную для класса объекта, на который указывает указатель рд: 
cout << "Now processing type " << typeid (*pg).name() << "An"; 
Код в листинге 15.18 представляет собой модифицированную версию кода из листинга 15.17: в нем используются операция typeid и функция-член name(). 
Они применяются в ситуациях, в которых операция dynamic_cast и виртуальные функции бессильны. 
Проверка typeid используется для выбора действия, которое даже не является методом класса, поэтому ее нельзя вызвать с помощью указателя на класс. 
Оператор с методом name() демонстрирует, как можно использовать этот метод для отладки. 
Обратите внимание, что в программе включается заголовочный файл typeinfo. 
Листинг 15.18. rtti2.cрр */
// rtti2.cpp — использование dynamic_cast, typeid и type_info 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using namespace std;
class Grand
{
    private:
        int hold;
    public:
        Grand(int h = 0) : hold(h){}
        virtual void Speak() const {cout << "I am a grand class!\n";}
        virtual int Value() const {return hold;}
};
class Superb : public Grand
{
    public: 
        Superb(int h = 0) : Grand(h) {}
        void Speak() const {cout << "I am a superb class!!\n";}
        virtual void Say() const
        {cout << "I hold the superb value of " << Value() << "!\n";}
};
class Magnificent : public Superb
{
    private:
        char ch;
    public:
        Magnificent(int h = 0, char cv = 'A') : Superb(h), ch(cv) {}
        void Speak() const {cout << "I am a magnificent class!!!\n";}
        void Say() const {cout << "I hold the character " << ch << " and the integer " << Value() << "!\n";}
};
Grand *GetOne();
int main()
{
    srand(time(0));
    Grand *pg;
    Superb *ps;
    for(int i = 0; i < 5; i++)
    {
        pg = GetOne();
        cout << "Now processing type " << typeid(*pg).name() << ".\n";
        pg->Speak();
        if(ps = dynamic_cast<Superb *>(pg))
            ps->Say();
        if(typeid(Magnificent) == typeid(*pg))
            cout << "Yes, you're really magnificent.\n";
    }
    return 0;
}
Grand *GetOne()  // случайным образом генерирует один из трех типов объектов 
{
    Grand *p;
    switch(rand() % 3)
    {
        case 0: p = new Grand(rand() % 100);
            break;
        case 1: p = new Superb(rand() % 100);
            break;
        case 2: p = new Magnificent(rand() % 100, 'A' + rand() % 26);
        break;
    }
    return p;
}
/*
Как и в предыдущем примере, вывод программы варьируется от запуска к запуску, поскольку для выбора типа объекта используется функция rand(). 
Кроме того,  некоторые компиляторы могут выдавать различные результаты при вызове name() —  например, 5Grand, а не Grand. 
*/