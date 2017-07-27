// В листинге 12.5 представлены пересмотренные определения методов. 
// Листинг 12.5. stringl.срр 
// stringl.срр — методы класса String 
#include <cstring>      // в некоторых случаях - string.h 
#include <cctype>
#include "string1.h"    // включение <iostream> 
using std::cin;
using std::cout;

// Инициализация статического члена класса 
int String::num_strings = 0;

// Статический метод 
int String::HowMany()
{
    return num_strings;
}

// Методы класса 
String::String(const char *s)   // создание String из С-строки 
{
    len = std::strlen(s);       // установка размера 
    str = new char[len + 1];    // выделение памяти 
    std::strcpy(str, s);        // инициализация 
    num_strings++;              // корректировка счетчика объектов 
}

String::String()                // конструктор по умолчанию 
{ 
    len = 4; 
    str = new char [1];
    str[0] = '\0';              // строка по умолчанию 
    num_strings++; 
}

String::String(const String &st)
{
    num_strings++;              // обработка обновления статического члена 
    len = st.len;               // длина та же 
    str = new char[len + 1];    // выделение памяти 
    std::strcpy(str, st.str);   // копирование строки в новое место 
}

String::~String()               // необходимый деструктор 
{
    --num_strings;              // требуется 
    delete [] str;              // требуется 
}

// Методы перегруженных операций 
// Присваивание объекта String объекту String 
String & String::operator=(const String & st) 
{ 
    if (this == &st) 
    return *this; 
    delete [] str; 
    len = st.len; 
    str = new char [len + 1]; 
    std::strcpy(str, st.str); 
    return *this; 
}
// Присваивание С-строки объекту String 
String & String::operator=(const char * s) 
{ 
    delete [] str; 
    len = std::strlen(s); 
    str = new char[len + 1]; 
    std::strcpy(str, s); 
    return *this; 
} 
// Доступ для чтения и записи отдельных символов в неконстантном объекте String 
char & String::operator[](int i)
{
    return str[i];
}
// Доступ только для чтения отдельных символов в константном объекте String 
const char &String::operator[](int i) const
{
    return str[i];
}
// Дружественные функции перегруженных операций 
bool operator<(const String &st1, const String &st2)
{
    return(std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String &st1, const String &st2)
{
    return st2.str < st1.str;
}
bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}
// Простой вывод String 
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}
// Простой вывод String 
istream & operator>>(istream & is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
        st = temp;
    while(is && is.get() != '\n')
        continue;
        return is;
}
/*
Перегруженная операция >> обеспечивает простой способ ввода строки с клавиатуры в объект String. 
Она принимает введенную строку длиной String::CINLIM или менее символов и отбрасывает все символы сверх этого предела. 
Учтите, что значение объекта istream в условии if равно false, если ввод данных по каким-то причинам аварийно прерывается — например, появление условия конца файла или, в 
случае get (char *, int), чтение пустой строки. 
*/

