/*
11
Модифицируйте калькулятор, созданный в упражнении 12 главы 5 так, чтобы вместо структуры fraction использовался одноименный класс. 
Класс должен содержать методы для ввода и вывода данных объектов, а также для выполнения арифметических операций. 
Кроме того, необходимо включить в состав класса функцию, приводящую дробь к несократимому виду. 
Функция должна находить наибольший общий делитель числителя и знаменателя и делить числитель и знаменатель на это значение. 
Код функции, названной lowterms(), приведен ниже: 
Можно вызывать данную функцию в конце каждого метода, выполняющего арифметическую операцию, либо непосредственно перед выводом на экран результата. 
Кроме перечисленных методов, вы можете включить в класс конструктор с двумя аргументами, что также будет полезно.
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
class Fraction{
    private:
        double one;
        double two;
        double sum;
        char choice;
    public:
        Fraction(): one(0), two(0), choice(' '){}
        Fraction(double o, double t, char c): one(o), two(t), choice(c){}
        void input(){
            std::cout << "Enter two numbers and a sign (example 10+20)\n";
            std::cin >> one;
            std::cin >> choice;
            std::cin >> two;
            switch(choice)
            {
                case '+': sum = one + two;
                    break;
                case '-': sum = one - two;
                    break;
                case '/': lowterms();//sum = one / two;
                    break;
                case '*': sum = one * two;
                    break;
                default:
                    std::cout << "Wrong input: " << choice << std::endl;
            }
        }
        void show_input(){
            std::cout << one << choice << two << "=" << sum << std::endl;
        }
        void lowterms();
        ~Fraction(){}
};


void Fraction::lowterms()       // сокращение дроби
{
    long tnum, tden, temp, gcd;
    tnum = labs(one);           // используем неотрицательные
    tden = labs(two);           // значения (нужен cmath)
    if(tden == 0){
        std::cout << "Invalid denominator!";
        exit(1);
    }else if(tnum == 0){        // проверка числителя на 0
        one = 0; 
        two = 1;
        return;
    }
    // нахождение наибольшего общего делителя
    while(tnum != 0){           // проверка числителя на 0
        if(tnum < tden){        // если числитель больше знаменателя,
            temp = tnum;        // меняем их местами
            tnum = tden;
            tden = temp;
        }
        tnum = tnum - tden;     // вычитание
    }
    gcd = tden;
    one = one / gcd;            // делим числитель и знаменатель на полученный наибольший общий делитель
    two = two / gcd;
}

int main()
{
    Fraction pr1;
    pr1.input();
    pr1.show_input();
    return 0;
}