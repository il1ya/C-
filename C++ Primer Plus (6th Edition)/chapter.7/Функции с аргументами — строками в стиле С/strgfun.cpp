/* Предположим, что требуется передать строку функции в виде аргумента. Доступны три варианта представления строки: 
• массив char; 
• константная строка в двойных кавычках (также называемая строковым литералом), 
• указатель на char, установлены в адрес начала строки. 
Все три варианта, однако, являются типом указателя на char (или, короче, тип char *), поэтому все три можно использовать в качестве аргументов функций, обрабатывающих строки: 
char ghost[15] = "galloping"; 
char * str = "galumphing"; 
int nl = strlen (ghost);        // ghost - это &ghost[0] 
int n2 = strlen (str);          // указатель на char 
int n3 = strlen("gamboling");   // адрес строки 
Неформально вы можете сказать, что передаете строку как аргумент, но на самом деле вы передаете адрес ее первого символа. 
Это подразумевает, что прототип строковой функции должен использовать char * как тип формального параметра, представляющего строку. 
Одно важное отличие между строкой в стиле С и обычным массивом состоит в том, что строка имеет встроенный ограничивающий нулевой символ. 
(Вспомните, что массив char, который содержит символы, но не содержит нулевой символ — это просто массив, а не строка.) 
Это значит, что вы не должны передавать размер строки в качестве аргумента. 
Вместо этого функция может использовать цикл для поочередного чтения каждого символа строки до тех пор, пока не будет достигнут ограничивающий нулевой символ. 
Код в листинге 7.9 иллюстрирует этот подход для функции, выполняющей подсчет количества появлений определенного символа в строке. 
Поскольку программа не нуждается в обработке отрицательных значений, в качестве типа счетчика применяется unsigned int. 
Листинг 7.9. strgfun.cpp */
// strgfun.cpp -- функция со строковым аргументом 

#include <iostream>
unsigned int c_in_str(const char str[], char ch);
int main(void)
{
    using namespace std;
    char mmm[15] = "minimum";                            // строка в массиве 
    // Некоторые системы требуют предварить char словом static, 
    // чтобы разрешить инициализацию массива 
    char *wail = "ululate";                              // wail указывает на строку 
    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');
    cout << ms << " m characters in " << mmm << endl;    // вывод количества символов m 
    cout << us << " u characters in " << wail << endl;   // вывод количества символов и 
    return 0;
}

// Эта функция подсчитывает количество символов ch в строке str 
unsigned int c_in_str(const char *str, char ch)
{
    unsigned int count = 0;
    while(*str)                     // завершение, когда *str равно '\0' 
    {
        if(*str == ch)
            count++;
            str++;                  // перемещение указателя на следующий символ 
    }
    return count;
}

/*
Замечания по программе 
Поскольку функция c_int_str() в листинге 7.9 не должна изменять исходную строку, она использует модификатор const в объявлении формального параметра str. 
После этого, если вы ошибочно позволите функции изменить часть строки,  компилятор перехватит эту ошибку.
Разумеется, для объявления str в заголовке функции можно применять нотацию массивов: 
unsigned int c_in_str(const char str[], char ch) // также нормально 
Однако использование нотации указателей напоминает о том, что аргумент не должен быть именем массива, а "какой-то другой формой указателя. 
Сама функция демонстрирует стандартный способ обработки символов в строке: 
while (*str) 
{ 
    операторы 
    str++; 
} 
Изначально str указывает на первый символ строки, поэтому *str представляет сам первый символ. 
Например, непосредственно после первого вызова функции *str имеет значение m — первый символ в minimum. 
До тех пор, пока символ не является нулевым (\0), *str не равно нулю и цикл продолжается. 
В конце каждого шага цикла выражение str++ увеличивает указатель на 1 байт, так что он указывает на  следующий символ в строке. 
В конечном итоге str указывает на завершающий нулевой символ, что делает *str равным нулю, и цикл прекращается. 
*/