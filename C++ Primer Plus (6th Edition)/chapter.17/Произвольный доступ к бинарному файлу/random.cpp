/*И, наконец, чтобы отобразить измененное содержимое файла, программа применяет seekg(), чтобы сбросить указатель файла на начало. 
Полный код программы приведен в листинге 17.20. Не забудьте, что в ней предполагается, что файл planets.dat, созданный с помощью программы binary.срр, доступен. 
На заметку! 
Чем старше реализация, тем более вероятно, что она не соответствует стандарту C++. Некоторые системы не распознают флаг binary, манипуляторы fixed и right, а также ios_base. 
Листинг 17.20. random.срр */
// random.срр — произвольный доступ к бинарному файлу 
#include <iostream>     // для большинства систем не требуется 
#include <fstream>
#include <iomanip>
#include <cstdlib>      // для exit() 
const int LIM = 20;
struct planet{
    char name[LIM];     // название планеты 
    double population;  // население 
    double g;           // ускорение свободного падения 
};

const char *file = "planets.dat";       // ПРЕДПОЛАГАЕТСЯ, ЧТО СУЩЕСТВУЕТ (пример binary.срр) 
inline void eatline()
{
    while(std::cin.get() != '\n')
        continue;
}

int main()
{
    using namespace std;
    planet pl;
    cout << fixed;

    // Отображение начального содержимого 
    fstream finout;     // потоки чтения и записи 
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
    // Примечание: некоторые системы Unix требуют опустить | ios:ibinary 
    int ch = 0;
    if(finout.is_open())
    {
        finout.seekg(0);        // перейти в начало 
        cout << "Here are the current contents of the " << file << " file:\n";
        while(finout.read((char *) &pl, sizeof pl))
        {
            cout << ch++ << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
        }
        if(finout.eof())
            finout.clear();     // очистить флаг eof 
        else{
            cerr << "Error in reading " << file << ".\n";
            exit(EXIT_FAILURE);
        }
    }
    else{
        cerr << file << " could not be opened -- bye.\n";
        exit(EXIT_FAILURE);
    }
    // Изменить запись 
    cout << "Enter the record number you wish to change: ";
    long rec;
    cin >> rec;
    eatline();      // избавление от символов новой строки  
    if(rec < 0 || rec >= ch)
    {
        cerr << "Invalid record number -- bye\n";
        exit(EXIT_FAILURE);
    }
    streampos place = rec * sizeof pl;      // преобразование в тип streampos 
    finout.seekg(place);                    // произвольный доступ 
    if(finout.fail())
    {
        cerr << "Error on attempted seek\n";
        exit(EXIT_FAILURE);
    }
    finout.read((char *) &pl, sizeof pl);
    cout << "Your selection:\n";
    cout << rec << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
    if(finout.eof())
        finout.clear();     // очистить флаг eof 
    cout << "Enter planet name: ";
    cin.get(pl.name, LIM);
    eatline();
    cout << "Enter planetary population: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;
    finout.seekp(place);                // вернуться назад 
    finout.write((char *) &pl, sizeof pl) << flush;
    if(finout.fail())
    {
        cerr << "Error on attempted write\n";
        exit(EXIT_FAILURE);
    }
    // Отображение измененного файла 
    ch = 0;
    finout.seekg(0);                    // перейти в начало файла 
    cout << "Here are the new contents of the " << file << " file:\n";
    while(finout.read((char *) &pl, sizeof pl))
    {
        cout << ch++ << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
    }
    finout.close();
    cout << "Done.\n";
    return 0;
}
/*
Используя методики, представленные в этой программе, ее можно расширить так, чтобы она позволяла добавлять новую информацию и удалять записи. 
Если вы намерены расширить программу, целесообразно реорганизовать ее, применив классы и функции. 
Например, структуру planet можно (было бы преобразовать в определение класса, затем перегрузить операцию вставки « так, чтобы выражение cout « pi  
отображало члены данных класса сформатированными, как в приведенном примере. 
К тому же приведенный пример не заботится о проверке допустимости ввода, поэтому можно было бы добавить код, проверяющий допустимость вводимых числовых  данных, когда это необходимо. 
*/