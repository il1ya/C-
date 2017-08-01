/* 5. Определите рекурсивную функцию, принимающую целый аргумент и возвращающую его факториал. 
Вспомните, что факториал 3 записывается, как 3! и вычисляется как 3x2! и т.д., причем 0! равно 1. 
В общем случае, если n больше нуля, то п != п *(п-1)!. 
Протестируйте функцию в программе, использующей цикл, где пользователь может вводить различные значения, для которых программа вычисляет и отображает факториалы. 
*/
// recur.срр — использование рекурсии 
#include <iostream>
using namespace std;
long long factorial(long long, long long);
int main(void)
{
    long long num, fact;
    cout << "Enter num (Press any letter to exit)" << endl;
    while(cin >> num)
    {
        fact = factorial(num, num);
        cout << num << "! = " << fact << endl;
    }
    cout << "Bye!" << endl;
}

long long factorial(long long n, long long fact)
{
    if(n == 0)
    return 1;
    while(n > 1)
    {
        fact *= (n - 1);
        n--;
        factorial(n, fact);
    }
    return fact;
}