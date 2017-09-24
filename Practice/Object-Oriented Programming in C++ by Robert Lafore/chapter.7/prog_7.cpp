/* 7. 
Одним из недостатков C++ является отсутствие для бизнеспрограмм встроенного типа для денежных значений, такого, как $173 698 001.32. 
Такой денежный тип должен иметь возможность для хранения числа с фиксированной десятичной точкой точностью около 17 знаков, 
которого было бы достаточно для хранения национального долга в долларах и центах. 
К счастью, встроенный тип C++ long double имеет точность 19 цифр, поэтому мы можем использовать его как базисный для класса money, даже используя плавающую точку. 
Однако нам нужно будет добавить возможность ввода и вывода денежных значений с предшествующим им знаком доллара и разделенными запятыми группы по три числа: 
так проще читать большие числа. 
Первым делом при разработке такого класса напишем метод mstold(), который принимает денежную строку, то есть строку, представляющую собой некоторое количество денег типа
"$1 234 567 890 123.99"
в качестве аргумента и возвращает эквивалентное ее значению число типа long double.
Вам нужно будет обработать денежную строку как массив символов и, просматривая ее символ за символом, скопировать из нее только цифры (0-9) и десятичную точку в другую строку. 
Игнорируется все остальное, включая знак доллара и запятые. 
Затем вы можете использовать библиотечную функцию _atold() (заметим, что здесь название функции начинается с символа подчеркивания — заголовочные файлы STDLIB.H или MATH.H) 
для преобразования новой строки к числу типа long double. 
Предполагаем, что денежное значение не может быть отрицательным. 
Напишите функцию main() для проверки метода mstold(), которая несколько раз получает денежную строку от пользователя и выводит соответствующее число типа long double. 
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

class Biznes{
private:
    std::string string_numeral;
    long double large_numeral;
public:
    Biznes(): string_numeral(""), large_numeral(0){}
    Biznes(std::string s, long double l): string_numeral(s), large_numeral(l){}
    long double mstold(){
        std::cout << "Enter amount: ";
        std::cin >> string_numeral;
         int size = string_numeral.length();
         std::string sum;
        for(int i = 0; i < size; i++)
            if(string_numeral[i] != ',')
            sum.push_back(string_numeral[i]);
            large_numeral = stold(sum);
            return large_numeral;
        
    }
    void display() const{
        std::cout << std::setiosflags(std::ios::fixed) 
                  << std::setiosflags(std::ios::showpoint) 
                  << std::setprecision(2) 
                  << "\n" << string_numeral 
                  << std::endl;
    }
    ~Biznes(){}
};

int main()
{
    char enter;
    do{
        Biznes pr1;

        pr1.mstold();
        pr1.display();

        std::cout << "\ncontinue? (y/n): ";
        std::cin >> enter;
    }while(enter != 'n');
    std::cout << std::endl;

    return 0;
}


