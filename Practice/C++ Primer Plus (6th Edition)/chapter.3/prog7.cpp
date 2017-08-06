/* 7. Напишите программу, которая запрашивает расход бензина в европейском стиле (количество литров на 100 км) и преобразует его в стиль, принятый в США — число миль на галлон. 
Обратите внимание, что кроме использования других единиц измерений, принятый в США подход (расстояние/топливо) противоположен европейскому (топливо/расстояние). 
Учтите, что 100 километров соответствуют 62.14 милям, а 1 галлон составляет 3.875 литра. 
Таким образом, 19 миль на галлон примерно равно 12.4 литров на 100 км, а 27 миль на галлон — примерно 8.7 литров на 100 км. */
#include <iostream>
const float lpg = 3.785;
const float kmpm = 1.609;
int main(void)
{
    using namespace std;
    float gas_mileage;
    cout << "Translation of fuel miles per gallon in liters per kilometer" << endl;
    cout << "Enter your fuel consumption in miles per gallon (MPG): ";
    cin >> gas_mileage;
    float MPG = 100 * lpg / (gas_mileage * kmpm);
    cout << fixed; // // выводилась только определенное число цифр после запятой
    cout.precision(1); // выводилась только определенное число цифр после запятой (сколько цифр после точки)
    cout << gas_mileage << " miles per gallon is approximately equal to " << MPG << " liters per 100 km." << endl;
    return 0;
}