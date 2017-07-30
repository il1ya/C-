/*
Второй файл этого примера (листинг 9.12) следует обычному шаблону, при котором файл исходного кода содержит определения для прототипов функций из заголовочного файла. 
Имена функций, объявленные в пространстве имен, имеют область видимости пространства имен, поэтому определения должны находиться в том же самом пространстве имен, что и объявления. 
Это тот случай, когда открытая природа пространства имен становится удобной. Исходные пространства имен включаются с помощью файла namesp.h (листинг 9.11). 
Затем файл добавляет определения функций к двум пространствам имен, как показано в листинге 9.12. 
Кроме того, в файле namesp.cpp демонстрируется обеспечение доступа к элементам пространства имен std с помощью объявления using и операции разрешения контекста. 
Листинг 9.12. namesp.cpp */
// namesp.cpp -- пространства имен 
#include <iostream>
#include "namesp.h"

namespace pers
{
    using std::cout;
    using std::cin;
    void getPerson(Person & rp)
    {
        cout << "Enter first name: "; // ввод имени
        cin >> rp.fname;
        cout << "Enter last name: ";  // ввод фамилии 
        cin >> rp.lname;
    }
    void showPerson(const Person & rp)
    {
        std::cout << rp.lname << ", " << rp.fname;
    }
}

namespace debts
{
    void getDebt(Debt & rd)
    {
        getPerson(rd.name);
        std::cout << "Enter debt: "; // ввод суммы задолженности 
        std::cin >> rd.amount;
    }
    void showDebt(const Debt & rd)
    {
        showPerson(rd.name);
        std::cout << ": $" << rd.amount << std::endl;
    }
    double sumDebts(const Debt ar[], int n)
    {
        double total = 0;
        for(int i = 0; i < n; i++)
            total += ar[i].amount;
            return total;
    }
}