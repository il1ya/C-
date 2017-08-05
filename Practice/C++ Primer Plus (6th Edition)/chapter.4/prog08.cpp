/* 8. Выполните упражнение 7, но с применением операции new для размещения структуры в свободном хранилище вместо объявления структурной переменной. 
Кроме того, сделайте так, чтобы программа сначала запрашивала диаметр пиццы, а потом — наименование компании. */
#include <iostream>
struct William_Wingate
{
    char company_name[40];
    int pizza_diameter;
    float pizza_weight;
};
int main(void)
{
    using namespace std;
    William_Wingate *stru = new William_Wingate;
    cout << "Company name: ";
    cin.get(stru -> company_name, 40);
    cout << "Pizza diameter: ";
    cin >> (*stru).pizza_diameter;
    cout << "Pizza weight: ";
    cin >> stru -> pizza_weight;
    cout << endl << "Company name: " << (*stru).company_name << endl;
    cout << "Pizza diameter: " << (*stru).pizza_diameter << endl;
    cout << "Pizza weight: " << (*stru).pizza_weight << endl;
    delete stru;
    return 0;
}