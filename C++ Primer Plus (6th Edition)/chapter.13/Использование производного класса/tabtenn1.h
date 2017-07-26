/*Чтобы использовать производный класс, программе необходимо иметь доступ к объявлениям базового класса. 
В листинге 13.4 оба объявления классов располагаются в одном и том же заголовочном файле. 
Каждому классу можно предоставить собственный заголовочный файл, однако поскольку классы зависят друг от друга, гораздо удобнее хранить объявления классов вместе. 
Листинг 13.4. tabtennl.h */
// tabtennl.h — базовый класс для клуба по настольному теннису 
#ifndef TABTENN1_H_
#define TABTENN1_H_
#include <iostream>
#include <string>
using std::string;
// Простой базовый класс
class TableTennisPlayer
{
    private:
        string firstname;
        string lastname;
        bool hasTable;
    public:
        TableTennisPlayer(const string &fn = "none", const string &ln = "none", bool ht = false);
        void Name() const;
        bool HasTable() const 
        {
            return hasTable;
        }
        void ResetTable(bool v)
        {
            hasTable = v;
        }
};

// Простой производный класс 
class RatedPlayer : public TableTennisPlayer
{
    private:
        unsigned int rating;
    public:
        RatedPlayer(unsigned int r = 0, const string &fn = "none", const string &ln = "none", bool ht = false);
        RatedPlayer(unsigned int r, const TableTennisPlayer &tp);
        unsigned int Rating() const
        {
            return rating;
        }
        void ResetRating(unsigned int r)
        {
            rating = r;
        }
};
#endif