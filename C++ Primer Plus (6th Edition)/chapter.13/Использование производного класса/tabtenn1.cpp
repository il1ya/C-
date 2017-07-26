/* В листинге 13.5 представлены определения методов для обоих классов. 
Как уже было сказано, можно использовать отдельные файлы, однако проще хранить определения вместе. 
Листинг 13.5. tabtennl.cpp */
#include <iostream>
#include "tabtenn1.h"
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{
}
void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

// Методы RatedPlayer 
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    rating = r;
}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) : TableTennisPlayer(tp), rating(r)
{

}