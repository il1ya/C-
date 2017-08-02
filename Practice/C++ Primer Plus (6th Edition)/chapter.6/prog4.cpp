#include <iostream>
int main(void)
{
    using namespace std;
    int line = 0; 
    char ch; 
    while (cin.get(ch) && ch != 'Q') 
{ 
    if (ch == '\n') 
    line++; 
} 
    cout << line << endl;
    return 0;
}