#include <iostream>
using namespace std;
int main(void)
{
    int a, b = 5;
    int c = 5;
    c = (c += 5) + (c * 5);
    cout << c << endl;
    return 0;
}