
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
        void input(){
            std::cout << "Enter the numerator and denominator values in the form 3/5\n";
            std::cin >> numerator;
            std::cout << "/" << std::endl;
            std::cin >> denominator;
        }
        void function_one(Fraction f1, Fraction f2){
            numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
            denominator = f1.denominator * f2.denominator;
        }
        void function_two(Fraction f1, Fraction f2){
            numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
            denominator = f1.denominator * f2.denominator;
        }
        void function_three(Fraction f1, Fraction f2){
            numerator = f1.numerator * f2.denominator;
            denominator = f1.denominator * f2.denominator;
        }
        void function_four(Fraction f1, Fraction f2){
            numerator = f1.numerator * f2.denominator;
            denominator = f1.denominator * f2.denominator;
        }
        void lowterms();
        void show(){
            std::cout << numerator << "/" << denominator << std::endl;
        }
        ~Fraction(){}
};


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
    char choice;
    do{
        Fraction pr1, pr2, summ;
        pr1.input();
        std::cout << "Enter the sign: ";
        pr2.input();
        std::cin >> choice;
        switch(choice){
            case '+': summ.function_one(pr1, pr2);
                break;
            case '-': summ.function_two(pr1, pr2);
                break;
            case '/': summ.function_three(pr1, pr2);
                break;
            case '*': summ.function_four(pr1, pr2);
                break;
        }
        summ.lowterms();
        summ.show();
        std::cout << "continue? (y/n)" << std::endl;
        std::cin >> choice;
    }while(choice != 'n');
    return 0;
}