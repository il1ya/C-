// Листинг 4.22. delete.срр 
// delete.срр — использование операции delete 
#include <iostream>
#include <cstring>   // или string.h 
using namespace std;
char *getname(void); // прототип функции 
int main(void)
{
    char *name;         // создание указателя, но без хранилища 
    name = getname();   // присваивание name адреса строки 
    cout << name << " at " << (int *) name << "\n";
    delete [] name;     // освобождение памяти 
    name = getname();   // повторное использование освобожденной памяти 
    cout << name << " at " << (int *) name << "\n";
    delete [] name;     // снова освобождение памяти 
    return 0;
}
char *getname()             // возвращает указатель на новую строку
{
    char temp[80]; // временное хранилище 
    cout << "Enter last name:"; // ввод фамилии 
    cin >> temp;
    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp); // копирование строки в меньшее пространство 
    return pn; // по завершении функции temp теряется 
}