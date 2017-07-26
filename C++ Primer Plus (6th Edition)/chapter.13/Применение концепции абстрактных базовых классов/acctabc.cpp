// Следующий шаг — реализация методов, у которых нет встроенных определений. 
// Это сделано в листинге 13.12. 
// Листинг 13.12. acctabc.cpp 
// acctabc.cpp -- методы класса банковских счетов 
#include <iostream>
#include "acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;

// Абстрактный базовый класс 
AcctABC::AcctABC(const string &s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}
void AcctABC::Deposit(double amt)
{
    if(amt < 0)
        cout << "Negative deposit not allowed; " << "deposit is cancelled.\n"; // отрицательный вклад не допускается
    else
        balance += amt;
}
void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

// Защищенные методы для. форматирования 
AcctABC::Formatting AcctABC::SetFormat() const
{
    // Установка формата ###.## 
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting &f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

// Методы Brass 
void Brass::Withdraw(double amt)
{
    if(amt < 0)
        cout << "Withdrawal amount must be positive; " << "withdrawal canceled.\n"; // снимаемая сумма должна быть положительной 
        else if(amt <= Balance())
        AcctABC::Withdraw(amt);
        else
            cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n" << "Withdrawal canceled.\n"; // снимаемая сумма превышает текущий баланс 
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;             // клиент Brass 
    cout << "Account Number: " << AcctNum() << endl;            // номер счета 
    cout << "Balance: $" << Balance() << endl;                  // баланс 
    Restore(f);
}

// Методы BrassPlus 
BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : AcctABC(ba)  // используется неявный конструктор копирования 
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "BrassPlus Client: " << FullName() << endl;     // клиент BrassPlus 
    cout << "Account Number: " << AcctNum() << endl;        // номер счета 
    cout << "Balance: $" << Balance() << endl;              // баланс 
    cout << "Maximum loan: $" << maxLoan << endl;           // максимальный заем 
    cout << "Owed to bank: $" << owesBank << endl;          // долг банку 
    cout.precision(3);
    cout << "loan Rate: " << 100 * rate << "%\n";           // процент на заем 
    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();
    double bal = Balance();
    if(amt <= bal)
        AcctABC::Withdraw(amt);
        else if(amt <= bal + maxLoan - owesBank)
        {
            double advance = amt - bal;
            owesBank  += advance * (1.0 + rate);
            cout << "Bank advance: $" << advance << endl;               // аванс банка 
            cout << "Finance charge: $" << advance * rate << endl;      // долг банку 
            Deposit(advance);
            AcctABC::Withdraw(amt);
        }
        else
            cout << "Credit limit exceeded. Transaction cancelled.\n";   //предел кредита превышен 
            Restore(f);
}
/*
Защищенные методы FullName() и AcctNum() предоставляют доступ только для чтения к членам данных fullName и acctNum, а также позволяют индивидуально настроить функцию ViewAcct() для каждого производного класса. 
В этой версии содержится пара усовершенствований в форматировании. 
В предыдущей версии использовались два вызова функции для указания форматирования и один вызов для восстановления: 
format initialState = SetFormatO; 
precis prec = cout.precision(2); 
restore(initialState, prec);    // восстановление исходного формата 

В новой версии определена структура для хранения двух значений форматирования, которая применяется для указания и восстановления форматов лишь за два вызова: 
struct Formatting 
{ 
    std::ios_base::fmtfglas flag; 
    std::streamsize pr; 
}; 
Formatting f = SetFormatO; 
Restore(f); 
Это выглядит аккуратнее. 
Проблема со старой версией была в том, что в ней функции setFormat() и restore() были автономными, и их имена могли конфликтовать с именами функций, определенных клиентом. 
Устранить такую проблему можно несколькими способами. 
Один из них — объявление обеих функций с квалификатором static, что делает их закрытыми в файле brass.срр или его предшественнике — файле acctabc.срр. 
Второй способ — помещение обеих функций и определения structFormatting в пространство имен. 
Но одной из тем в рассматриваемом примере является защищенный доступ, поэтому здесь определения структур и функции помещены в защищенную часть определения класса. 
Это делает их доступными в базовом классе и производных классах, но скрывает от внешнего мира. 
*/