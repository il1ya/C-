/* Как вы уже видели, можно использовать сіп с операцией >> для чтения объекта string и cout с операцией << — для отображения объекта string, причем с тем же синтаксисом, что и в случае строк в стиле С. 
Однако чтение за один раз целой строки с пробелами вместо отдельного слова требует другого синтаксиса. В листинге 4.10 демонстрируется это отличие. */
// Листинг 4.10. strtype4 .срр 
// strtype4.cpp -- ввод строки с пробелами 
#include <iostream>
#include <string>  // обеспечение доступа к классу string 
#include <cstring> // библиотека обработки строк в стиле С 
int main(void)
{
    using namespace std;
    char charr[20];
    string str;

    // Длина строки в charr перед вводом 
    cout << "Length of string in charr before input: " << strlen(charr) << endl;
    // Длина строки в str перед вводом 
    cout << "Length of string in str before input: " << str.size() << endl;
    cout << "Enter a line of text:\n"; // ввод строки текста 
    cin.getline(charr, 20);  // указание максимальной длины 
    cout << "You entered: " << charr << endl;
    cout << "enter another line of text:\n"; // ввод другой строки текста 
    getline(cin, str); // теперь сіп - аргумент; спецификатор длины отсутствует 
    cout << "You entered: " << str << endl;
    // Длина строки в charr после ввода 
    cout << "Length of string in charr after input: " << strlen(charr) << endl;
    // Длина строки в str после ввода 
    cout << "Length of string in str after input: " << str.size() << endl;
    return 0;
}