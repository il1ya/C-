/* Чтобы добавить функции, которые преобразуют объект stonewt в типы int и double, необходимо дополнить объявление класса следующими прототипами: 
operator int(); 
operator double(); 
В листинге 11.19 представлена модифицированная версия объявления класса. 
Листинг 11.19. stonewtl.h */
// stonewtl.h -- усовершенствованное определение класса Stonewt 
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
    private:
        enum { Lbs_per_stn = 14};   // фунтов на стоун 
        int stone;                  // полных стоунов 
        double pds_left;            // дробное число фунтов
        double pounds;              // общий вес в фунтах
    public:
        Stonewt(double lbs);            // конструктор для значения в фунтах 
        Stonewt(int stn, double lbs);   // конструктор для значения в стоунах и фунтах 
        Stonewt();                      // конструктор по умолчанию 
        ~Stonewt();
        void show_lbs() const;          // отображение веса в формате фунтов 
        void show_stn() const;          // отображение веса в формате стоунов 
        // Функции преобразования
        operator int() const;
        operator double() const;
};
#endif