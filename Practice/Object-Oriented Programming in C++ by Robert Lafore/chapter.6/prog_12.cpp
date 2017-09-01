#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>

class Fraction{
    public:
        int numerator;
        int denominator;
        Fraction(): numerator(0), denominator(0){}
        void function(Fraction f1, Fraction f2){
            numerator = f1.numerator * f2.numerator;
            denominator = f1.denominator * f2.denominator;
        }
        void lowterms();
        void show(){
            std::cout << std::setw(5) << numerator << "/" << denominator;
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
    int number;
    Fraction pr1, pr2, pr3;
    pr1.denominator = pr2.denominator = number;
    std::cout << "Enter denominator: ";
    std::cin >> number;
    for(int i = 1; i < number; i++){
        pr1.numerator = i;
        pr1.denominator = number;
        pr1.lowterms();
        pr1.show();
    }
    std::cout << std::endl;
    for(int j = 1; j < number; j++){
        pr2.numerator = j;
        pr2.denominator = number;
        pr2.lowterms();
        pr2.show();

    for(int i = 1; i < number; i++){
        pr1.numerator = i;
        pr1.denominator = number;
        pr3.function(pr1, pr2);
        pr3.lowterms();
        pr3.show();
    }
    std::cout << std::endl;
    }
    return 0;
}