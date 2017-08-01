/*1. Напишите программу, которая многократно запрашивает у пользователя пару чисел до тех пор, пока хотя бы одно из этой пары не будет равно 0. 
С  каждой парой программа должна использовать функцию для вычисления среднего гармонического этих чисел. 
Функция должна возвращать ответ main() для отображения результата. 
Среднее гармоническое чисел — это инверсия среднего значения их инверсий; она вычисляется следующим образом: среднее гармоническое = 2.0 * х * у / (х + у) */
#include <iostream>
using namespace std;
int array(int enter1, int enter2);
int main(void)
{
    int enter1, enter2;
    //cout << "Enter one: ";
    //cin >> enter1;
    //cout << "Enter two: ";
    //cin >> enter2;
    cout << "Enter: ";
    while(cin >> enter1 >> enter2)
    {
        if(enter1 == 0 || enter2 == 0)
        break;
        cout << array(enter1, enter2) << endl;
        cout << "Enter: ";
    }
    //int name = array(enter1, enter2);
    //cout << name << endl;
    cout << "See you!" << endl;
    return 0;
}
int array(int enter1, int enter2)
{
    int sum;
    sum = 2.0 * enter1 * enter2 / (enter1 + enter2);
    return sum;
}