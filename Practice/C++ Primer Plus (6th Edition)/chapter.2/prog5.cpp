/* Напишите программу, в которой функция main() вызывает определяемую пользователем функцию, принимающую в качестве аргумента значение  
температуры по Цельсию и возвращающую эквивалентное значение температуры по Фаренгейту. Программа должна выдать запрос на ввод значения по Цельсию и отобразить следующий результат: 
Please enter a Celsius value: 20 
20 degrees Celsius is 68 degrees Fahrenheit. 
Вот формула для этого преобразования: Температура в градусах по Фаренгейту = 1,8 * Температура в градусах по Цельсию + 32 */
#include <iostream>
int main(void)
{
    using namespace std;
    int value;
    // int value1;
    cout << "Please enter a Celsius value: ";
    cin >> value;
    cout << value << " degrees Celsius is " << (1,8 * value + 32) << " degrees Fahrenheit." << endl;
    // value1 = ((1,8 * value) + 32);
    return 0; 
}