/*
12. 
Создайте калькулятор, выполняющий четыре арифметических действия над дробями (см. упражнение 9 главы 2 и упражнение 4 этой главы). 
Формулы, демонстрирующие выполнение арифметических операций над дробями, приведены ниже.
Сложение: a/b+c/d=(a*d+b*c)/(b*d) 
Вычитание: a/b-c/d=(a*d-b*c)/(b*d) 
Умножение: a/b*c/d=(a*c)/(b*d) 
Деление: a/b/c/d = (a*d)/(b*c)
Пользователь должен сначала ввести первый операнд, затем знак операции и второй операнд. 
После вычисления результата программа должна отобразить его на экране и запросить пользователя о его желании произвести еще одну операцию.
*/
#include <iostream>
int main()
{
    std::string verifi;
    do{
        char fract, enter_0;
        int a, b, c, d, summ_0, summ_1;
        std::cout << "Enter the first fraction(Input by fraction 0/0)\n";
        std::cin >> a >> fract >> b;
        std::cout << "Enter the second fraction(Input by fraction 0/0)\n";
        std::cin >> c >> fract >> d;
        std::cout << "Enter operation mark +, -, /, *\n";
        std::cin >> enter_0;
        switch(enter_0){
            case '+': summ_0 = a*d + b*c;
                      summ_1 = b*d;
                break;
            case '-': summ_0 = a*d - b*c;
                      summ_1 = b*d;
                break;
            case '*': summ_0 = a*c;
                      summ_1 = b*d;
                break;
            case '/': summ_0 = a*d;
                      summ_1 = b*c;
                break;
            default:
            if(enter_0 == ')')
                std::cout << ":D\n";
            else
                std::cout << enter_0 << " I do not know such operation\n";
        }
        std::cout << "Results of calculation: " << summ_0 << fract << summ_1 << std::endl;
        std::cout << "Do you want to continue?\n(yes/no) ";
        std::cin >> verifi;
    }while(verifi != "no");
    std::cout << "Thanks for using the program, bye!\n";
    return 0;
}