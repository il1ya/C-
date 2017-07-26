// Листинг 13.2. tabtennO.cpp 
// tabtennO.cpp -- методы простого базового класса 
#include "tabtenn0.h"
#include <iostream>
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{

}
void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}
/* 
Класс TableTennisPlayer просто содержит имена игроков, а также наличие у них столов. Здесь стоит отметить пару моментов. 
Во-первых, для хранения имен в классе используется стандартный класс string. Он удобнее, гибче и надежнее, чем символьный массив. И он профессиональнее класса String из главы 12. 
Во-вторых, в конструкторе задействован список инициализаторов членов.  
Инициализацию можно выполнить и так: 
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht)
{
    firstname = fn;
    lastname = ln; 
    hasTable = ht;
}

Правда, при таком подходе сначала вызывается конструктор string по умолчанию для firstname, а затем выполняется операция присваивания для string, которая заносит в firstname значение fп. 
Синтаксис списка инициализаторов членов экономит один шаг: он просто инициализирует член firstname значением fn с помощью конструктора копирования string. 
*/