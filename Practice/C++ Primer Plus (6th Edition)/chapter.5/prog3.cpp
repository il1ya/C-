/* Напишите программу, которая приглашает пользователя вводить числа. 
После каждого введенного значения программа должна выдавать накопленную сумму введенных значений. Программа должна завершаться при вводе 0. */
#include <iostream>
int main(void)
{
    using namespace std;
    int number, sum;
    for(int i = 0; i < number; )
    {
            cout << "Enter the number: ";
            cin >> number;
            sum += number;
            cout << "accumulated value: " << number << endl;
    }
    return 0;
}