/* 7. Вильям Вингейт (William Wingate) заведует службой анализа рынка пиццы. 
О каждой пицце он записывает следующую информацию: 
• наименование компании — производителя пиццы, которое может состоять из более чем одного слова; 
• диаметр пиццы; 
• вес пиццы. 
• Разработайте структуру, которая может содержать всю эту информацию, и напишите программу, использующую структурную переменную этого типа. 
Программа должна запрашивать у пользователя каждый из перечисленных показателей и затем отображать введенную информацию. Применяйте сіп (или его методы) и сout. */
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
    char company_name[40];
    int pizza_diameter;
    float pizza_weight;
    cout << "Company name: ";
    cin >> company_name;
    cout << "Pizza diameter: ";
    cin >> pizza_diameter;
    cout << "Pizza weight: ";
    cin >> pizza_weight;
    cout << endl << "Company name: " << company_name << endl;
    cout << "Pizza diameter: " << pizza_diameter << endl;
    cout << "Pizza weight: " << pizza_weight << endl;
    return 0;
}