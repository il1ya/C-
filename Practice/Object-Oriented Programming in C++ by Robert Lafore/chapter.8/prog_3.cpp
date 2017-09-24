/*3. 
Модифицируйте класс time из упражнения 3 главы 6 так, чтобы вместо метода add_time() можно было использовать операцию + для складывания двух значений времени. 
Напишите программу для проверки класса. */
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
    Time operator+(Time t){
        int s = second + t.second;
        int m = minute + t.minute;
        int h = hour  + t.hour;
        if(s > 59){
            s -= 60;
            m++;
        }
        if(m > 59){
            m -= 60;
            h++;
        }
        return Time(h, m, s);
    }
};
int main()
{
    Time time1(5, 59, 59);
    Time time2(4, 30, 30);
    Time time3;
    time3 = time1 + time2;
    /*
    time3.add_time(time1, time2); */
    std::cout << "time3 = ";
    time3.show_time();
    std::cout << std::endl;
    return 0;
}