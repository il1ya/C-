/* Код в листинге 11.20 представляет собой модифицированную версию кода из листинга 11.17 с включением функций преобразования типа. 
Обратите внимание, что обе функции возвращают значение нужного типа, даже несмотря на то, что не имеют объявленного типа возврата. 
Кроме того, определение преобразования в int округляет возвращаемое значение к ближайшему целому, а не усекает его. 
Например, если pounds равно 114.4, то pounds + 0.5 равно 114.9, a int(114.9) равен 114. 
Но если pounds равно 114.6, то pounds + 0.5 равно 115.1, a int(115.1) равно 115. 
Листинг 11.20. stonewtl.срр */
// stonewtl.срр — методы класса Stonewt с функциями преобразования 
#include <iostream>
using std::cout;
#include "stonewt1.h"
// Конструирует объект Stonewt из значения типа double 
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn; // целочисленное деление 
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}
// Конструирует объект Stonewt из стоунов и значения типа double 
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt() // конструктор по умолчанию, wt = 0 
{
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt() // деструктор
{

}
// Отображение веса в стоунах 
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}
// Отображение веса в фунтах 
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}
// Функции преобразования 
Stonewt::operator int() const
{
    return int(pounds + 0.5);
}
Stonewt::operator double() const
{
    return pounds;
}