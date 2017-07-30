// Листинг 9.2. filel.срр 
// filel.срр — пример программы, состоящей из трех файлов 
#include <iostream>
#include "coordin.h" // шаблоны структур, прототипы функций 
using namespace std;
int main(void)
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: "; // ввод значений х и у 
    while(cin >> rplace.x >> rplace.y)    // ловкое использование сіп 
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
            // ввод следующих двух чисел (q для завершения)
    }
    cout << "Done.\n";
    return 0;
}