/* 3. 
Напишите программу, которая запрашивает у пользователя имя, фамилию, а затем конструирует, сохраняет и отображает третью строку, 
состоящую из фамилии пользователя, за которой следует запятая, пробел и его имя. 
Используйте массивы char и функции из заголовочного файла cstring. Пример запуска должен выглядеть так: 
Enter your first name: Flip 
Enter your last name: Fleming 
Here's the information in a single string: Fleming, Flip */
#include <iostream>
int main(void)
{
    using namespace std;
    const int Size = 20;
    char first_name[Size];
    char last_name[Size];
    cout << "Enter your first name: ";
    cin >> first_name;
    cout << "Enter your last name: ";
    cin >> last_name;
    cout << "Here's the information in a single string: " << last_name << ", " << first_name << endl;
    return 0;
}