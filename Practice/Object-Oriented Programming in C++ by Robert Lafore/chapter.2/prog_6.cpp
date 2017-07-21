// 6. На биржевых торгах за 1 фунт стерлингов давали $1.487, за франк — $0.172, за немецкую марку — $0.584, а за японскую йену — $0.00955. 
// Напишите программу, которая запрашивает денежную сумму в долларах, а затем выводит эквивалентные суммы в других валютах.
#include <iostream>
int main()
{
    const double funt = 1.487;
    const double frank = 0.172;
    const double nazi_mark = 0.584;
    const double japan_jen = 0.00955;
    double enter, summ_1, summ_2, summ_3, summ_4;
    while(std::cin >> enter)
    {
        summ_1 = enter / funt;
        std::cout << summ_1 << std::endl;
        summ_2 = enter / frank;
        std::cout << summ_2 << std::endl;
        summ_3 = enter / nazi_mark;
        std::cout << summ_3 << std::endl;
        summ_4 = enter / japan_jen;
        std::cout << summ_4 << std::endl;
    }
    return 0;
}