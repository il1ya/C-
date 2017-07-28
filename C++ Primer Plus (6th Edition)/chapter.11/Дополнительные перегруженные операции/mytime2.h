/* Для класса Time имеют смысл и другие операции. Например, может понадобиться вычитать одно время из другого или умножать время на число.
Представим, скажем, перегрузку операций вычитания и умножения. 
Подход здесь тот же, что и для операции сложения: создание методов operator-() и operator*(). 
То есть к объявлению класса добавляются следующие прототипы: 
Time operator-(const Time & t) const; 
Time operator*(double n) const; 
В листинге 11.7 показан новый заголовочный файл. 
Листинг 11.7. mytime2.h */
// mytime2.ty -- класс Time после перегрузки операции 
#ifndef MYTIME2_H_
#define MYTIME2_H_
class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        Time operator+(const Time & t) const;
        Time operator-(const Time & t) const;
        Time operator*(double n) const;
        void Show() const;
};
#endif