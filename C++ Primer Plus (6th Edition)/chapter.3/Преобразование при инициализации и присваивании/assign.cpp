// Листинг 3.13. assign.срр 
// assign.срр -- изменение типа при инициализации 
#include <iostream>
int main(void)
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;     // int преобразован в float 
    int guess = 3.9832; // float преобразован в int 
    // int debt = 7.2E12;  // результат не определен в C++ 
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
   // cout << "debt = " << debt << endl;
    return 0;
}
