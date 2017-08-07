/* 4. Напишите программу, которая предлагает пользователю ввести свой возраст. 
Затем программа должна отобразить возраст в месяцах: 
Enter your age: 29 
Your age in months is 348. */
#include <iostream>
int main(void)
{
    using namespace std;
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age in months is " << age * 12 << endl;
    return 0;
}
