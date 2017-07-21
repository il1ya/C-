/* В листинге 17.22 применяется перегруженная операция » для чтения содержимого строки по одному слову за раз. 
Листинг 17.22. strin.cpp */
// strin.cpp -- форматированное чтение из символьного массива 
#include <iostream>
#include <sstream>
#include <string>
int main()
{
    using namespace std;
    string lit = "It was a dark and stormy day, and "
                " the full moon glowed brilliantly. ";
    istringstream instr(lit);       // использование буфера для ввода 
    string word;
    while(instr >> word)            // чтение по одному слову 
        cout << word << endl;
        return 0;
}
/*
Класс istringstream позволяет использовать семейство методов istream для чтения данных из объекта istringstream, который может быть инициализирован объектом string. 
Предположим, что facts — это объект типа string. 
Чтобы создать объект istringstream, ассоциированный с этой строкой, можно использовать следующий код: 
    istringstream instr(facts);     // использование facts для инициализации потока 
Затем можно применить методы istream для чтения данных из instr. 
Например, если instr содержит ряд целых чисел в символьном формате, их можно прочесть следующим образом: 
    int n; 
    int sum = 0; 
    while(instr >> n) 
    sum += n; 
*/
// Короче говоря, классы istringstream и istringstream предоставляют в ваше распоряжение всю мощь методов классов istream и ostream для управления символьными данными, сохраненными в строках. 
