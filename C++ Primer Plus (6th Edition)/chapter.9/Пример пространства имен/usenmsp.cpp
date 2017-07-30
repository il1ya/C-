/*
Наконец, третий файл программы (листинг 9.13) представляет собой файл исходного кода, который использует структуры и функции, объявленные и определенные в пространствах имен. 
В листинге 9.13 показаны методы обеспечения доступа к идентификаторам пространства имен. 
Листинг 9.13. usenmsp.срр */
// usenmsp.срр — использование пространств имен 
#include <iostream>
#include "namesp.h"
void other(void);
void another(void);
int main(void)
{
    using debts::Debt;
    using debts::showDebt;
    Debt golf = { {"Benny", "Goatsniff"}, 120.0};
    showDebt(golf);
    other();
    another();
    return 0;
}
void other(void)
{
    using std::cout;
    using std::endl;
    using namespace debts;
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];
    int i;
    for(i = 0; i < 3; i++)
        getDebt(zippy[i]);
    for(i = 0; i < 3; i++)
        showDebt(zippy[i]);
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
    return;
}
void another(void)
{
    using pers::Person;
    Person collector = { "Milo", "Rightshift" };
    pers::showPerson(collector);
    std::cout << std::endl;
}
/*
Функция main() в листинге 9.13 начинается с двух объявлений using: 
using debts::Debt;      // делает доступным определение структуры Debt 
using debts::showDebt;  // делает доступной функцию showDebt 
Обратите внимание, что в объявлениях using присутствуют только имена. 
Так, во втором примере отсутствует описание типа возвращаемого значения и сигнатуры функции showDebt, а приводится лишь ее имя. 
(Таким образом, если функция была перегружена, одно объявление using обеспечит импортирование всех ее версий.) 
Кроме того, хотя Debt и showDebt() используют тип Person, нет необходимости импортировать какое-либо из имен Person, т.к. в пространстве имен debt уже  
содержится директива using, включающая пространство имен pers. 
Функция other() использует менее желательный способ импорта всего пространства имен с помощью директивы using: 
using namespace debts; // делает доступными для other() все имена из debts и pers 
Поскольку директива using в debts импортирует пространство имен pers, функция other() может использовать тип данных Person и функцию showPerson(). 
Наконец, в функции another() применяется объявление using и операция разрешения контекста для доступа к отдельным именам: 
using pers::Person; 
pers::showPerson(collector); 
Ниже показан результат выполнения программы, представленной в листингах 9.11, 
9.12 и 9.13: 
Goatsniff, Benny: $120 
Glister, Doodles 
Enter first name: Arabella 
Enter last name: Binx 
Enter debt: 100 
Enter first name: Cleve 
Enter last name: Delaproux 
Enter debt: 120 
Enter first name: Eddie 
Enter last name: Fiotox 
Enter debt: 200 
Binx, Arabella: $100 
Delaproux, Cleve: $120 
Fiotox, Eddie: $200 
Total debt: $420 
Rightshift, Milo 
*/