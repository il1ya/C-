/*12. 
Создайте класс bMoney. 
Он должен хранить денежные значения как long double. 
Используйте метод mstold() для преобразования денежной строки, введенной пользователем, в long double, 
и метод ldtoms() для преобразования числа типа long double в денежную строку для вывода (см. упражне- ния 6 и 10). 
Вы можете вызывать для ввода и вывода методы getmoney()и putmoney(). 
Напишите другой метод класса для сложения двух объектов типа bMoney и назовите его madd(). 
Сложение этих объектов легко произ- вести: просто сложите переменную типа long double одного объекта с такой же переменной другого объекта. 
Напишите функцию main(), которая просит пользователя несколько раз ввести денежную строку, а затем выводит сумму значений этих строк. Вот как может выглядеть определение класса:
class bMoney {
private:
long double money; public: bMoney();
bMoney(char s[]);
void madd(bMoney m1, bMoney m2);
void getmoney();
void putmoney();
}; */


#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

class bMoney{
private:
    std::string strMon;
    long double number;
public:
    bMoney(): number(0){}
    void mstold(){
        std::cout << "Enter: ";
        getline(std::cin, strMon, '$');
        int wlen = strMon.length();
        int n = 0;
        std::string num;
        for(int j = 0; j < wlen; j++)
            if(strMon[j] != ',' && strMon[j] != '$')
                num.push_back(strMon[j]);
                number = stold(num);
    }
    void madd(bMoney mon1, bMoney mon2){
        number = mon1.number + mon2.number;
    }
    void display() const{
        std::cout << std::setiosflags(std::ios::fixed) 
        << std::setiosflags(std::ios::showpoint) 
        << std::setprecision(2) 
        << "\n" << number << '$' << std::endl;
    }

};

int main()
{
    bMoney money1, money2, moneysum;
    char enter;
    do{
        money1.mstold();
        money2.mstold();
        moneysum.madd(money1, money2);
        moneysum.display();
        std::cout << "\ncontinue?(y/n)" << std::endl;
        std::cin >> enter;
    }while(enter != 'n');
    return 0;
}