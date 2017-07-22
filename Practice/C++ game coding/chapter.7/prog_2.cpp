// Напишите программу с указателем, направленным на указатель объекта string. С помощью указателя на указатель вызовите функцию-член size () объекта string.
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name = "ILLYA";
    string *pStr = &name;
    cout << name.size() << endl;
    return 0;
}