#ifndef BANK_H_
#define BANK_H_
#include <iostream>
#include <string>
class Bank
{
    private:
        std::string name_contributor;   // имя вкладчика
        std::string account_number;     // номер счета (используйте строку)
        double balance;                 // баланс
    public:
        Bank(const std::string &client, const std::string &num, double bal = 0.0);      // создание объекта и его инициализация
        void show(void);                                                                // отображение имени вкладчика, номера счета и баланса
        void amount_adding(double cash);                                                // добавление на счет суммы денег, переданной в аргументе
        void amount_withdrawals(double cash);                                           // снятие суммы денег, переданной в аргументе
        ~Bank()
        {
            std::cout << "End" << std::endl;
        }
};
#endif