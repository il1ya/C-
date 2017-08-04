/* Выполните упражнение 5, но используя двумерный массив для сохранения данных о месячных продажах за 3 года. 
Выдайте общую сумму продаж за каждый год и за все годы вместе. */

#include <iostream>
#include <string>
const int Size = 12;
const int YEAR = 3;
int main(void)
{
    using namespace std;
    string month[Size] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string *months = month;
    int salers[YEAR][Size];
    int i, j;
    for(i = 0; i < YEAR; i++)
    {
        cout << i + 1 << " year:" << endl;
        for(j = 0; j < Size; j++)
        {
            cout << "what volume of sales for " << *(months + j) << "?" << endl;
            cin >> salers[i][j];
        }
    }
    int allsum = 0;
    for(i = 0; i < YEAR; i++)
    {
        int sum = salers[i][0];
        for(j = 0; j < YEAR; j++)
        {
            sum += salers[i][j];
        }
        cout << "amount for the whole " << i + 1 << " year: " << sum << endl;
        allsum += sum;
    }
    cout << "amount for the whole " << YEAR << " year: " << allsum << endl;
    return 0;
}