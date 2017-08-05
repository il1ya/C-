/* 4. 
Напишите программу, которая приглашает пользователя ввести его имя и фамилию, а затем построит, сохранит и отобразит третью строку, состоящую 
из фамилии, за которой следует запятая, пробел и имя. 
Используйте объекты string и методы из заголовочного файла string. Пример запуска должен выглядеть так: 
Enter your first name: Flip 
Enter your last name: Fleming 
Here's the information in a single string: Fleming, Flip */ 
#include <iostream>
#include <string>
int main(void)
{
    using namespace std;
    string first_name;
    string last_name;
    cout << "Enter your first name: ";
    cin >> first_name;
    cout << "Enter your last name: ";
    cin >> last_name;
    cout << "Here's the information in a single string: " << last_name << ", " << first_name << endl;
    return 0;
}