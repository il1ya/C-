/*9. 
Две дроби а/b и c/d можно сложить следующим образом: a/b + c/d = (a*d + b*c)/(b*d)
Например, 1/4 + 2/3 = (1*3 + 4*2)/4*3 = 11/12 дробей, а затем выводящую результат, также записанный в форме дроби. 
Взаимодействие программы с пользователем может выглядеть, например, следующим образом:
Введите первую дробь: 1/2 
Введите вторую дробь: 2/5 
Сумма равна 9/10
Вы можете использовать тот факт, что операция извлечения >> может считывать более одного значения за раз: cin >> а >> dummychar >> b;*/
#include <iostream>
int main()
{
    int enter_1, enter_2, enter_3, enter_4, summ_1, summ_2;
    char symbol_1, symbol_2;
    std::cout << "Enter one fractions through a fraction: " << std::endl;
    std::cin >> enter_1 >> symbol_1 >> enter_2;
    std::cout << "Enter second fractions through a fraction: " << std::endl;
    std::cin >> enter_3 >> symbol_2 >> enter_4;
    summ_1 = (enter_1 * enter_4) + (enter_2 * enter_3);
    summ_2 = (enter_2 * enter_4);
    std::cout << "The amount is = " << summ_1 << "/" << summ_2 << std::endl;
    return 0;
}