8. /*
Модифицируйте класс bMoney из упражнения 12 главы 7 «Массивы и строки», включив арифметические операции, выполненные с помощью перегруженных операций:
bMoney = bMoney + bMoney 
bMoney = bMoney - bMoney
bМоnеу = bMoney * long double (цена за единицу времени, затраченного на изделие) 
long double = bMoney / bMoney (общая цена, деленная на цену за изделие) 
bMoney = bMoney / long double (общая цена, деленная на количество изделий)
Заметим, что операция / перегружена дважды. 
Компилятор может различить оба варианта, так как их аргументы разные. 
Помним, что легче выполнять арифметические операции с объектами класса bMoney, выполняя те же операции с его long double данными.
Убедитесь, что программа main() запросит ввод пользователем двух денежных строк и числа с плавающей точкой. 
Затем она выполнит все пять операций и выведет результаты. Это должно происходить в цикле, так, чтобы пользователь мог ввести еще числа, если это понадобится.Некоторые операции с деньгами не имеют смысла: bMoney*bMoney не пред- ставляет ничего реального, так как нет такой вещи, как денежный квад- рат; вы не можете прибавить bMoney к long double (что же будет, если рубли сложить с изделиями?). Чтобы сделать это невозможным, скомпилируйте такие неправильные операции, не включая операции преобразования для bMoney в long double или long double в bMoney. Если вы это сделаете и запи- шете затем выражение типа:
bmon2 = bmon1 + widgets; // это не имеет смысла
то компилятор будет автоматически преобразовывать widgets в bMoney и выполнять сложение. Без них компилятор будет отмечать такие преобра- зования как ошибки, что позволит легче найти концептуальные ошибки. Также сделайте конструкторы преобразований явными.
Вот некоторые другие вероятные операции с деньгами, которые мы еще не умеем выполнять с помощью перегруженных операций, так как они требуют объекта справа от знака операции, а не слева:
long double * bMoney // Пока не можем это сделать: bMoney возможен только справа long double / bMoney // Пока не можем это сделать: bMoney возможен только справа
Мы рассмотрим выход из этой ситуации при изучении дружественных функций в главе 11.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

class bMoney{
private:
    std::string strMon;
    long double number;
public:
    bMoney(): number(0){}
    bMoney(long double num){
        number = num;
    }
    operator long double() const{
        long double num = number;
        return num;
    }
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
    bMoney operator+(bMoney b2){
        return number + b2.number;
    }
    bMoney operator-(bMoney b2){
        return number - b2.number;
    }
    bMoney operator*(long double b2){
        return number * b2;
    }
    bMoney operator/(bMoney b2){
        return number / b2.number;
    }
    bMoney operator/(long double b2){
        return number / b2;
    }
    bMoney
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
    long double sum = 0;
    char enter;
    do{
        money1.mstold();
        money2.mstold();
        moneysum = money1 + money2;
        moneysum.display();
        moneysum = money1 - money2;
        moneysum.display();
        sum = money2;
        moneysum = money1 * sum;
        moneysum.display();
        moneysum = money1 / money2;
        moneysum.display();
        moneysum = money1 / sum;
        moneysum.display();
        std::cout << "\ncontinue?(y/n)" << std::endl;
        std::cin >> enter;
    }while(enter != 'n');
    return 0;
}