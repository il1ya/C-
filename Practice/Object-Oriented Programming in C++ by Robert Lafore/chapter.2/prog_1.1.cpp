//1. Считая, что кубический фут равен 7.481 галлона, написать программу, запрашивающую у пользователя число галлонов и выводящую на экран эквивалентный объем в кубических футах.
#include <iostream>
int main()
{
    const double galon = 7.481;
    double enter, summ;
    std::cin >> enter;
    summ = enter / galon;
    std::cout << summ << std::endl;
    return 0;
}