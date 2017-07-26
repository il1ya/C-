// Информация о данных двух классах позволяет построить объявления классов, которые похожи на приведенные в листинге 13.7. 
// Листинг 13.7. brass.h 
// brass.h — классы банковских счетов 
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
// Класс счета Brass Account 
class Brass
{
    private:
        std::string fullName;
        long acctNum;
        double balance;
    public:
        Brass(const std::string &s = "Nullbody", long an =-1, double bal = 0.0);
        void Deposit(double amt);
        virtual void Withdraw(double amt);
        double Balance() const;
        virtual void ViewAcct() const;
        virtual ~Brass() {}
};

// Класс счета Brass Plus 
class BrassPlus : public Brass
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const std::string &s = "Nullbody", long an =-1, double bal = 0.0, double ml = 500, double r = 0.11125);
        BrassPlus(const Brass &ba, double ml= 500, double r = 0.11125);
        virtual void ViewAcct() const;
        virtual void Withdraw(double amt);
        void ResetMax(double m) {maxLoan = m;}
        void ResetRate(double r) {rate = r;}
        void ResetOwes() { owesBank = 0;}
};
#endif
/*
В листинге 13.7 следует обратить внимание на ряд перечисленных ниже моментов. 
• Класс BrassPlus добавляет в класс Brass три новых закрытых члена данных и три новых открытых функции-члена. 
• Оба класса объявляют методы ViewAcct() и Withdraw(); однако вести себя они будут в разных объектах по-разному. 
• При объявлении ViewAcct() и Withdraw() в классе Brass использовано новое ключевое слово virtual. Эти методы теперь называются виртуальными. 
• Класс Brass также объявляет виртуальный деструктор, который ничего не делает. 
*/