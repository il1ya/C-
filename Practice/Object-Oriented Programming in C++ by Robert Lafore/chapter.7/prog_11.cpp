/* 11. 
Вернемся к обсуждению денежных строк из упражнения 6. 
Напишите метод ldtoms() для преобразования числа типа long double в денежную строку, представляющую это число. 
Для начала вам нужно проверить, что значение long double не очень большое. 
Мы предполагаем, что вы не будете пытаться преобразовать число, больше чем 9 999 999 999 999 990.00. 
Затем преобразуем long double в строку (без знака доллара и запятых), хранящуюся в памяти, используя объект ostrstream, как рассматривалось ранее в этой главе. 
Получившаяся отформатированная строка может быть помещена в буфер, называющийся ustring.
Затем вам нужно будет создать другую строку, начинающуюся со знака доллара, далее копируем цифру за цифрой из строки ustring, начиная сле- ва и вставляя запятые через каждые три цифры. 
Также вам нужно подав- лять нули в начале строки. 
Например, вы должны вывести $3 124.95, а не $0 000 000 000 003 124.95. 
Не забудьте закончить строку нулевым симво- лом '\0'.
Напишите функцию main() для тестирования этой функции путем много- кратного ввода пользователем чисел типа long double и вывода результата в виде денежной строки. */

//#include <stdafx.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Money{
private:
    std::string strMon;
    std::string strMon1;
    long double summ;
public:
    void idtoms(){
        std::stringstream conv;
        conv << summ;
        conv >> strMon;
    }
    void getmoney(){
        std::cout << "Enter the amount" << std::endl;
        std::cin >> summ;
        if(summ > 99999999999999990.00){
            std::cout << "\nError.Try Again";
            // exit(1);
        }
    }
    void strings(){
        std::string doll("$");
        strMon1 = strMon;
        strMon1 = doll+strMon1;
        int x = strMon1.find('.');
        strMon1.erase(x,1);
        reverse(strMon1.begin(), strMon1.end());
        strMon1.inser(5, " ");
        strMon1.insert(8, " ");
        strMon1.insert(11, " ");
        strMon1.insert(14, " ");
        strMon1.insert(17, " ");
        strMon1.insert(2, ".");
        reverse(strMon1.begin(), strMon1.end());
    }
    void display() const{
        std::cout << "\n" << strMon1 << std::endl;
    }
};

int main()
{
    Money money;
    money.getmoney();
    money.idtoms();
    money.strings();
    money.display();
    return 0;
}