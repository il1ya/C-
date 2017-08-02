/* Напишите предшественник программы, управляемой меню. Она должна отображать меню из четырех пунктов, каждый из них помечен буквой. 
Если пользователь вводит букву, отличающуюся от четырех допустимых, программа должна повторно приглашать его ввести правильное значение до тех пор, пока он этого не сделает. 
Затем она должна выполнить некоторое простое действие на основе пользовательского выбора. Работа программы должна выглядеть примерно так: 
Please enter one of the following choices: 
c) carnivore p) pianist 
t) tree g) game 
f 
Please enter a c, p, t, or g: q 
Please enter a c, p, t, or g: t 
A maple is a tree. 
*/
#include <iostream>
using namespace std;
void menu(void);
int main(void)
{
    char ch;
    menu();
    cin >> ch;
    while(ch != 'Q')
    {
        switch(ch)
        {
        case 'c' : cout << "tiger\n";
        break;
        case 't' : cout << "Pine\n";
        break;
        case 'p' : cout << "Fryderyk Franciszek Chopin\n";
        break;
        case 'g' : cout << "xcom 2\n";
        break;
        default : cout << "Wrong answer!\n";
        }
    cout << "Please enter a c, p, t, or g: ";
    cin >> ch;
    }
    cout << "Bye!\n";
    return 0;
}

void menu(void)
{
    cout << "Please enter one of the following choices(exit Q):\n";
    cout << "c) carnivore           p) pianist\n";
    cout << "t) tree                g) game\n";
}
