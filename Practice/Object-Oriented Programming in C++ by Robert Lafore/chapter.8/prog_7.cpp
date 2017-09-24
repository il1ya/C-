/* 7. 
Модифицируйте класс fraction в четырехфункциональном дробном калькуляторе из упражнения 11 главы 6 так, чтобы он использовал перегруженные операции сложения, вычитания, 
умножения и деления. (Вспомните правила арифметики с дробями в упражнении 12 главы 3 «Циклы и ветвления».) 
Также перегрузите операции сравнения == и != и используйте их для выхода из цикла, когда пользователь вводит 0/1, 0 и 1 значения двух частей дроби. 
Вы можете модифицировать и функцию lowterms() так, чтобы она возвращала значение ее аргумента, уменьшенное до несократимой дроби. 
Это будет полезным в арифметических функциях, которые могут быть выполнены сразу после получения ответа. */

#include <iostream>
#include <cmath>
#include <stdlib.h>

class Fraction{
    private:
        double numerator;
        double denominator;
    public:
        Fraction(): numerator(0), denominator(0){}
        Fraction(double n, double d): numerator(n), denominator(d){}
        void get(){
            char enter;
            std::cout << "\nEnter fraction (1/1)\n";
            std::cin >> numerator;
            std::cin >> enter;
            std::cin >> denominator;
        }
        void lowterms();
        Fraction operator+(Fraction d2);
        Fraction operator-(Fraction d2);
        Fraction operator/(Fraction d2);
        Fraction operator*(Fraction d2);
        void display(){
            std::cout << "Result = " << numerator << "/" << denominator << std::endl;
        }
        ~Fraction(){}
};
Fraction Fraction::operator+(Fraction d2){
    double num = numerator * d2.denominator + denominator * d2.numerator;
    double denom = denominator * d2.denominator;
    return Fraction(num, denom);
}
Fraction Fraction::operator-(Fraction d2){
    double num = numerator * d2.denominator - denominator * d2.numerator;
    double denom = denominator * d2.denominator;
    return Fraction(num, denom);
}
Fraction Fraction::operator/(Fraction d2){
    double num = numerator * d2.denominator;
    double denom = denominator * d2.denominator;
    return Fraction(num, denom);
}
Fraction Fraction::operator*(Fraction d2){
    double num = numerator * d2.denominator;
    double denom = denominator * d2.denominator;
    return Fraction(num, denom);
}

void Fraction::lowterms()       // сокращение дроби
{
    long tnum, tden, temp, gcd;
    tnum = labs(numerator);           // используем неотрицательные
    tden = labs(denominator);           // значения (нужен cmath)
    if(tden == 0){
        std::cout << "Invalid denominator!";
        exit(1);
    }else if(tnum == 0){        // проверка числителя на 0
        numerator = 0; 
        denominator = 1;
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
    numerator = numerator / gcd;            // делим числитель и знаменатель на полученный наибольший общий делитель
    denominator = denominator / gcd;
}

int main()
{
    char enter;
    do{
        Fraction one, two, sum;
        char choice;
        one.get();
        std::cout << "Enter sign (+,-,/,*): ";
        std::cin >> choice;
        two.get();
        switch(choice)
        {
            case '+': sum = one + two;
                break;
            case '-': sum = one - two;
                break;
            case '/': sum = one / two;
                break;
            case '*': sum = one * two;
                break;
            default:
                std::cout << "Wrong input: " << choice << std::endl;
            }
            sum.lowterms();
            sum.display();
            std::cout << "\ncontinue? (y/n)\n";
            std::cin >> enter;
        }while(enter != 'n');

    return 0;
}