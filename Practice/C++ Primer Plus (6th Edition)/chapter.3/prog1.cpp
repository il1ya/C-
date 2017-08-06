/* 1. Напишите короткую программу, которая запрашивает рост в дюймах и преобразует их в футы и дюймы. Программа должна использовать символ  
подчеркивания для обозначения позиции, где будет производиться ввод. Для представления коэффициента преобразования используйте символьную константу const. */
#include <iostream>
int main(void)
{
    using namespace std;
    double inches, ft, inches1;
    cout << "Enter your height in inches:__\b\b";
    cin >> inches;
    ft = inches / 12;
    cout << "your height in ft = " << ft << endl;
    return 0;
}