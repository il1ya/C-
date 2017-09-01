/*9. 
На основе структуры fraction из упражнения 8 главы 4 создайте класс fraction. 
Данные класса должны быть представлены двумя полями: числителем и знаменателем. 
Методы класса должны получать от пользователя значения числителя и знаменателя дроби в форме 3/5 и выводить значение дроби в этом же формате. 
Кроме того, должен быть разработан метод, складывающий значения двух дробей. 
Напишите функцию main(), которая циклически запрашивает у пользователя ввод пары дробей, затем складывает их и выводит результат на экран. 
После каждой такой операции программа должна спрашивать пользователя, следует ли продолжать цикл. */

#include <iostream>
class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int n, int d): numerator(n), denominator(d){}
        Fraction(): numerator(0), denominator(0){}
        void get(){
            std::cout << "Enter the numerator and denominator values in the form 3/5\n";
            std::cin >> numerator;
            std::cout << "/" << std::endl;
            std::cin >> denominator;
        }
        void function(Fraction f1, Fraction f2){
            numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
            denominator = f1.denominator * f2.denominator;
        }
        void show(){
            std::cout << numerator << "/" << denominator << std::endl;
        }
        ~Fraction(){}
};

int main()
{
    char enter;
    do{
    Fraction pr1, pr2, pr3;
    pr1.get();
    pr2.get();
    pr3.function(pr1, pr2);
    pr3.show();
    std::cout << "Continue? y / n" << std::endl;
    std::cin >> enter;
    }while(enter == 'y');
    return 0;
}