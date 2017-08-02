1. Посмотрите на следующие два фрагмента кода для подсчета пробелов и переводов строк: 
// Версия 1 
while (cin.get(ch)) // завершение по eof 
{ 
    if (ch == ' ') 
    spaces++; 
    if (ch == '\n') 
    newlines++; 
} 
// Версия 2 
while (cin.get(ch)) // завершение по eof 
{ 
    if (ch== ' ') 
    spaces++; 
    else if (ch == ' \n') 
    newlines++; 
} 
Какие преимущества (если они есть) у второй формы перед первой? 
1. 1 версия подсчитывает и пробелы и новую строку, тогда как 2 версия считает пробелы если они есть и новую строку.
1. Обе версии кода дают одинаковые ответы, однако версия 2 (с if else) более эффективна. 
Посмотрим, что произойдет, например, если ch является пробелом. В версии 1 после инкрементирования spaces выполняется проверка,  
является ли символ символом новой строки. Это непроизводительные затраты времени, поскольку код уже установил, что ch является пробелом и, следовательно, 
не может быть новой строкой. В версии 2 в аналогичной ситуации проверка на предмет новой строки пропускается. 


2. Какой эффект даст замена в листинге 6.2 выражения ++ch на ch+1? 
2. Одинкова ++ch начинает сразу ch+1 на следущий ход.
2. ++сh и ch + 1 дают одно и то же числовое значение. Однако ++сh имеет тип char и выводится в виде символа, в то время как ch + 1, поскольку добавляет 
char к типу int, является типом int и выводится в виде числа. 


3. Внимательно изучите следующую программу: 
#include <iostream> 
using namespace std; 
int main() 
{ 
    char ch; 
    int ct1, ct2; 
    ct1 = ct2 = 0; 
    while ((ch = cin.get()) != '$') 
    { 
    cout << ch; 
    ct1++; 
    if(ch = '$') 
        ct2++; 
        cout << ch; 
    } 
    cout << "ct1 = " << ct1 << ", ct2 = " << ct2 << "\n"; 
    return 0; 
} 

Предположим, что вы вводите следующие строки, нажимая клавишу <Enter> в конце каждой строки: 
Hi! 
Send $10 or $20 now! 
Каким будет вывод? (Вспомните, что ввод буферизуется.) 
3. ошибка в выводе.
3. Поскольку в программе используется ch = ' $' вместо ch == ' $ ',  комбинированный ввод и вывод выглядит следующим образом: 
Hi! 
Н$і$!$ 
$Send $10 or $20 now! 
S$e$n$d$ $ctl = 9, ct2 = 9 
Каждый символ преобразуется в $ до вывода во второй раз. Также значение выражения ch == $ является кодом символа $, следовательно, ненулевым,  
следовательно, true; таким образом, каждый раз происходит инкрементирование ct2. 


4. Постройте логические выражения для представления перечисленных ниже условий. 
а. weight больше или равно 115, но меньше 125. 
б. ch равно q или Q. 
в. х — четное, но не равно 26. 
г. х — четное, но не кратно 26. 
д. donation находится в диапазоне 1000-2000 или guest равно 1. 
е. ch — буква в нижнем или верхнем регистре. (Предполагается, что буквы нижнего регистра кодируются последовательно и буквы верхнего регистра также 
кодируются последовательно, но между буквами нижнего и верхнего регистров имеется промежуток.) 

4. 
a) (weight >= 155 && weight < 125)
б) (ch == 'q' || ch == 'Q')
в) (x % 2 == 0 && x != 26)
г) (x % 2 == 0 && !(x % 26 == 0)
д) (donation >= 1000 && donation <= 2000 || quest == 1)
e) (ch >= fat && ch <= 'z') || (ch >= 'A' && ch <= 'Z')

4.  a. weight >= 115 && weight < 125 
    6. ch == 'q' || ch == 'Q' 
    в. x % 2 == 0 && x != 26 
    r. x % 2 == 0 && ! (x % 26 == 0) 
    д. donation >= 1000 && donation <= 2000 I I guest == 1 
    е. (ch >= faf && ch <= 'z') | | (ch >= 'A' && ch <= 'Z') 


5. В английском языке предложение "I will not not speak" означает то же, что и "I will speak". Является ли выражение !!х в языке C++ тем же самым, что и х? 
5. нет
5. He обязательно. Например, если х равно 10, то !х равно 0, а !!х равно 1. Однако если х является переменной bool, то !!х является х. 


6. Постройте условное выражение, которое эквивалентно абсолютному значению переменной. 
То есть если значение х положительное, то значением выражения будет просто х, но если значение х отрицательное, то значением выражения должно быть -х, которое является положительным. 
6.   (х < 0) ? -х : х 
или 
    (х >= 0) ? х : -х; 

7. Перепишите следующий фрагмент с применением switch: 
if (ch == 'А') 
    a_grade++; 
else if (ch == 'B' ) 
    b_grade++; 
else if (ch == 'C') 
    c_grade++; 
    else if (ch == 'D') 
    d_grade++; 
    else 
    f_grade++; 

7.
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

7. switch(ch) 
{ 
case 'A' : a_grade++; 
break; 
case 'В' : b_grade++; 
break; 
case 'C' : c_grade++; 
break; 
case 'D': d_grade++; 
break; 
default: f_grade++; 
break; 
} 


8. Каково преимущество в листинге 6.10 использования символьных меток, таких как а и с, вместо цифр для выбора в меню и в операторе switch? 
(Подсказка: подумайте о том, что произойдет, если пользователь введет q в любом  регистре, и что случится, когда он введет в любом регистре 5.) 
8. 
#include <iostream>
using namespace std;
void showmenu(); // прототипы функций 
void report();
void comfort();
int main(void)
{
    showmenu();
    int choice;
    cin >> choice;
    while(choice != 5)
    {
        switch(choice)
        {
            case 1 : cout << "\a\n";
            break;
            case 2 : report();
            break;
            case 3 : cout << "The boss was in all day.\n";
            break;
            case 4 : comfort();
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
    cout << "Please enter 1, 2, 3, 4, or 5:\n"
            "1) alarm       2) report\n"
            "3) alibi       4) comfort\n"
            "5) quit\n";
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
***********************************************************************************
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
8. Если вы используете целочисленные метки, а пользователь вводит не целое число, такое как q, то программа зависнет, потому что целочисленный ввод не 
может быть обработан как символ. 
Однако если применяются целочисленные метки, а пользователь вводит целое число, например, 5, то символьный ввод будет интерпретировать 5 как символ. 
Затем в части default оператора switch можно предложить ввести другой символ. 


9. Посмотрите на следующий фрагмент кода: 
int line = 0; 
char ch; 
while (cin.get(ch)) 
{ 
    if(ch == 'Q') 
    break; 
    if (ch != '\n') 
    continue; 
    line++; 
} 

Перепишите этот код так, чтобы в нем не использовались операторы break и continue. 
9.
#include <iostream>
int main(void)
{
    using namespace std;
    int line = 0;
    char ch;
    while(cin.get(ch))
    {
        if(ch == 'Q')
        else
        (ch != '\n')
        line++;
    }
    cout << ch << line << endl;
    return 0;
}

9. Вот одна из версий кода: 
int line = 0; 
char ch; 
while (cin.get(ch) && ch != 'Q') 
{ 
    if (ch == '\n') 
    line++; 
} 
