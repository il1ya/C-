/* Предположим, что хі и х2 являются переменными типа double, которые вы хотите просуммировать как целые числа, а полученный результат присвоить целочисленной переменной. 
Напишите для этого необходимый оператор C++. Что если вы хотите просуммировать их как значения double, а затем  преобразовать результат в int? */
#include <iostream>
int main(void)
{
    using namespace std;
    double xi, s2;
    cout << "Enter first: ";
    cin >> xi;
    cout << "Enter next: ";
    cin >> s2;
    int name1 = double(xi) + double(s2);
    cout << name1 << endl;
    return 0;
}