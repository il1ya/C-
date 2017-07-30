#include <iostream>
using namespace std;
int main() 
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && a==c && b==c) 
    cout << 3; 
    else if(a!=b && a!=c && b!=c) 
    cout << 0; 
    else 
    cout << 2; 
    return 0;
}