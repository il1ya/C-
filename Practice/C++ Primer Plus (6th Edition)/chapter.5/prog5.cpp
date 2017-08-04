/* 5. 
Предположим, что вы продаете книгу по программированию на языке C++ для начинающих. 
Напишите программу, которая позволит ввести ежемесячные объемы продаж в течение года (в количестве книг, а не в деньгах). 
Программа должна использовать цикл, в котором выводится приглашение с названием месяца, применяя массив указателей на char 
(или массив объектов string, если вы предпочитаете его), инициализированный строками — названиями месяцев, и сохраняя введенные значения в массиве int. 
Затем программа должна найти сумму содержимого массива и выдать общий объем продаж за год. 
*/
#include <iostream>
const int Size = 12;
int main(void)
{
    using namespace std;
    string month[Size] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string *months = month;
    int salers[Size];
    int i;
    for(i = 0; i < Size; i++)
    {
        cout << "what volume of sales for " << *(months + i) << "?" << endl;
        cin >> salers[i];
    }
    int sum = salers[0];
    for(i = 1; i < Size; i++)
    sum += salers[i];
    
    cout << "amount for the whole year: " << sum << endl;
    return 0;
}