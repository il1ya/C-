/* В листинге 11.11 показан пересмотренный набор определений. 
Снова обратите внимание на то, что методы используют квалификатор Time::, тогда как дружественные функции — нет. 
Кроме того, поскольку mytime3.h включает iostream и предоставляет объявление using std::ostream, включение файла mytime3.h в 
mytime3 срр предоставляет поддержку ostream в файле реализации. 
Листинг 11.11. mytime3.срр */

// mytime3.cpp — реализация методов класса Time 
#include <iostream>
#include "mytime3.h"
Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}
void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}
void Time::AddHr(int h)
{
    hours += h;
}
void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}
Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time &t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}
Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;

}
std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}
/*
В листинге 11.12 приведен код программы-примера. 
Формально файл usetime3.срр не должен включать заголовочный файл iostream,  поскольку mytime3.h уже включает его. 
Однако, как пользователь класса Time, вы не обязаны знать, какие заголовочные файлы включены в код класса, поэтому в вашей 
ответственности включать эти файлы, если код в них нуждается. 
*/