/* 6. 
Напишите программу, использующую описанные ниже функции. 
Fill_array() принимает в качестве аргумента имя массива элементов типа double и размер этого массива. 
Она приглашает пользователя ввести значения double для помещения их в массив. 
Ввод прекращается при наполнении массива либо когда пользователь вводит нечисловое значение и возвращает действительное количество элементов. 
Show_array() принимает в качестве аргументов имя массива значений double, а также его размер, и отображает содержимое массива. 
Reverse_array() принимает в качестве аргумента имя массива значений double, а также его размер, и изменяет порядок его элементов на противоположный. 
Программа должна использовать эти функции для наполнения массива, обращения порядка его элементов, кроме первого и последнего, с последующим отображением. 
*/
#include <iostream>
using namespace std;
const int SIZE = 5;
int Fill_array(double arr[], int n);
void Show_array(double arr[], int n);
void Reverse_array(double arr[], int n);

int main(void)
{
    double arr[SIZE];
    int i;
    i = Fill_array(arr, SIZE);
    Show_array(arr, i);
    Reverse_array(arr, i);
    Show_array(arr, i);
    return 0;
}

int Fill_array(double arr[], int n)
{
    int temp, i;
    for(i = 0; i < SIZE; i++)
    {
        cout << "\nEnter " << i+1 << " num ";
        cin >> temp;
        if(!cin) //если неправильный ввод
        {
            cin.clear(); // очистка буфера
            while(cin.get() != '\n') //пока в буфере не попадется знак ввода
            continue; //запуск цикла очистки сначала
            cout << "Bad input. \n" << endl;
            break; //прерывание всего цикла for
        }
        else if(temp < 0)
        break; //прерывание всего цикла for
        arr[i] = temp;
    }
    return i; // возврат количества введенных элементов в массив
}

void Show_array(double arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << "arr[" << i+1 << "] = " << arr[i] << endl;
}

void Reverse_array(double arr[], int n)
{
    double temp;
    for(int i = 0; i < (n / 2); i++)
    {
        if(i == 0)
        continue;
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}