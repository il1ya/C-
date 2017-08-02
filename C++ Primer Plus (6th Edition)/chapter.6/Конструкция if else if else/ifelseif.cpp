/* Это выглядит как совершенно новая управляющая структура — if else if else. 
Но на самом деле это один оператор if else, вложенный в другой. 
Пересмотренный формат выглядит намного яснее и позволяет даже при поверхностном взгляде оценить все альтернативы. 
Вся эта конструкция по-прежнему трактуется как единственный оператор. 
В листинге 6.3 это форматирование используется для построения простой программы загадок и отгадок. 
Листинг 6.3. ifelseif.срр */
// ifelseif.cpp — использование оператора if else if else 
#include <iostream>
const int Fave = 27;
int main(void)
{
    using namespace std;
    int n;
    cout << "Enter a number in the range 1-100 to find ";
    cout << "my favorite number: "; // запрос на ввод числа из диапазона 1-100 
    do
    {
        cin >> n;
        if(n < Fave)
        cout << "Too low -- guess again: "; // число слишком мало 
        else if(n > Fave)
        cout << "Too high -- guess again: "; // число слишком велико 
        else 
        cout << Fave << " is right!\n"; // число угадано    
    }while(n != Fave);
    return 0;
}