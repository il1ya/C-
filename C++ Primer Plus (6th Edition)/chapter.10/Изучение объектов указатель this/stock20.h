/*
Тот факт, что возвращаемое значение представляет собой ссылку, означает, что возвращаемый объект является тем же самым объектом, который вызвал данный метод, а не копией, переданной механизмом возврата. 
В листинге 10.7 приведен новый заголовочный файл. 
Листинг 10.7. stock20.h */ 
// stock20.h — дополненная версия 
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>
class Stock
{
    private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val;}
    public:
    Stock();    // Конструктор по умолчанию
    Stock(const std:: string & co, long n = 0, double pr = 0.0);
    ~Stock();   // деструктор
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show()const;
    const Stock & topval(const Stock & s) const;
};
#endif