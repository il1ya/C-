/*Языки С и C++ разделяют эти два средства — прототип и определение — для библиотечных функций. 
Библиотечные файлы содержат скомпилированный код для функций, а заголовочные файлы — соответствующие прототипы. 
Прототип функции должен располагаться перед первым использованием функции. 
Чаще всего прототипы помещают непосредственно перед определением функции main(). 
В листинге 2.4 приведен пример использования библиотечной функции sqrt (); ее прототип предоставляется включением файла cmath. */
// Листинг 2.4. sqrt.cpp 
// sqrt.cpp — использование функции sqrt() 
#include <iostream>
#include <cmath> // или math.h
int main()
{
    using namespace std;
    double area;
    cout << "Enter the floor area, in square feet, of your home: ";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "That's the equivalent of a square " << side << " feet to the side." << endl;
    cout << "How fascinating!" << endl;
    return 0;
}

