// 2. Перепишите код из листинга 5.4 с использованием объекта array вместо встроенного массива и типа long double вместо long long. Найдите значение 100! 
#include <iostream>
#include <array>
using namespace std;
const int ArSize = 101;  // пример внешнего объявления 
int main(void)
{
    array<long double, ArSize> ar; 
    ar[1] = ar[0] = 1LL;

    for(int i = 2; i < ArSize; i++)
        ar[i] = i * ar[i-1];

    for(int i = 0; i < ArSize; i++)
       cout << i << "! = " << ar[i] << endl;
    return 0;
}

/*
#include<iostream>
#include<array>
using namespace std;

const int ArSize = 101; // пример внешнего объявления

void main() 
{

array <long double, ArSize> factorials;
factorials[1] = factorials[0] = 1LL;

for (int i = 2; i < ArSize; i++)
factorials[i] = i * factorials[i-1];

for (int i = 0; i < ArSize; i++ )
cout << i <<"! = " << factorials[i] << endl; 
}
*/