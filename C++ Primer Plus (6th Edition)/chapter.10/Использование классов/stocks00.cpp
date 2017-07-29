/*
Памятуя об этих двух обстоятельствах, методы класса можно реализовать, как показано в листинге 10.2. 
Эти определения методов могут быть помещены в отдельный файл либо в тот же файл, где находится объявление класса. 
Мы поместили их в отдельный файл реализации, поэтому в нем потребуется включить заголовочный файл stockOO.h, чтобы компилятор имел доступ к определению класса. 
Для демонстрации возможности работы с пространствами имен в одних методах используется квалификатор std::, а в других — объявления using. 
Листинг 10.2. stocksOO.cpp */
// stockOO.срр -- реализация класса Stock 
// версия 00 
 
#include <iostream>
#include "stock00.h"
void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if(n < 0)
    {
        // Количество пакетов не может быть отрицательным; устанавливается в 0. 
        std::cout << "Number of shares can't be negative; " << company  << " shares set to 0.\n";
        shares = 0;
    }
    else
    shares = n;
    share_val = pr;
    set_tot();
}
void Stock::buy(long num, double price)
{
    if(num < 0)
    {
    
    //Количество приобретаемых пакетов не может быть отрицательным. Транзакция прервана. 
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
        // Количество продаваемых пакетов не может быть отрицательным. Транзакция прервана, 
        cout << "Number of shares sold can't be negative. " << "Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        // Нельзя продать больше того, чем находится во владении. Транзакция прервана, 
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
void Stock::show()
{
    // Вывод названия компании, количества пакетов, цены пакета и общей стоимости. 
    std::cout << "Company: " << company << "Shares: " << shares << '\n' << "Share Price: $" << share_val << "Total Worth: $" << total_val << '\n';
}