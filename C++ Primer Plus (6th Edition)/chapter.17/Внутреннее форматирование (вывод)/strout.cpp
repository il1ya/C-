/*
Применение str() "замораживает" объект, и дальнейшая запись в него становится невозможной.
В листинге 17.21 приведен краткий пример внутреннего форматирования. 
Листинг 17.21. strout.cpp */
// strout.cpp — внутреннее форматирование (вывод) 
#include <iostream>
#include <sstream>
#include <string>
int main()
{
    using namespace std;
    ostringstream outstr;                    // управляет строковым потоком 
    string hdisk;
    cout << "What's the name of your hard disk? ";
    getline(cin, hdisk);
    int cap;
    cout << "What's its capacity in GB? ";
    cin >> cap;

    // Запись форматированной информации в строковый поток 
    outstr << "The hard disk " << hdisk << " has a capacity of " << cap << " gigabytes.\n";
    string result = outstr.str();           // сохранение результата 
    cout << result;                         // отображение содержимого 
    return 0;
}