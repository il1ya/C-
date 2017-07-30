// file1.cpp
#include <iostream>
using namespace std;
void other();
void another();
int x = 10;
int y;
int main()
{
    cout << x << endl; // 10
    {
        int x = 4;
        cout << x << endl; // 4
        cout << y << endl; // 1
    }
    other(); // 10, 1
    another(); // 10, -4
    return 0;
}
void other()
{
    int y = 1;
    cout << "Other: " << x << ", " << y << endl;
}