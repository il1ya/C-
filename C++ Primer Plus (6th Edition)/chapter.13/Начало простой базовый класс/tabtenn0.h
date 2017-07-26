/*Когда один класс наследуется от другого, исходный класс называется базовым классом, а наследующий — производным классом. 
Чтобы проиллюстрировать прием наследования, начнем с разработки базового класса. 
Предположим, клуб "Webtown Social Club" решил вести учет своих членов, играющих в настольный теннис. 
Как ведущий программист клуба, вы написали простой класс TableTennisPlayer, который показан в листингах 13.1 и 13.2. 
Листинг 13.1. tabtennO.h */
// tabtennO.h — базовый класс для клуба по настольному теннису 
#ifndef TABTENNO_H_
#define TABTENNO_H_

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
#endif