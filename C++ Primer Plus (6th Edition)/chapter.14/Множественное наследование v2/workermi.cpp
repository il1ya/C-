// Листинг 14.11. workermi.cpp 
// workermi.cpp — методы классов работников с множественным наследованием 
#include "workermi.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Методы Worker 
Worker::~Worker() {}

// Защищенные методы 
void Worker::Data() const
{
    cout << "Name: " << fullname << "\n";       // имя и фамилия 
    cout << "Employee ID: " << id << "\n";      // идентификатор 
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Enter worker's ID: ";          // ввод идентификатора работчика 
    cin >> id;
    while(cin.get() != '\n')
        continue;
}
// Методы Waiter 
void Waiter::Set()
{
        cout << "Enter waiter's name: ";   // ввод имени и фамилии работчика 
        Worker::Get();
        Get();
}

void Waiter::Show() const
{
    cout << "Category: waiter\n";          // категория: официант 
    Worker::Data();
    Data();
}

// Защищенные методы
void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;   // индекс элегантности 
}

void Waiter::Get()
{
        cout << "Enter waiter's panache rating: ";
            // Ввод индекса элегантности официанта 
        cin >> panache;
        while(cin.get() != '\n')
            continue;
}

// Методы Singer 
const char *Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
    cout << "Enter singer's name: ";   // Ввод имени и фамилии певца 
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: singer\n";                       // категория: певец 
    Worker::Data();
    Data();
}

// Защищенные методы
void Singer::Data() const
{
    cout << "Vocal range: " << pv[voice] << endl;      // Вокальный диапазон 
}

void Singer::Get()
{
        cout << "Enter number for singer's vocal range:\n";
            // Ввод номера вокального диапазона певца 
            int i;
            for(i = 0; i < Vtypes; i++)
            {
                cout << i << ": " << pv[i] << " ";
                if(i % 4 == 3)
                    cout << endl;
            }
            if(i % 4 != 0)
                cout << endl;
            cin >> voice;
            while(cin.get() != '\n')
                continue;
}

// Методы SingingWaiter 
void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}
void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}
void SingingWaiter::Set()
{
    cout << "Enter singing waiter's name: ";
                // Ввод имени и фамилии поющего официанта 
    Worker::Get();
    Get();
}
void SingingWaiter::Show() const
{
    cout << "Category: singer\n";                   // категория: певец 
    Worker::Data();
    Data();
}