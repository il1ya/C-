/* 2. Напишите программу, читающую в массив double до 10 значений пожертвований. 
(Или, если хотите, используйте шаблонный объект array.) Программа должна прекращать ввод при получении нечисловой величины. 
Она должна выдавать среднее значение полученных чисел, а также количество значений в массиве, превышающих среднее. 
*/
#include<iostream>

using namespace std;
const int MAX = 10;

int main(void) 
{
 double ar[MAX];
 cout << "Enter amount of donations" << endl;
 int i = 0; // счетчик 
 double sum; 
 while ((cin >> ar[i])) // если cin используется как часть проверочного условия, он преобр в bool. в данном случае оно равно тру пока вводятся числовые значения, т.е. принимается в счет ar[i] типа double, одновременно это выражение вставляет в массив значение введенное пользователем
  i++; // счетчик цикла и счетчик взносов после каждого цикла увеличивается.
 sum = ar[0];
 for (int j = 1; j<i; j++)
  sum += ar[j];
 double average = sum/i;
 cout << "Average = " << average << endl;
 cout << "values greater than the average: " << endl; 
 for (int k = 0; k<i; k++)
 {
    if (ar[k] > average)
    cout << ar[k] << endl;
 }
    cout << endl;
    return 0;
}
