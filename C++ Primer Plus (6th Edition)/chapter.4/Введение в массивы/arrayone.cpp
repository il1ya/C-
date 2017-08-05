/* Небольшая программа анализа, представленная в листинге 4.1, 
демонстрирует несколько свойств массивов, включая их объявление, присваивание значение его элементам, а также инициализацию. */
// Листинг 4.1. arrayone.срр 
// arrayone.срр -- небольшие массивы целых чисел 
#include <iostream>
int main(void)
{
    using namespace std;
    int yams[3];        // создание массива из трех элементов 
    yams[0] = 7;        // присваивание значения первому элементу 
    yams[1] = 8;
    yams[2] = 6;
    int yamcosts[3] = { 20, 30, 5 }; // создание и инициализация массива 
    // Примечание. Если ваш компилятор C++ не может инициализировать 
    // этот массив, используйте static int yamcosts[3] вместо int yamcosts[3] 
    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    cout << "The total yam expense is " << total << " cents.\n";
    cout << "\nSize of yams array = " << sizeof yams;
    cout << " bytes.\n";
    cout << "Size of one element = " << sizeof yams[0];
    cout << " bytes.\n";
    return 0;

}