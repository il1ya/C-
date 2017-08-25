/* *3. Создайте класс с именем time, содержащий три поля типа int, предназначенные для хранения часов, минут и секунд. 
Один из конструкторов класса должен инициализировать поля нулевыми значениями, а другой конструктор — заданным набором значений. 
Создайте метод класса, который будет выводить значения полей на экран в формате 11:59:59, и метод, складывающий значения двух объектов типа time, передаваемых в качестве аргументов.
В функции main() следует создать два инициализированных объекта (по- думайте, должны ли они быть константными) и один неинициализированный объект. 
Затем сложите два инициализированных значения, а результат присвойте третьему объекту и выведите его значение на экран. 
Где возможно, сделайте методы константными. */
#include <iostream>
class Time{
private:
    int hour;
    int minute;
    int second;
public:
    Time() : hour(0), minute(0), second(0){
    }
    Time(int h, int m, int s) : hour(h), minute(m), second(s){
    }
    void show_time() const{
        std::cout << hour << ":" << minute << ":" << second << std::endl;
    }
    void add_time(Time t1, Time t2){
        second = t1.second + t2.second;
        if(second > 59){
            second -= 60; 
            minute++;
        }
        minute += t1.minute + t2.minute;
        if(minute > 59){
            minute -= 60;
            hour++;
        }
        hour += t1.hour + t2.hour;
    }
};
int main()
{
    const Time time1(5, 59, 59);
    const Time time2(4, 30, 30);
    Time time3;
    time3.add_time(time1, time2);
    std::cout << "time3 = ";
    time3.show_time();
    std::cout << std::endl;
    return 0;
}