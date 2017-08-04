/* Формат — или синтаксис — написания оператора for может показаться чересчур ограниченным, поскольку тело цикла должно состоять из всего лишь одного оператора. 
Это весьма неудобно, если вы хотите, чтобы тело цикла включало несколько операторов. К счастью, C++ предлагает синтаксис, позволяющий поместить в тело цикла любое количество операторов. 
Трюк заключается в использовании пары фигурных скобок, с помощью которых конструируется составной оператор, или блок. Блок  
состоит из пары фигурных скобок с заключенными между ними операторами и синтаксически воспринимается как один оператор. 
Например, в листинге 5.8 фигурные скобки применяются для комбинирования трех отдельных операторов в единый блок. 
Это позволяет в теле цикла организовать вывод приглашения пользователю, прочитать его ввод и выполнить вычисления. 
Программа вычисляет текущую сумму вводимых значений, и это является удобным случаем для использования операции +=. 
Листинг 5.8. block.срр */
// block.срр — использование блока 
#include <iostream>
int main(void)
{
    using namespace std;
    cout << "The Amazing Accounto will sum and average ";
    cout << "five numbers for you.\n";
    cout << "Please enter five values:\n";
    double number;
    double sum = 0.0;
    for(int i = 1; i <= 5; i++)
    { // начало блока 
        cout << "Value " << i << ": ";
        cin >> number;
        sum += number;
    } // конец блока 
    cout << "Five exquisite choices indeed! ";
    cout << "They sum to " << sum << endl; // вывод суммы 
    cout << "and average to " << sum / 5 << ".\n"; // вывод среднего значения 
    cout << "The Amazing Accounto bids you adieu!\n";
    return 0;
}