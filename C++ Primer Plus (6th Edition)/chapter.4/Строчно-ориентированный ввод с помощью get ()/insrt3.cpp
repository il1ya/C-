/* Такую возможность обеспечивает то, что cin.get (name, ArSize) возвращает объект cin, который затем используется в качестве объекта, вызывающего функцию get(). 
Аналогично приведенный ниже оператор читает две следующих друг за другом строки в массивы namel и name2, что эквивалентно двум отдельным вызовам 
cin.getline(): 
cin.getline(namel, ArSize).getline(name2, ArSize); 
В листинге 4.5 применяется конкатенация. В главе 11 вы узнаете о том, как включить это средство в собственные определения классов. */
// Листинг 4.5. insrt3.срр 
// insrt3.cpp -- чтение более одного слова с помощью get() и get() 
#include <iostream>
int main(void)
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";  // запрос имени 
    cin.get(name, ArSize).get();   // читать строку и символ новой строки 
    cout << "Enter your favorite dessert:\n";  // запрос любимого десерта 
    cin.get(dessert, ArSize).get();
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}
