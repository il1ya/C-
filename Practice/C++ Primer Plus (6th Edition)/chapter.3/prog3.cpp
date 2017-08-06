/* 3. Напишите программу, которая запрашивает широту в градусах, минутах и секундах, после чего отображает широту в десятичном формате. 
В одной минуте 60 угловых секунд, а в одном градусе 60 угловых минут; представьте эти значения с помощью символических констант. 
Для каждого вводимого значения должна использоваться отдельная переменная. Результат выполнения программы должен выглядеть следующим образом: 
Enter a latitude in degrees, minutes, and seconds: 
First, enter the degrees: 37 
Next, enter the minutes of arc: 51 
Finally, enter the seconds of arc: 19 
37 degrees, 51 minutes, 19 seconds = 37.8553 degrees */
// Десятичные градусы = Град + Мин/60 + Сек/60
#include <iostream>
    const int arcseconds = 60;
    const int arcminutes = 60;
int main(void)
{
    using namespace std;
    int degrees, minutes, seconds;
    cout << "Enter a latitude in degrees, minutes, and seconds:\n";
    cout << "First, enter the degrees:   \b\b";
    cin >> degrees;
    cout << "Next, enter the minutes of arc:   \b\b";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc:   \b\b";
    cin >> seconds;
    double (maini) = double(degrees) + double(minutes) / arcseconds + double(seconds) / arcminutes;
    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << maini << " degrees" << endl;
    return 0;
}