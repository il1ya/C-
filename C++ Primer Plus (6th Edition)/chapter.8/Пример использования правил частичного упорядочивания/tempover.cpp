/*
Рассмотрим завершенную программу, которая использует правила частичного упорядочивания для идентификации применяемого определения шаблона. 
Листинг 8.14 содержит два определения шаблонов, отображающих содержимое массива. Первое определение (шаблон А) предполагает, что передаваемый в качестве аргумента массив содержит данные, которые следует отобразить. 
Второе определение (шаблон В) предполагает, что элементы массива являются указателями на отображаемые данные. 
Листинг8.14.tempover.cpp */
// tempover.срр — перегрузка шаблонов 
#include <iostream>

template <typename T> // шаблон А 
void ShowArray(T arr[], int n);

template <typename T> // шаблон В 
void ShowArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main(void)
{
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = 
    {
        {"ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double *pd[3];
    // Установка указателей на члены amount структур в mr_E 
    for(int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
        cout << "Listing Mr.E's counts of things:\n'";
        // things - массив значений int 
        ShowArray(things, 6); // использует шаблон А 
        cout << "Listing Mr. E's debts:\n";
        // pd - массив указателей на double 
        ShowArray(pd, 3); // использует шаблон В (более специализированный) 
        return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "template A\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
        cout << endl;
}

template <typename T>
void ShowArray(T *arr[], int n)
{
    using namespace std;
    cout << "template B\n";
    for(int i = 0; i < n; i++)
        cout << *arr[i] << ' ';
        cout << endl;
}