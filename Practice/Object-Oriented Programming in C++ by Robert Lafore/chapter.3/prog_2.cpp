/**2. Напишите программу, предлагающую пользователю осуществить перевод температуры из шкалы Цельсия в шкалу Фаренгейта или наоборот, а затем осуществите преобразование. 
Используйте в программе переменные вещественного типа. 
Взаимодействие программы с пользователем может выглядеть следующим образом:
Нажмите 1 для перевода шкалы Цельсия в шкалу Фаренгейта, 
2 для перевода шкалы Фаренгейта в шкалу Цельсия: 2 
Введите температуру по Фаренгейту: 70 
Значение по Цельсию: 21.111111
Для перевода температуры из шкалы Фаренгейта в шкалу Цельсия нужно от исходного числа отнять 32 и умножить результат на 5/9
Для перевода температуры из шкалы Цельсия в шкалу Фаренгейта нужно умножить исходное число на 9/5 и прибавить 32.
*/
#include <iostream>
int main()
{
    double celsi, fahren, enter_1, enter_2;
    std::cout << "Press 1 to convert the Celsius scale to the Fahrenheit scale,\n2 for converting the Fahrenheit scale to a Celsius scale: ";
    while(std::cin >> enter_1)
    {
        if(enter_1 == 1)
        {
            std::cout << "Enter the temperature by Celsius: ";
            std::cin >> enter_2;
            celsi = enter_2 * (9.0 / 5.0) + 32.0;
            std::cout << celsi << std::endl;
        }
        else if(enter_1 == 2)
        {
            std::cout << "Enter the temperature by Fahrenheit: ";
            std::cin >> enter_2;
            fahren = (enter_2 - 32.0) * (5.0 / 9.0);
            std::cout << fahren << std::endl;
        }
        std::cout << "Press 1 to convert the Celsius scale to the Fahrenheit scale,\n2 for converting the Fahrenheit scale to a Celsius scale: ";
    }
    return 0;
}