/* 6. Напишите программу, которая запрашивает количество миль, пройденных автомобилем, и количество галлонов израсходованного бензина, а затем сообщает значение количества миль на галлон. 
Или, если хотите, программа может запрашивать расстояние в километрах, а объем бензина в литрах, и выдавать результат в виде количества литров на 100 километров. */
/*  GALLON 3.785
    MILE 1.609
    MPG 236 
*/

#include <iostream>
//const int mpg = 236;
//const float gallon = 3.785;
int main(void)
{
    using namespace std;
    float km, liters;
    cout << "Enter the number of distance in kilometers by car: ";
    cin >> km;
    cout << "And the volume of gasoline in liters consumed: ";
    cin >> liters;
    //float point = km / liters;
    //float point1 = point / liters;
    //cout << km << endl << point1 << endl;
    return 0;
}