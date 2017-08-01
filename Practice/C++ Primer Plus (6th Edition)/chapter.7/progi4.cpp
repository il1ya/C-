/*4. Многие лотереи в США организованы подобно той, что была смоделирована в листинге 7.4. 
Во всех их вариациях вы должны выбрать несколько чисел из одного набора, называемого полем номеров. 
(Например, вы можете выбрать 5 чисел из поля 1-47.) Вы также указываете один номер (называемый меганомером) из второго диапазона, такого как 1-27. 
Чтобы выиграть главный приз, вы должны правильно угадать все номера. 
Шанс выиграть вычисляется как вероятность угадывания всех номеров в поле, умноженная на вероятность угадывания меганомера. 
Например, вероятность выигрыша в описанном здесь примере вычисляется как вероятность угадывания 5 номеров из 47, умноженная на вероятность угадывания одного номера из 27. 
Модифицируйте листинг 7.4 для вычисления вероятности выигрыша в такой лотерее. 
*/
#include <iostream>
long double probability(unsigned numbers, unsigned picks);
int main(void)
{
    using namespace std;
    double total, total2, choices;
        // Ввод общего количества номеров и количества номеров, которые нужно угадать 
    cout << "Enter the total number of choices on the game card and\n";
    cout << "the number of picks allowed:\n";
    while((cin >> total >> total2 >> choices) && choices <= total)
    {
        cout << "You have one chance in ";
        cout <<  probability(total, choices) * probability(total2, 1);   // вычисление и вывод шансов 
        cout <<  " of winning.\n";
        cout << "Next two numbers(q to quit): ";
            // Ввод следующих двух чисел (q для завершения) 
    }
    cout << "Buy\n";
    return 0;
}

// Следующая функция вычисляет вероятность правильного 
// угадывания picks чисел из numbers возможных 
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0; // несколько локальных переменных 
    long double n;
    unsigned p;
    for(n = numbers, p = picks; p > 0; n--, p--)
    result = result * n / p;
    return result;
}