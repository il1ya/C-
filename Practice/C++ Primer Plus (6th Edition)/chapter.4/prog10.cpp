/* 10. 
Напишите программу, которая приглашает пользователя ввести три результата забега на 40 ярдов (или 40 метров, если желаете) и затем отображает эти значения и их среднее. 
Для хранения данных применяйте объект array. (Если объект array не доступен, воспользуйтесь встроенным массивом.) */
#include <iostream>
#include <array>
using namespace std;
int main(void)
{
    array<float, 3> ar;
    cout << "Enter 3 result of the race." << endl;
    cout << "First result: ";
    cin >> ar[0];
    cout << "Second result: ";
    cin >> ar[1];
    cout << "Third result: ";
    cin >> ar[2];
    cout << "The result of the data entered by you";
    ar[3] = (ar[0] + ar[1] + ar[2]) / 3.0;
    cout << "Result: " << ar[2] << endl;
    return 0;
}