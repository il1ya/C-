#include <iostream>
using namespace std;
void showmenu(); // прототипы функций 
void report();
void comfort();
int main(void)
{
    showmenu();
    char choice;
    cin >> choice;
    while(choice != 'Q')
    {
        switch(choice)
        {
            case 'A' : cout << "\a\n";
            break;
            case 'B' : report();
            break;
            case 'C' : cout << "The boss was in all day.\n";
            break;
            case 'D' : comfort();
            break;
            default : cout << "That's not a choice.\n";
        }
        showmenu();
        cin >> choice;
    }
    cout << "Bye!\n";
    return 0;
}
void showmenu()
{
    cout << "Please enter A, B, C, D, or Q:\n"
            "A) alarm       B) report\n"
            "C) alibi       D) comfort\n"
            "Q) quit\n";
}
void report()
{
    cout << "It's been an excellent week for business.\n"
            "Sales are up 120%. Expenses are down 35%.\n";
}
void comfort()
{
    cout << "Your employees think you are the finest CEO\n"
            "in the industry. The board of directors think\n"
            "you are the finest CEO in the industry.\n";
}