#include <iostream>
int main(void)
{
    using std::cout;
    using std::cin;
    using std::endl;
    double x;
    cout << "Enter value: ";
    while(!(cin >> x))
    {
        cout << "Bad input, Please enter a number: "; // неверный ввод
        cin.clear();
        while(cin.get() != '\n')
        continue;
    }
    cout << "Value = " << x << endl;
    return 0;
}