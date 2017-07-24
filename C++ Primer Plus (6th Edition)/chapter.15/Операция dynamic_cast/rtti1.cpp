/*
В программе определена функция-член GetOne(), которая случайным образом создает и инициализирует объект одного из этих трех классов и возвращает адрес в виде указателя типа Grand *. 
(Функция GetOne () имитирует интерактивное принятие решения пользователем.) 
В цикле этот указатель присваивается переменной pg типа Garnd *, и затем pg используется для вызова функции Speak(). 
Поскольку эта функция виртуальная, код вызывает версию Speak(), соответствующую указываемому объекту: 
for (int i = 0; i < 5; i++) 
{
    pg = GetOne(); 
    pg->Speak(); 
}
Этот подход (с указателем на Grand) нельзя в точности использовать для вызова функции Say(): она не определена для класса Grand(). 
Однако операция dynamic_cast позволяет узнать, можно ли тип рд привести к указателю на Superb. 
Это возможно, если объект имеет тип Superb или Magnificent. В любом из этих случаев можно безопасно вызвать функцию Say (): 
if (ps = dynamic_cast<Superb *>(pg)) 
        ps->Say(); 
Вспомните, что значением в выражении присваивания является значение, которое присваивается левой части. 
Поэтому значение выражения if — это ps. 
Если приведение типа выполнится успешно, ps будет ненулевым, т.е. true. 
Если приведение типа завершится неудачно (если рд указывает на объект Grand), то ps будет равно нулю, или false. 
В листинге 15.17 приведен полный код. (Кстати, некоторые компиляторы, зная, что программисты обычно используют в условии if операцию ==, могут выдать предупреждение о ненамеренном присваивании.) 
Листинг 15.17. rttil.cpp */
// rttil.cpp — использование RTTI-onepaunndynamic_cast 
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
class Grand
{
    private:
        int hold;
    public:
        Grand(int h = 0) : hold(h) {}
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
        Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
        void Speak() const {cout << "I am a magnificent class!!!\n";}
        void Say() const {cout << "I hold the character " << ch << " and the integer " << Value() << "!\n";}
};
Grand *GetOne();
int main()
{
    std::srand(std::time(0));
    Grand *pg;
    Superb *ps;
    for(int i = 0; i < 5; i++)
    {
        pg = GetOne();
        pg->Speak();
        if(ps = dynamic_cast<Superb *>(pg))
            ps->Say();
    }
    return 0;
}
Grand *GetOne()  // случайным образом генерирует один из трех типов объектов 
{
    Grand *p;
    switch(std::rand() % 3)
    {
        case 0: p = new Grand(std::rand() % 100);
            break;
        case 1: p = new Superb(std::rand() % 100);
            break;
        case 2: p = new Magnificent(std::rand() % 100, 'A' + std::rand() %26);
        break;
    }
    return p;
}
/*
Даже если ваш компилятор поддерживает RTTI, по умолчанию этот механизм может быть отключен. 
Если это так, то программа может нормально скомпилироваться, но приводить к ошибкам времени выполнения. Если вы столкнетесь с такой проблемой, обратитесь к документации. 

Программа в листинге 15.17 иллюстрирует важную мысль. По возможности следует всегда использовать виртуальные функции, a RTTI — только когда это необходимо. 
Как видите, методы Say() вызваны только для классов Superb и Magnificent. 
(Вывод будет варьироваться от запуска к запуску, т.к. для выбора типа объекта в программе применяется функция rand().) 
Операция dynamic_cast применима и к ссылкам, хотя ее использование при этом слегка отличается. 
Поскольку не существует такого значения ссылки, которое соответствует типу нулевого указателя, невозможно выбрать специальное значение, которое обозначает неудавшееся выполнение. 
Вместо этого операция dynamiccast генерирует исключение badcast, производное от класса exception и определенное в заголовочном файле typeinfо. 
Поэтому можно применить следующую операцию (rg — ссылка на объект Grand): 
#include <typeinfo> // для bad_cast 
    try { 
        Superb & rs = dynamic_cast<Superb &> (rg); 
    } 
    catch(bad_cast &){ 
}; 
*/