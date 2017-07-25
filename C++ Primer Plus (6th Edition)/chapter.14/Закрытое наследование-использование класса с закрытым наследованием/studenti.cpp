/* Доступ к друзьям базового класса 
Явное указание имени функции с именем ее класса не работает для дружественных функций, т.к. дружественная функция не принадлежит этому классу. 
Но для корректного вызова функций можно использовать явное приведение типа к базовому классу. 
В принципе, это та же техника, что и при доступе к объектам базового класса в методах класса. 
Но в случае с друзьями доступно имя объекта Student, поэтому вместо *this в коде используется имя объекта. 
Например, рассмотрим следующее определение дружественной функции: 
ostream & operator<<(ostream & os, const Student & stu) 
{ 
    os « "Scores for " « (const string &) stu « " :\n"; 
}
Если platо — объект типа Student, то показанный ниже оператор вызывает эту функцию, где stu — ссылка на plat о, a os — ссылка на cout: 
cout << plato; 
Рассмотрим следующую строку кода: 
os « "Scores for " « (const string &) stu « ":\n"; 
Приведение типа явно преобразует stu в ссылку на объект типа string, а этот тип вызывает функцию operator« (ostream &, const string &). 
Ссылка stu не преобразуется автоматически в ссылку на string, поскольку при закрытом наследовании ссылке или указателю на базовый класс нельзя присвоить ссылку или указатель на  
производный класс без явного приведения типа. 
Однако даже при открытом наследовании нужно иметь явные приведения типов. 
Одна из причин состоит в том, что без приведения код вроде показанного ниже соответствует прототипу дружественной функции, что приводит к рекурсивному вызову: 
os << stu; 
Существует еще одна причина: поскольку класс использует множественное наследование, компилятор не может определить, 
в какой базовый класс выполнять преобразование, т.к. оба базовых класса поддерживают функцию operator<<(). 
В листинге 14.5 показаны все методы класса Student, за исключением приведенных непосредственно в объявлении класса. 
Листинг 14.5. studenti.срр */
// studenti.срр — класс Student, использующий закрытое наследование 
#include "studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// Открытые методы 
double Student::Average() const
{
    if(ArrayDb::size() > 0)
        return ArrayDb::sum() / ArrayDb::size();
        else
            return 0;
}
const string &Student::Name() const
{
    return (const string &) *this;
}
double &Student::operator[] (int i)
{
    return ArrayDb::operator[](i); // использует ArrayDb::operator[]() 
}
double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}

// Закрытый метод 
ostream &Student::arr_out(ostream &os) const
{
    int i;
    int lim = ArrayDb::size();
    if(lim > 0)
    {
        for(i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if(i % 5 == 4)
                os << endl;
        }
        if(i % 5 != 0)
            os << endl;
    }
    else
        os << "empty array ";
        return os;
}

// Друзья 
// Использует версию operator»() из класса string 
istream &operator>>(istream &is, Student &stu)
{
    is >>(string &)stu;
    return is;
}
// Использует друга string - getline(ostream &, const string &) 
istream &getline(istream &is, Student &stu)
{
    getline(is, (string &)stu);
    return is;
}
// Использует версию operator«() из класса string 
ostream &operator<<(ostream &os, const Student &stu)
{
    os << "Scores for " << (const string &)stu << ":\n";
    stu.arr_out(os); // использование закрытого метода для scores 
    return os; 
}

// В этом примере также задействован код string и valarray, и поэтому дополнительное кодирование сведено к минимуму — за исключением закрытого вспомогательного метода. 
