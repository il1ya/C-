/*
5. Взяв в качестве основы структуру из упражнения 5 главы 4, создайте класс date. 
Его данные должны размещаться в трех полях типа int: month, day и year. 
Метод класса getdate() должен принимать значение для объекта в формате 12/31/02, а метод showdate() — выводить данные на экран.
*/
#include <iostream>
class Date{
    private:
        int month;
        int day;
        int year;
    public:
        Date() : month(0), day(0), year(0){
        }
        Date(int m, int d, int y) : month(m), day(d), year(y){
        }
        void getdate(){
            std::cout << "Month ";
            std::cin >> month;
            std::cout << "Day ";
            std::cin >> day;
            std::cout << "Year ";
            std::cin >> year;
        }
        void showdate() const{
            std::cout << month << "/" << day << "/" << year << std::endl;
        }
};
int main()
{
    Date pr1;
    pr1.getdate();
    pr1.showdate();
    return 0;
}