// Напишите цикл for, который печатает значения 1 2 4 8 16 32 64, увеличивая вдвое значение переменной счетчика на каждом шаге. 
#include <iostream>
const int Size = 64;
int main(void)
{
    using namespace std;
    int i;
    for(i = 1; i <= Size; i *= 2)
    cout << i << endl;
    return 0;
}