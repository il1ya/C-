// Листинг 5.15. dowhile.срр 
// dowhile. срр -- цикл с проверкой на выходе 
#include <iostream>
int main(void)
{
    using namespace std;
    int n;
    cout << "Enter numbers in the range 1-10 to find ";
    cout << "my favorite number\n"; // запрос на ввод любимого числа из диапазона 1-10 
    do
    {
        cin >> n; // выполнить тело 
    }while(n != 7); // затем проверить 
    cout << "Yes, 7 is my favorite.\n "; // любимое число - 7 
    return 0;
}