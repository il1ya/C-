/* Файл реализации 
В листинге 10.5 приведены определения методов для разрабатываемой программы. 
Для предоставления программе необходимого объявления класса в нем включается файл stocklO.h. 
(Вспомните, что помещение имени файла в двойные кавычки вместо угловых скобок заставляет компилятор искать его там же, где расположены файлы исходного кода.) 
Кроме того, в листинге 10.5 включен заголовочный файл iostream для обеспечения поддержки ввода-вывода. 
В коде также демонстрируется использование объявлений using и уточненных имен (наподобие std: :string) для обеспечения доступа к различным определениям из заголовочных файлов. 
В этом файле к предшествующим методам добавлены определения методов конструктора и деструктора. 
Чтобы помочь увидеть момент вызова метода, каждый из них отображает сообщение. Это не является обычным свойством конструкторов и деструкторов, однако позволяет сделать  
наглядным их использование классом. 
Листинг 10.5. stockio.cpp */
// stocklO.cpp — реализация класса Stock с добавленными конструкторами и деструктором 
#include <iostream>
#include "stock10.h"

// Конструкторы (версии с выводом сообщений) 
Stock::Stock() // конструктор по умолчанию 
{
    std::cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = co;
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
// Деструктор класса 
Stock::~Stock()          // деструктор класса, отображающий сообщение 
{
    std::cout << "Bye, " << company << "!\n";
}

// Другие методы 
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
        cout << "Tou can't sell more than you have! " << "Transaction is aborted.\n";
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
    using std::cout;
    using std::ios_base;
    // Установка формата в #.### 
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
        std::streamsize prec = cout.precision(3);
        cout << "Company: " << company << "Shares: " << shares << '\n';
        cout << "Share Price: $" << share_val;
    // Установка формата в #.## 
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';

    // Восстановление исходного формата 
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}