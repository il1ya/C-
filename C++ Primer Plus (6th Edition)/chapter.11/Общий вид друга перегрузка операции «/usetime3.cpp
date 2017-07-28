// Листинг 11.12. usetime3.срр 
// usetime3.cpp — использование четвертой черновой версии класса Time 
// Компилировать usetime3.cpp и mytime3.cpp вместе 
#include <iostream>
#include "mytime3.h"
int main()
{
    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;    // operator+() 
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;     // функция-член operator*() 
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
    return 0;
}