/*
Код в листинге 17.19 применяет эти методы для создания и чтения бинарного файла. 
По форме эта программа подобна приведенной в листинге 17.18, но использует write() и read() вместо операции вставки и метода get(). Она также применяет манипуляторы для форматирования экранного вывода. 
Листинг 17.19. binary.срр */
// binary.срр — бинарный файловый ввод-вывод 
#include <iostream>     // для большинства систем не требуется 
#include <fstream>
#include <iomanip>
#include <cstdlib>      // для exit() 

inline void eatline()
{
    while(std::cin.get() != '\n')
    continue;
}
struct planet
{
    char name[20];      // название планеты 
    double population;  // население 
    double g;           // ускорение свободного падения 
};

const char *file = "planets.dat";

int main()
{
    using namespace std;
    planet pl;
    cout << fixed << right;

    // Отображение начального содержимого 
    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary); // бинарный файл 
    // Примечание: некоторые системы не принимают режим ios_base:rbinary 
    if(fin.is_open())
    {
        cout << "Here are the current contents of the " << file << " file:\n";
        while(fin.read((char*) &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    // Добавление новых данных 
    ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
    // Примечание: некоторые системы не принимают режим ios:ibinary 
    if(!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output:\n";
        exit(EXIT_FAILURE);
    }
    cout << "Enter planet name (enter a blank line to quit):\n";        // ввод названия планеты 
    cin.get(pl.name, 20);
    while(pl.name[0] != '\0')
    {
        eatline();
        cout << "Enter planetary population: ";                         // ввод населения 
        cin >> pl.population;
        cout << "Enter planet's accelaration of gravity: ";
                // Ввод ускорения свободного падения 
        cin >> pl.g;
        eatline();
        fout.write((char *) &pl, sizeof pl);
        cout << "Enter planet name (enter a blank line to quit):\n";    // ввод названия планеты 
        cin.get(pl.name, 20);
    }
    fout.close();

    // Отображение измененного файла 
    fin.clear();        // не обязательно в некоторых реализациях, но это не помешает 
    fin.open(file, ios_base::in | ios_base::binary);
    if(fin.is_open())
    {
        cout << "Here are the new contents of the " << file << " file:\n";
        while(fin.read((char *) &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    cout << "Done.\n";
    return 0;
}
/*
Вы уже видели основные возможности этой программы, но задержимся на ней еще немного. 
Программа использует следующий код (в форме встроенной функции eatlene()) после чтения значения g для планеты: 
while(std::cin.get () != '\n') continue; 
Он считывает и отбрасывает ввод вплоть до символа новой строки. Рассмотрим следующий оператор ввода в цикле: 
cin.get(pi.name, 20); 
Если бы символ новой строки остался на своем месте, этот оператор читал бы его как пустую строку, завершая цикл. 
Вы можете спросить: нельзя ли воспользоваться объектом string вместо массива символов для члена name структуры planet? 
Ответ отрицателен — по крайней мере, без серьезных изменений в проектном решении. Проблема в том, что объект string в действительности не содержит в себе строку. 
Вместо этого он содержит указатель на область памяти, где хранится строка. Поэтому если скопировать структуру в файл, то будут скопированы не данные строки, а адрес области ее хранения в памяти. 
При повторном запуске программы этот адрес утрачивает смысл. 
*/