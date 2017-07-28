/* В листинге 11.10 показано модифицированное определение класса с включением двух дружественных функций operator*() и operator« (). 
Первая из этих функций реализована здесь как встроенная, поскольку ее код очень короткий. 
(Когда определение одновременно является прототипом, как в этом случае, применяется префикс friend.) 
На заметку! 
Ключевое слово friend используется только в прототипе, представленном в объявлении класса. 
В определении функции оно указывается, только если не присутствует в самом прототипе. 
Листинг 11.10. mytime3.h */
// mytime3.h -- класс Time с друзьями 
#ifndef MYTIME2_H_
#define MYTIME2_H_
#include <iostream>
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
        friend Time operator*(double m, const Time & t)
            {return t * m; } // встроенное определение
        friend std::ostream & operator << (std::ostream & os, const Time & t);
};
#endif