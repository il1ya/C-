/* 4. Напишите оператор, который присваивает переменной even сумму первого и последнего элементов массива из вопроса 3. 
int array[5] = { 5, 7, 11, 13, 15 }; */
#include <iostream>

struct fish
{
    char view[20];
    float weight;
    double length;
};

int main(void)
{
    using namespace std;
    fish fishi =
    {
        "crucian", 10, 2.20
    };

    cout << fishi.view << endl << fishi.weight << endl << fishi.length << endl;
    return 0;
}