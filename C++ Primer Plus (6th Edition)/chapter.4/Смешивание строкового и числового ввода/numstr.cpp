// Смешивание числового и строкового ввода может приводить к проблемам.Рассмотрим пример простой программы в листинге 4.6.Листинг 4.6. numstr.срр 
// numstr.срр -- строковый ввод после числового 
#include <iostream>
int main(void)
{
    using namespace std;
    cout << "What year was your house built?\n";  // ввод года постройки дома 
    int year;
    cin >> year;
    cout << "What is its street address?\n";  // ввод адреса 
    char address[80];
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;  // вывод года постройки 
    cout << "Address: " << address << endl;  // вывод адреса 
    cout << "Done!\n";
    return 0;
}