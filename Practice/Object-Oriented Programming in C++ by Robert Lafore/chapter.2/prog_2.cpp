/*
2. Напишите программу, выводящую следующую таблицу:
1990 135
1991 7290
1992 11300
1993 16200
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << 1990 << setw(8) << 135 << endl;
    cout << 1991 << setw(8) << 7290 << endl;
    cout << 1992 << setw(8) << 11300 << endl;
    cout << 1993 << setw(8) << 16200 << endl;
    return 0;
}