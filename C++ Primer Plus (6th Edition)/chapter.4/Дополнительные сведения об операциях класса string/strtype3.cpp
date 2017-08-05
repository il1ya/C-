/* Еще до появления в C++ класса string программисты нуждались в таких действиях, как присваивание строк. Для строк в стиле С использовались функции из 
стандартной библиотеки С. Эти функции поддерживаются заголовочным файлом cstring (бывший string.h). Например, вы можете применять функцию strcpy() 
для копирования строки в символьный массив, а функцию strcat () — для добавления строки к символьному массиву: 
strcpy(charrl, charr2); // копировать charr2 в charrl 
strcat(charrl, charr2); // добавить содержимое charr2 к charl 
В листинге 4.9 сравниваются подходы с объектами string и символьными массивами. 
Листинг 4,9. strtype3.срр */
// strtype3.cpp — дополнительные средства класса string 
#include <iostream>
#include <string>  // обеспечение доступа к классу string 
#include <cstring> // библиотека обработки строк в стиле 
int main(void)
{
    using namespace std;
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";
    // Присваивание объектов string и символьных массивов 
    str1 = str2;  // копирование str2 в str2 
    strcpy(charr1, charr2); // копирование charr2 в charrl 
    // Добавление объектов string и символьных массивов 
    str1 += "paste"; // добавление "paste" в конец strl 
    strcat(charr1, "juice"); // добавление " juice" в конец charrl 
    // Определение длины объекта string и строки в стиле С 
    int len1 = str1.size(); // получение длины strl 
    int len2 = strlen(charr1); // получение длины charrl 
    cout << "The string " << str1 << " contains " << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains " << len2 << " characters.\n";
    return 0;
}