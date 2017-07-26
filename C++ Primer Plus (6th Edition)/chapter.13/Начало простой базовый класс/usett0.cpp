// Код в листинге 13.3 демонстрирует этот скромный класс в действии. 
// Листинг 13.3. usettO.cpp 
// usettO.cpp — использование базового класса 
#include <iostream>
#include "tabtenn0.h"
int main(void)
{
    using std::cout;
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    player1.Name();
    if(player1.HasTable())
        cout << ": has a table.\n";
        else
            cout << ": hasn't a table.\n";
    player2.Name();
    if(player2.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";
    return 0;
}
/*
Обратите внимание, что в программе используются конструкторы с аргументами в виде строк стиля С: 
TableTennisPlayer playerl("Чак", "Близзард", true); 
TableTennisPlayer player2("Тара", "Бумди", false); 
Однако формальные параметры конструктора объявлены как const-string•&. 
Типы не совпадают, ноу класса string, почти как у класса String из главы 12, имеется конструктор с параметром const char*, который автоматически вызывается 
для создания объекта string, инициализированного строкой в стиле С. Короче говоря, в качестве аргумента конструктора TableTennisPlayer можно использовать как объект string, так и строку в стиле С. 
В первом случае вызывается конструктор string с параметром conststring&, а во втором — конструктор string с  параметром const string*. 
*/