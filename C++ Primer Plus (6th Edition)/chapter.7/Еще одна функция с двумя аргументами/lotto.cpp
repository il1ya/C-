/*Для выполнения этого вычисления можно воспользоваться циклом for: 
long double result = 1.0; 
for (n = numbers, p = picks; p > 0; n —, p—) 
result = result * n / p; 
Вместо того чтобы сразу перемножить все составляющие числителя, цикл начинает с умножения 1.0 на первую составляющую числителя и делит его на первую составляющую знаменателя. 
Затем на следующем шаге цикл умножает и делит результат на следующие составляющие числителя и знаменателя. Это позволяет сохранять 
текущее произведение меньшим, чем если бы сначала выполнялось все умножение. 
Например, сравните 
(10 * 9) / (2 * 1) 
и 
(10 / 2) * (9 / 1) 
Первое выражение вычисляется как 90/2 и дает в результате 45, а второе вычисляется как 5 х 9 с получением того же результата 45. 
Результаты одинаковы, но в первом случае получается большее промежуточное значение (90), нежели во втором. 
Чем больше множителей, тем существеннее будет разница. Для больших чисел эта стратегия замены умножения делением может предохранить процесс вычисления от  
переполнения максимально возможного значения с плавающей точкой. 
В листинге 7.4 эта формула заключена в функцию probability (). Поскольку количество вариантов выбора и общее количество чисел должны быть положительными 
значениями, в программе для этих величин используется тип unsigned int  
(сокращенно — unsigned). Перемножение нескольких целых может породить достаточно большие результаты, поэтому в lotto. срр для возвращаемого значения функции  
применяется тип long double. К тому же такие выражения, как 49/6, порождают ошибки округления при работе с целочисленными типами. 
На заметку! 
Некоторые реализации C++ не поддерживают тип long double. Если ваша реализация относится к ним, используйте просто double. 
Листинг 7.4. lotto.срр */
// lotto.срр — вероятность выигрыша 
#include <iostream>
// Примечание: некоторые реализации требуют применения double вместо long double 
long double probability(unsigned numbers, unsigned picks);
int main(void)
{
    using namespace std;
    double total, choices;
        // Ввод общего количества номеров и количества номеров, которые нужно угадать 
    cout << "Enter the total number of choices on the game card and\n";
    cout << "the number of picks allowed:\n";
    while((cin >> total >> choices) && choices <= total)
    {
        cout << "You have one chance in ";
        cout <<  probability(total, choices);   // вычисление и вывод шансов 
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
/*
Обратите внимание, что увеличение количества вариантов в игровой карточке существенно снижает шансы на выигрыш. 
Замечания по программе 
Функция probability() из листинга 7.4 иллюстрирует два вида локальных переменных, которые встречаются в функциях. 
Первый — это формальные параметры (numbers и picks), объявленные в заголовке функции внутри круглых скобок.
Затем идут другие локальные переменные (result, n и р). Они объявлены между фигурными скобками, ограничивающими определение функции. 
Основная разница между формальными параметрами и другими локальными переменными состоит в том, что формальные параметры получают свои значения из функции, которая вызывает 
probability (), в то время как локальные переменные получают свои значения  внутри функции. 
*/