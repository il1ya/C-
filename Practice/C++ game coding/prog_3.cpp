#include <iostream>
using namespace std;
int main()
{
    int *pScore = new int;
        *pScore = 500;
    cout << *pScore << endl;
        delete pScore;
    pScore = new int(1000);
    cout << *pScore << endl;
        delete pScore;
        *pScore = 0;
    cout << *pScore << endl;
    return 0;
}