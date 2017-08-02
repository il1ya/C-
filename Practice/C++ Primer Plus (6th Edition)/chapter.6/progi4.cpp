/*
Когда вы вступите в Благотворительный Орден Программистов (БОП), к вам могут обращаться на заседаниях БОП по вашему реальному имени, по должности либо секретному имени БОП. 
Напишите программу, которая может выводить списки членов по реальным именам, должностям, секретным именам либо по предпочтению самого члена. 
В основу положите следующую структуру: 
// Структура имен Благотворительного Ордена Программистов (БОП) 
struct bop { 
char fullname[strsize]; // реальное имя 
char title[strsize];    // должность 
char bopname[strsize];  // секретное имя БОП 
int preference;         // 0 = полное имя, 1 = титул, 2 = имя БОП 
}; 
В этой программе создайте небольшой массив таких структур и инициализируйте его соответствующими значениями. 
Пусть программа запустит цикл, который даст возможность пользователю выбирать разные альтернативы: 

a. display by name      b. display by title 
c. display by bopname   d. display by preference 
q. quit 

Обратите внимание, что "display by preference" (отображать по предпочтениям) не означает, что нужно отобразить член preference; это значит, что  
необходимо отобразить член структуры, который соответствует значению preference. 
Например, если preference равно 1, то выбор d должен вызвать отображение должности данного программиста. 
Пример запуска этой программы может выглядеть следующим образом: 
Benevolent Order of Programmers Report 

a. display by name b. display by title 
c. display by bopname d. display by preference 
q. quit 

Enter your choice: a 
Wimp Macho 
Raki Rhodes 
Celia Laiter 
Hoppy Hipman 
Pat Hand 
Next choice: d 
Wimp Macho 
Junior Programmer 
MIPS 
Analyst Trainee 
LOOPY 
Next choice: q 
Bye! 
*/


#include <iostream>
#include <string>
const int strsize = 50;
const int Size = 5;
using namespace std;

void menu(void);
void name(void);

struct bop
{
    char fullname[strsize];         // реальное имя
    char title[strsize];            // должность
    char bopname[strsize];          // секретное имя БОП 
    int preference;                 // 0 = полное имя, 1 = титул, 2 = имя БОП
};

int main(void)
{
    char ch;
        bop mystructur[Size] =
        {
             {"Illya Skvotrsov", "student", "Reidu", 4},
             {"Jarek", "Junior Programmer", "Jar", 1},
             {"No Face", "Programmer Java", "Java boys", 2},
             {"Frost", "C++", "Frc++", 3},
             {"Sakata, Gintoki", "home", "White Devil", 6}
        };

    cout << "Benevolent Order of Programmers Report\n";
    menu();
    cout << "Enter your choice:";
    cin >> ch;
    while(ch != 'q')
    {
        switch(ch)
        {
            case 'a' : for(int i = 0; Size > i; ++i)
                            cout <<  mystructur[i].fullname << endl;
            /* cout 
            << mystructur[0].fullname << endl 
            << mystructur[1].fullname << endl 
            << mystructur[2].fullname << endl 
            << mystructur[3].fullname << endl 
            << mystructur[4].fullname << endl;
            */
            break;
            case 'b' : for(int i = 0; Size > i; ++i)
                            cout << mystructur[i].title << endl;
            break;
            case 'c' : for(int i = 0; Size > i; ++i)
                            cout << mystructur[i].bopname << endl;
            break;
            case 'd' : for(int i = 0; Size > i; ++i)
                            cout << (mystructur[i].preference != 0 ? mystructur[i].preference == 1 ? mystructur[i].bopname : mystructur[i].title : mystructur[i].fullname) << endl;
            break;
            default : cout << "Invalid input!\n";
        }
        cout << "Next choice: ";
        cin >> ch;
    }
    cout << "Bye!\n";
    return 0;
}

void menu(void)
{
    cout << "a) display by name         b) display by title\n";
    cout << "c) display by bopname      d) display by preference\n";
    cout << "q) quit\n";
}
