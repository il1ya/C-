/* Демонстрация поведения виртуальных методов В листинге 13.9 методы вызываются объектами, а не указателями или ссылками, поэтому программа не использует возможности виртуальных методов. 
Давайте рассмотрим пример, в котором задействованы виртуальные методы. Предположим, что вам требуется управлять смесью счетов Brass и BrassPlus. 
Было бы удобно иметь единственный массив, хранящий набор объектов Brass и BrassPlus, но это невозможно: каждый элемент массива должен относиться к одному и тому же типу, а Brass и BrassPlus — два различных типа. 
Однако можно создать массив указателей на Brass. В этом случае все элементы будут одного типа, но благодаря модели общедоступного наследования указатель на Brass может указывать либо на объект Brass, либо на объект BrassPlus. 
To есть, по сути, у нас имеется способ представления коллекции данных более чем одного типа в едином массиве. Это и есть полиморфизм; в листинге 13.10 показан простой пример. 
Листинг 13.10. usebrass2.срр */
// usebrass2.срр — пример полиморфизма 
// Компилировать вместе с brass.срр 
#include <iostream>
#include <string>
#include "brass.h"
const int CLIENTS = 4;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    Brass *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    for(int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";            // ввод имени клиента 
        getline(cin, temp);
        cout << "Enter client's account number: ";  // ввод номера счета клиента 
        cin >> tempnum;
        cout << "Enter opening balance: $";         // ввод начального баланса 
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "<< "2 for BrassPlus Account: ";  // 1 — Brass Account; 2 — BrassPlus Account 
        while(cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if(kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
            else
            {
                double tmax, trate;
                cout << "Enter the overdraft limit: $";                             // ввод предельного овердрафта 
                cin >> tmax;
                cout << "Enter the interest rate " << "as a decimal fraction: ";    // ввод процентной ставки 
                cin >> trate;
                p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
            }
            while(cin.get() != '\n')
                continue;
    }
    cout << endl;
    for(int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for(int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];  // освобождение памяти 
    }
    cout << "Done.\n";
    return 0;
}
/*
Программа в листинге 13.10 позволяет определять тип добавляемого счета, а затем с помощью операции new создает и инициализирует объект соответствующего типа. 
Как вы должны помнить, вызов getline (с in, temp) читает строку ввода из сіп и сохраняет ее в объекте типа string по имени temp. 
Полиморфизм обеспечивается с помощью следующего кода: 
for (int i = 0; i < CLIENTS; i++) 
{ 
    p_clients[i]->ViewAcct(); 
    cout << endl; 
} 
Если элемент массива указывает на объект Brass, то вызывается Brass:: ViewAcct(), а если на объект BrassPlus — то BrassPlus::ViewAcct(). 
Если бы функция Brass::ViewAcct() была объявлена как виртуальная, то во всех случаях вызывался бы метод Brass:ViewAcct(). 
*/