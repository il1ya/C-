/* Напишите программу, которая выдает запрос на ввод значений часов и минут. 
Функция main() должна передать эти два значения функции, имеющей тип void, которая отобразит эти два значения в следующем виде: 
Enter the number of hours: 9 
Enter the number of minutes: 28 
Time: 9:28 */
#include <iostream>
using namespace std;

void function(int, int);

int main(void)
{
    int hours;
    int minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    function(hours, minutes);
    return 0;
}

void function(int hours, int minutes)
{
    cout << "Time: " << hours << ":" << minutes << endl;
}