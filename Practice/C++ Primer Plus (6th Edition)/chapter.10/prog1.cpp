// Упражнения по программированию 
// 1. Предоставьте определения методов для класса, описанного в вопросе 5, и напишите короткую программу для иллюстрации всех его возможностей. 
#include <iostream>
#include <cstring> 
class Bank
{
    private:
        std::string name_contributor;   // имя вкладчика
        std::string account_number;     // номер счета (используйте строку)
        double balance;                 // баланс
    public:
        Bank(const std::string &client, const std::string &num, double bal = 0.0)     // создание объекта и его инициализация
        {
            name_contributor = client;
            account_number = num;
            balance = bal;
        }
        void show(void)                                                                // отображение имени вкладчика, номера счета и баланса
        {
            std::cout << "Contributor name " << name_contributor << std::endl;
            std::cout << "Account number " << account_number << std::endl;
            std::cout << "Balance " << balance << std::endl;
        }
        void amount_adding(double cash)                                                // добавление на счет суммы денег, переданной в аргументе
        {
            balance += cash;
        }
        void amount_withdrawals(double cash)                                           // снятие суммы денег, переданной в аргументе
        {
            balance -= cash;
        }
};

int main(void)
{
    Bank first("Illya Skwvortsov", "22222223KD", 2500);
    first.show();
    first.amount_adding(0);
    first.show();
    first.amount_withdrawals(500);
    first.show();
    return 0;
}