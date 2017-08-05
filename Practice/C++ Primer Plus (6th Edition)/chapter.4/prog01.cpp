/* 1. 
Напишите программу C++, которая запрашивает и отображает информацию, как показано в следующем примере вывода: 
What is your first name? Betty Sue 
What is your last name? Yewe 
What letter grade do you deserve? В 
What is your age? 22 
Name: Yewe, Betty Sue 
Grade: С 
Age: 22 
Обратите внимание, что программа должна принимать имена, состоящие из более чем одного слова. 
Кроме того, программа должна уменьшать значение grade на одну градацию — т.е. на одну букву выше. 
Предполагается, что пользователь может ввести А, В или С, поэтому вам не нужно беспокоиться о пропуске между D и F. */

#include <iostream>
const int Size = 25;
int main(void)
{
    using namespace std;
    char first_name[Size];
    char last_name[Size]; 
    char grade[Size];
    int age;
    cout << "What is your first name? ";
    cin.getline(first_name, Size);
    cout << "What is your last name? ";
    cin >> last_name;
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    char gradee =  *grade + 1;
    cout << "What is your age? ";
    cin >> age;
    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << "Grade: " << gradee << endl;
    cout << "Age: " << age << endl;
    return 0;
}