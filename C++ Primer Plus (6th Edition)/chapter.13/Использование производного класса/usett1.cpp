// Код в листинге 13.6 создает объекты как класса TableTennisPlayer, так и класса RatedPlayer. 
// Обратите внимание, что объекты обоих классов могут использовать методы Name() и HasTable() класса TableTennisPlayer. 
#include <iostream>
#include "tabtenn1.h"
int main(void)
{
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Chuck", "Blizzard", false);
    RatedPlayer rplayerl(1140, "Tara", "Boomdea", true);
    rplayerl.Name(); // объект производного класса использует метод базового класса 
    if(rplayerl.HasTable())
        cout << ": has a table.\n";
        else
            cout << ": hasn't a table.\n";
    player1.Name();
    if(player1.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";
    cout << "Name: ";
    rplayerl.Name();
    cout << "; Rating: " << rplayerl.Rating() << endl;

    // Инициализация объекта RatedPlayer с помощью объекта TableTennisPlayer 
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;
    return 0;
}