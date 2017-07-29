/*
В листинге 10.8 показан измененный файл с методами класса. Он включает в себя новый метод topval().
Также теперь, когда вы ознакомились с работой конструкторов и деструкторов, в листинге 10.8 они заменены версиями, которые не выводят никаких сообщений. 
Листинг 10.8. stocks20.cpp */
// stock20.cpp -- дополненная версия 
#include <iostream>
#include "stock20.h"
// Конструкторы
Stock::Stock() // конструктор по умолчанию
{
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
Stock::Stock(const std::string & co, long n, double pr)
{
    companu = co;
    if(n < 0)
    {
        std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    shares = n;
    share_val = pr;
    set_tot();
}
// Деструктор 
Stock::~Stock() // деструктор, не выводящий сообщений
{

}
// другие методы
void Stock::buy(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. " << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(long num, double price)
{
    using std::cout;
    if(num < 0)
    {
        cout << "Number of shares sold can't be negative. " << "Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        cout << "You can't sell more than you have! " << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}
void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    // Установка формата в #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Company: " << company << " Shares: " << shares << '\n';
    cout << "Share Price: $" << chare_val;
    // Установка формата в #.##
    cout.precision(2);
    cout << "Total Worth: $" << total_val << '\n';
    // Востановление исходного формата
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}
const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val > total_val)
    return s;
    else 
    return *this;
}