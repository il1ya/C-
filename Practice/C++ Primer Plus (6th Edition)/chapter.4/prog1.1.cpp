#include <iostream>
int main(void)
{
    using namespace std;
    char address[80];
    cin.getline(address, 80); 
    cin >> address;
    cout << address << endl;
    return 0;
}