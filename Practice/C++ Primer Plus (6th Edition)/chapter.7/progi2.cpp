/* 2. 
Напишите программу, которая запрашивает у пользователя 10 результатов игры в гольф, сохраняя их в массиве. 
При этом необходимо обеспечить возможность прекращения ввода до ввода всех 10 результатов. 
Программа должна отобразить все результаты в одной строке и сообщить их среднее значение. 
Реализуйте ввод, отображение и вычисление среднего в трех отдельных функциях, работающих с массивами. 
*/
#include <iostream>
using namespace std;
const int SIZE = 10;

void menu(int arr[], int&);
float calculation(int arr[], int size);
void show(int arr[], int size, float siz);

int main(void)
{
    int count = 0;
    int ar[SIZE];
    cout << "Enter 10 results golfing:\n";
    menu(ar, count);
    float sred = calculation(ar, count);
    show(ar, count, sred);
    return 0;
}

void menu(int arr[], int &count)
{
    for( ; count < SIZE; count++)
    cin >> arr[count];
    if(arr[count] < 0)
    ;
}


float calculation(int arr[], int count)
{
    int sum = 0;
    for(int i = 0; i < count; i++)
        sum += arr[i];
        return (float)sum / count;
}

void show(int arr[], int count, float sred)
{
        cout << "results:\n";
    for(int i = 0; i < count; i++)
        cout << arr[i] << " ";
        cout << "\nAverage value: " << sred << endl;
}