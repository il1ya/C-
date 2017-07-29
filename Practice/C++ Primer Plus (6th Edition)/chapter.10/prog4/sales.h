/* 4.
Выполните упражнение 4 из главы 9, но преобразуйте структуру Sales и ассоциированные с ней функции в класс и методы. 
Замените функцию setSales (Sales &, doublet], int) конструктором. 
Реализуйте интерактивный метод setSales (Sales &), используя конструктор. 
Оставьте класс в пространстве имен SALES. 
*/
#ifndef SALES_H_
#define SALES_H_
const int QUARTERS = 4;
class Sales
{
    private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    public:
        Sales();
        Sales(const double ar[], int n = 4);
        void showSales() const;
        void setSales();
        void setSales(const double [], int);
};
#endif