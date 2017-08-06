/* 8. Вычислите следующие выражения: 
а. 8 * 9 + 2 = 74
б. 6 * 3 / 4 = 4
в. 3 / 4 * б = 0
г. 6.0 * 3 / 4 = 4
д. 15 % 4 = 3; */
#include <iostream>
int main(void)
{
    using namespace std;
    int name1, name2, name3, name4, name5;
    name1 = 8 * 9 + 2;
    name2 = 6 * 3 / 4;
    name3 = 3 / 4 * 6;
    name4 = 6.0 * 3 / 4;
    name5 = 15 % 4;
    cout << name1 <<endl << name2 <<endl << name3 << endl << name4 << endl << name5 << endl;
    return 0;
}