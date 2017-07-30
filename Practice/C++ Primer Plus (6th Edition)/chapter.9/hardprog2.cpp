// 2. Модифицируйте код в листинге 9.9, заменив символьный массив объектом string. 
// Программа больше не должна проверять, умещается ли вводимая строка, и для проверки ввода пустой строки может сравнивать вводимую строку со значением "". 
// Листинг 9.9. static.срр
// static.срр — использование статической локальной переменной 
#include <iostream>
// Константы 
const int ArSize = 10;
// Прототип функции 
void strcount(const char *str);
int main()
{
    using namespace std;
    char input[ArSize];
    char next;
    cout << "Enter a line: \n";
    cin.get(input, ArSize);
    while(cin)
    {
        cin.get(next);
        while(next != '\n')     // строка не помещается; 
            cin.get(next);      // избавиться от остатка 
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const char *str)
{
    using namespace std;
    static int total = 0;   // статическая локальная переменная 
    int count = 0;          // автоматическая локальная переменная 
    cout << "\"" << str << "\" contains ";
    while(*str++)           // переход к концу строки 
        count++;
    total += count;
    cout << count << "characters\n";
    cout << total << " characters total\n";
}