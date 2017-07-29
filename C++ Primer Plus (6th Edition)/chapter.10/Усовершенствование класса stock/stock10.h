/*
Теперь необходимо включить конструкторы и деструктор в определение класса и методов. 
Учитывая важность добавления конструкторов, изменим имя stockOO.h на stocklO.h. 
Методы класса будут находиться в файле по имени stocklO.cpp. 
И, наконец, программа, использующая эти ресурсы, будет помещена в третий файл — usestok2.срр. 
Заголовочный файл 
В листинге 10.4 показан заголовочный файл программы stock. К исходному объявлению класса здесь добавлены прототипы функций конструктора и деструктора. 
Также он отличается отсутствием функции acquire(), которая более не нужна, поскольку класс имеет конструкторы. 
В файле используется также прием #ifndef, описанный в главе 9, для защиты от многократного включения заголовочного файла. 
Листинг 10.4.stocklO.h */
// stocklO.h -- объявление класса Stock с добавленными конструкторами и деструктором 
#ifndef STOCK10_H_
#define STOCK00_H_
#include <string>

class Stock
{
    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }
    public:
        // Два конструктора 
        Stock(); // конструктор по умолчанию 
        Stock(const std::string & co, long n = 0, double pr = 0.0);
        ~Stock(); // деструктор 
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
};
#endif