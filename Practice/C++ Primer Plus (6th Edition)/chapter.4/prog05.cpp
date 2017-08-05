/* 5. 
Структура CandyBar содержит три члена. Первый из них хранит название коробки конфет. 
Второй — ее вес (который может иметь дробную часть), а третий — число calories (целое значение). 
Напишите программу, объявляющую эту структуру и создающую переменную типа CandyBar по имени snack, инициализируя ее члены значениями "Mocha Munch", 2.3 и 350, соответственно. 
Инициализация должна быть частью объявления snack. И, наконец, программа должна отобразить содержимое этой переменной. */

#include <iostream>
struct CandyBar
{
    char name[20];
    float weight;
    int calories;
};
int main(void)
{
    using namespace std;
    CandyBar snak = 
    {
        "Mocha Munch", 
        2.3,
        350
    };
    cout << snak.name << endl;
    cout << snak.weight << endl;
    cout << snak.calories << endl;
    return 0;
}