// И, наконец, код в листинге 11.3 тестирует суммирование времени, реализованное классом Time. 
// Листинг 11.3. usetimeO.срр 
// usetimeO.срр -- использование первой черновой версии класса Time 
// компилировать usetimeO.срр и mytimeO.cpp вместе 
#include <iostream>
#include "mytime0.h"
int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;
    cout << "planning time = "; // время на планирование 
    planning.Show();
    cout << endl;
    cout << "coding time = ";   // время на кодирование 
    coding.Show();
    cout << endl;
    cout << "fixing time = ";   // время на исправление 
    fixing.Show();
    cout << endl;
    total = coding.Sum(fixing);
    cout << "coding.Sum(fixing) = ";
    total.Show();
    cout << endl;
    return 0;
}