/* 4. Напишите программу, которая запрашивает количество секунд в виде целого значения (используйте тип long или long long, если последний доступен) и 
затем отображает эквивалентное значение в сутках, часах, минутах и секундах. 
Для представления количества часов в сутках, количества минут в часе и количества секунд в минуте используйте символические константы. Результат выполнения программы должен выглядеть следующим образом: 
Enter the number of seconds: 31600000 
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds */

#include <iostream>
const long long In_one_day = 86400;
const long long seconds = 3600;
const long long seconds_in_minutes = 001667;
int main(void)
{
    using namespace std;
    long long a_second_integer;
    cout << "Enter the number of seconds:  \b";
    cin >> a_second_integer;
    long long decides = a_second_integer / In_one_day;
    long long decides_seconds = a_second_integer / seconds;
    long long decides_seconds_in_minutes = a_second_integer / seconds_in_minutes;
    cout << a_second_integer << " seconds = " << decides << " days, " << decides_seconds << " hours, " << decides_seconds_in_minutes << " minutes, " << a_second_integer << " seconds" << endl;
    return 0;
}