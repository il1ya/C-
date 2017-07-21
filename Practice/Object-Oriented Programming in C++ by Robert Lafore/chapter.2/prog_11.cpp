/*11. По умолчанию форматирование вывода производится по правому краю поля. 
Можно изменить форматирование текста на левостороннее путем использования манипулятора setiosflags(ios::left) 
(не беспокойтесь о смысле новой формы записи, встретившейся в манипуляторе). 
Используйте этот манипулятор вместе с setw() для того, чтобы произвести следующий вывод:
Фамилия     Имя         Адрес               Город
-------------------------------------------------------------------
Петров      Василий     Кленовая 16         Санкт-Петербург 
Иванов      Сергей      Осиновая 3          Находка
Сидоров     Иван        Березовая 21        Калининград
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << "Surname" << setw(16) << "First name" << setw(12) << "Address" << setw(12) << "City" << endl;
    cout << setw(47) << setfill('.') << "." << endl;
    cout << setfill(' ') << "Skvortsov" << setw(9) << "Illya" << setw(23) << "Jan Cecota 36" << setw(7) << "Minsk" << endl;
    cout << setfill(' ') << "Skvortsov" << setw(9) << "Illya" << setw(13) << "Red" << setw(18) << "Moskov" << endl;
    cout << setfill(' ') << "Skvortsov" << setw(9) << "Illya" << setw(19) << "Ykabasano" << setw(11) << "Tokyo" << endl;
    return 0;
}