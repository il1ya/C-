/* Инициализировать указатель можно в операторе объявления. В этом случае инициализируется указатель, а не значение, на которое он указывает. 
То есть следующие операторы устанавливают pt, а не *pt равным значению &higgens: 
int higgens = 5; 
int * pt = Shiggens; 
В листинге 4.16 демонстрируется инициализация указателя определенным адресом. 
Листинг 4.16. init_ptr.срр. */
// init_ptr.cpp — инициализация указателя 
#include <iostream>
int main(void)
{
    using namespace std;
    int higgens = 5;
    int *pt = &higgens;
    cout << "Value of higgens = " << higgens << "; Address of higgens = " << &higgens << endl;
    cout << "Value of *pt = " << *pt << "; Value of pt = " << pt << endl;
    return 0;
}