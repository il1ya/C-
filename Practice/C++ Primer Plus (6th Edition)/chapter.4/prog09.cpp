/* 9. Выполните упражнение б, но вместо объявления массива из трех структур CandyBar используйте операцию new для динамического размещения массива. */
#include <iostream>
#include <string>
using namespace std;
struct CandyBar
{
    string name;
    float weight;
    int calories;
};

int main(void)
{
    CandyBar *snak = new CandyBar[3];
    snak[0].name = "Mocha Munch";
    snak[0].weight = 2.3;
    snak[0].calories = 350;

    snak[1].name = "Nyaaa";
    snak[1].weight = 2.6;
    snak[1].calories = 450;

    snak[2].name = "Desu ne";
    snak[2].weight = 3.3;
    snak[2].calories = 550;


    cout << snak[0].name << endl;
    cout << snak[0].weight << endl;
    cout << snak[0].calories << endl;

    cout << endl << snak[1].name << endl;
    cout << snak[1].weight << endl;
    cout << snak[1].calories << endl;

    cout << endl << snak[2].name << endl;
    cout << snak[2].weight << endl;
    cout << snak[2].calories << endl;

    delete [] snak;
    return 0;
}
