// Листинг 15.11. error4.срр 
// error4.cpp — использование классов исключений 
#include <iostream>
#include <cmath>    // или math.h, пользователям UNIX может потребоваться флаг -lm 
#include "exc_mean.h"

// Прототипы функций 
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    double x, y, z;
    cout << "Enter two numbers: ";      // запрос на ввод двух чисел 
    while(cin >> x >> y)
    {
        try{
            z = hmean(x, y);
            cout << "Harmonic mean of "  << x << " and " << y << " is " << z << endl;           // вывод среднего гармонического 
            cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl; // вывод среднего геометрического 
            cout << "Enter next set of numbers <q to quit>: "; // ввод следующей пары чисел ' 
        }   // конец блока try 
        catch(bad_hmean &bg)         // начало блока catch 
        {
            bg.mesg();
            cout << "Try again.\n";  // необходимо повторить попытку 
            continue;
        }
        catch(bad_gmean &hg)
        {
            cout << hg.mesg();
            cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;   // используемые знарчения 
            cout << "Sorry, you don't get to play any more.\n";          // завершение работы 
            break;
        }                                                                // конец блока catch 
    }
    cout << "Bye!\n";
    return 0;
}
double hmean(double a, double b)
{
    if(a == -b)
        throw bad_hmean(a, b);
        return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
    if(a < 0 || b < 0)
        throw bad_gmean(a, b);
        return std::sqrt(a * b);
}
/*
Ниже приведен пример запуска программы из листингов 15.11 и 15.10; выполнение прекращается из-за недопустимых аргументов, переданных функции gmean(): 
Обратите внимание, что обработчик badhmean использует оператор continue, a обработчик bad_gmean — оператор break. 
Поэтому при обнаружении недопустимых данных в функции hmean() программа пропускает остаток цикла и переходит к его началу, а недопустимые данные в функции gmean() приводят к прекращению цикла. 
Подобным образом программа определяет, какое исключение возникло (по типу исключения), и выбирает реакцию на исключение. 
И еще одно: приемы, используемые в badgmean и badhmean, различны. 
В частности, в bad_gmean используются открытые данные и метод, возвращающий строку в стиле С. 
*/