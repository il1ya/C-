/*
Вы, возможно, хотели бы увидеть полный пример АБК, поэтому давайте применим этот принцип к представлению счетов Brass и BrassPlus, начав с абстрактного базового класса AcctABC. 
Этот класс должен содержать все методы и данные-члены, общие для классов Brass и BrassPlus. 
Методы, работа которых различается для классов BrassPlus и Brass, необходимо объявлять как виртуальные функции. 
Чтобы сделать класс AcctABC абстрактным, по крайней мере, одна виртуальная функция должна быть чистой виртуальной. 
В листинге 13.11 приведен заголовочный файл, в котором объявлен класс AcctABC (абстрактный базовый класс), а также классы Brass и BrassPlus (конкретные классы). 
Для облегчения доступа производного класса к данным базового класса в AcctABC имеется несколько защищенных методов. 
Вспомните, что защищенные методы — это методы, которые может вызывать производный класс, однако они не входят в общедоступный интерфейс для объектов производного класса. 
Кроме того, класс AcctABC предоставляет защищенную функцию-член для управления форматированием, которое ранее выполнялось в сторонних функциях. 
В классе AcctABC имеются две чистые виртуальные функции, поэтому он, несомненно, является абстрактным. 
Листинг 13.11. acctabc.h */

// acctabc.h — классы банковских счетов 

#ifndef ACCTABC_H_ 
#define ACCTABC_H_ 

#include <iostream> 
#include <string> 

// Абстрактный базовый класс 
class AcctABC
{
    private:
        std::string fullName;
        long acctNum;
        double balance;
    protected:
        struct Formatting
        {
            std::ios_base::fmtflags flag;
            std::streamsize pr;
        };
        const std::string &FullName() const 
        {
            return fullName;
        }
        long AcctNum() const
        {
            return acctNum;
        }
        Formatting SetFormat() const;
        void Restore(Formatting &f) const;
    public:
        AcctABC(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);
        void Deposit(double amt);
        virtual void Withdraw(double amt) = 0;  // чистая виртуальная функция 
        double Balance() const
        {
            return balance;
        };
        virtual void ViewAcct() const = 0;      // чистая виртуальная функция 
        virtual ~AcctABC() {}
};

// Класс счета Brass Account 
class Brass :public AcctABC
{
    public:
        Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal) { }
        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;
        virtual ~Brass() {}
};

// Класс счета Brass Plus 
class BrassPlus : public AcctABC
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
        BrassPlus(const Brass &ba, double ml = 500, double r = 0.1);
        virtual void ViewAcct() const;
        virtual void Withdraw(double amt);
        void ResetMax(double m)
        {
            maxLoan = m;
        }
        void ResetRate(double r)
        {
            rate = r;
        };
        void ResetOwes()
        {
            owesBank = 0;
        }
};
#endif