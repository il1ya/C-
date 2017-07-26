/*
Новую реализацию счетов Brass и BrassPlus можно использовать таким же образом, как и старую, поскольку у методов класса те же имена и интерфейсы, что и ранее. 
Например, чтобы преобразовать код в листинге 13.10 для применения повой реализации (преобразовать файл usebrass2.срр в usebrass3.срр), необходимо выполнить перечисленные ниже шаги. 
• Связать usebrass2.срр с acctabc.срр вместо brass.срр. 
• Включить acctabc.h вместо brass.h. 
• Заменить 
Brass *p_clients[CLIENTS]; 
на 
AcctABC *p_clients[CLIENTS]; 
Полученный файл приведен в листинге 13.13 с новым именем usebrass3.срр. 
Листинг 13.13. usebrass3.cpp */
// usebrass3.срр - полиморфный пример с использованием абстрактного базового класса 
// Компилировать вместе с acctacb.cpp 

#include <iostream>
#include <string>
#include "acctabc.h"
const int CLIENTS = 4;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    AcctABC *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    for(int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";                // ввод имени клиента 
        getline(cin, temp);
        cout << "Enter client's account number: ";      // ввод номера счета клиента 
        cin >> tempnum;
        cout << "Enter opening balance: $";             // ввод начального баланса 
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "         // 1 — Brass Account; 
             << "2 for Brassplus Account: ";            // 2 -- BrassPlus Account 
             while(cin >> kind &&(kind != '1' && kind != '2'))
                cout << "Enter either 1 or 2: ";
                if(kind == '1')
                    p_clients[i] = new Brass(temp, tempnum, tempbal);
                    else
                    {
                        double tmax, trate;
                        cout << "Enter the overdraft limit: $";                          // ввод предела овердрафта 
                        cin >> tmax;
                        cout << "Enter the interest rate " << "as a decimal fraction: "; // ввод процентной ставки 
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
        delete p_clients[i];            // освобождение памяти 
    }
    cout << "Done.\n";
    return 0;
}

// Эта программа ведет себя точно так же, как и версия без АБК, поэтому при одинаковых входных данных будет получен тот же вывод, что и для листинга 13.10. 
