/* Как обычно, необходимо освободить память, ранее управляемую указателем str, и выделить достаточный объем памяти для новой строки. 
В листинге 12.4 показано пересмотренное объявление класса. В дополнение к уже упомянутым изменениям, в нем определяется константа CINLIM, которая используется в реализации operator>> (). 
Листинг 12.4. stringl.h */
// stringl.h — исправленное и расширенное объявление строкового класса 
#include <iostream> 
using std::ostream;
using std::istream;

class String
{
     private:
        char *str;                    // указатель на строку 
        int   len;                    // длина строки 
        static int num_strings;
        static const int CINLIM = 80; // предел ввода для сіп 
     public:
        // Конструкторы и другие методы 
        String(const char *s);   // конструктор 
        String();                // конструктор по умолчанию
        String(const String &);     // конструктор копирования
        ~String();               // деструктор
        int length () const {return len;}

        // Методы перегруженных операций 
        String & operator = (const String &);
        String & operator = (const char *);
        char & operator[] (int i);
        const char & operator[](int i) const;

        // Дружественные функции перегруженных операций 
        friend bool operator <(const String &st, const String &st2); 
        friend bool operator >(const String &st1, const String &st2); 
        friend bool operator ==(const String &st, const String &st2); 
        friend ostream & operator << (ostream & os, const String & st); 
        friend istream & operator >> (istream & is, String & st);
        // Статическая функция 
        static int HowMany();
};