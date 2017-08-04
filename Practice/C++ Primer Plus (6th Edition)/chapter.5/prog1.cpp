/* 
1.
Напишите программу, запрашивающую у пользователя ввод двух целых чисел. 
Затем программа должна вычислить и выдать сумму всех целых чисел, лежащих между этими двумя целыми. 
Предполагается, что меньшее значение вводится первым. 
Например, если пользователь ввел 2 и 9, программа должна сообщить, что сумма всех целых чисел от 2 до 9 равна 44. 
*/

#include <iostream>
int main(void)
{
    using namespace std;
    int first, second, general;
    cout << "Enter first least number: ";
    cin >> first;
    cout << "Enter second major number: ";
    cin >> second;
    general = second - first;
    int i, j = 0;
    for(i = 0; i <= general; i++)
    {
        j += first + i;
    }
    cout << "The sum of all integers of " << first << " to " << second << " = " << j << endl;
    return 0;
}