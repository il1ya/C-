/* Разработайте структуру по имени саг, которая будет хранить следующую информацию об автомобиле: название производителя в виде строки в символьном 
массиве или в объекте string, а также год выпуска автомобиля в виде целого числа. 
Напишите программу, которая запросит пользователя, сколько автомобилей необходимо включить в каталог. 
Затем программа должна применить new для создания динамического массива структур саг указанного пользователем размера. 
Далее она должна пригласить пользователя ввести название производителя и год выпуска для наполнения данными каждой структуры в массиве (см. главу 4). 
И, наконец, она должна отобразить содержимое каждой структуры. Пример запуска программы должен выглядеть подобно следующему: 
Сколько автомобилей поместить в каталог? 2 
Автомобиль #1: 
Введите производителя: Hudson Hornet 
Укажите год выпуска: 1952 
Автомобиль #2: 
Введите производителя: Kaiser 
Укажите год выпуска: 1951 
Вот ваша коллекция: 
1952 Hudson Hornet 
1951 Kaiser 
*/

#include <iostream>
#include <string>
using namespace std;
struct car
{
    string name;
    int year;
};
int main(void)
{
    int cr;
    cout << "How many cars placed in the directory?";
    cin >> cr;
    car *cars = new car[cr];
    cout << "Car #1:" << endl;
    cout << "Enter the manufacturer: ";
    cin >> cars -> name;
    cout << "Select Year: ";
    cin >> cars -> year;
    cout << "This is your collection: " << endl;
    cout << cars -> year << " " << cars -> name << endl;
    delete [] cars;
    return 0;
}