#include <iostream>
#include "bank.h"
    
    Bank::Bank(const std::string &client, const std::string &num, double bal)           // создание объекта и его инициализация
        {
            name_contributor = client;
            account_number = num;
            balance = bal;
        }

   void Bank::show(void)                                                                // отображение имени вкладчика, номера счета и баланса
        {
            std::cout << "Contributor name " << name_contributor << std::endl;
            std::cout << "Account number " << account_number << std::endl;
            std::cout << "Balance " << balance << std::endl;
        }

   void Bank::amount_adding(double cash)                                                // добавление на счет суммы денег, переданной в аргументе
        {
            balance += cash;
        }

   void Bank::amount_withdrawals(double cash)                                           // снятие суммы денег, переданной в аргументе
        {
            balance -= cash;
        }