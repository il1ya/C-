/**4. Создайте эквивалент калькулятора, выполняющего четыре основных арифметических операции. 
Программа должна запрашивать ввод пользователем первого операнда, знака операции и второго операнда. 
Для хранения операндов следует использовать переменные вещественного типа. 
Выбрать операцию можно при помощи оператора switch. 
В конце программа должна отображать результат на экране. 
Результат работы программы с пользователем может выглядеть следующим образом:
Введите первый операнд, операцию и второй операнд: 10 / 3
Результат равен 3.333333
Выполнить еще одну операцию (y/n)? y
Введите первый операнд, операцию и второй операнд: 12 + 100
Результат равен 112
Выполнить еще одну операцию (y/n)? n */
#include <iostream>
int main()
{
    double enter_1, enter_2, summ_1, summ_2;
    char ch, ch_1;
    do
    {
        std::cout << "Enter the first operand, operation, and second operand: ";
        std::cin >> enter_1 >> ch >> enter_2;
            switch(ch)
            {
            case '+': std::cout << enter_1 + enter_2 << std::endl;
            break;
            case '-': std::cout << enter_1 - enter_2 << std::endl;
            break;
            case '/': std::cout << enter_1 / enter_2 << std::endl;
            break;
            case '*': std::cout << enter_1 * enter_2 << std::endl;
            break;
            default:
                std::cout << ch << "- i don't know this symbol :(" << std::endl;
            }
        std::cout << "Enter the first operand, operation, and second operand: ('y' continue 'n' end)";
        std::cin >> ch_1;
    }while(ch_1 != 'n');
    return 0;
}
