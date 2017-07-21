#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char name[20];
    float wages, worked = 0;
    cout << "Enter your name: ";
    cin.get(name, 20).get();
    cout << "Enter your hourly wages: ";
    cin >> wages;
    cout << "Enter number of hours worked: ";
    cin >> worked;
    printf("First format: \n%s: $ %.2f: %.1f\n", name, wages, worked);
    printf("Second format: \n%s : $ %.2f :%.1f\n", name, wages, worked);
    return 0;
}