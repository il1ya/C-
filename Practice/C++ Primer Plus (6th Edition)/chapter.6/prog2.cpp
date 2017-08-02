#include <iostream>
const int SIZE = 40;
int main(void)
{
    using namespace std;
    int a_grade, b_grade, c_grade, d_grade, f_grade;
    char ch;
    cin >> ch;
    while(ch != 'D')
{
        switch(ch)
    {
        case 'A' : a_grade++;
        break;
        case 'B' : b_grade++;
        break;
        case 'C' : c_grade++;
        break;
        case 'D' : d_grade++;
        break;
        default : f_grade++;
        break;
    }
}
    cout << a_grade << b_grade << c_grade << d_grade <<  f_grade << endl;
    return 0;
}