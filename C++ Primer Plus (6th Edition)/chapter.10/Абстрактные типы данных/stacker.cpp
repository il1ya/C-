/*
Давайте протестируем стек. Код в листинге 10.12 моделирует деятельность клерка, обрабатывающего заказы на покупки, который берет их со стопки на столе, используя 
характерный для стека алгоритм LIFO (last-in, first-out — последним пришел, первым обслужен). 
Листинг 10.12.stacker.срр */
// stacker.срр -- тестирование класса Stack 
#include <iostream>
#include <cctype>    // или ctype.h
#include "stack.h"
int main()
{
    using namespace std;
    Stack st;       // создание пустого стека 
    char ch;
    unsigned long po;
    // A - добавление заказа, Р - обработка заказа, Q - завершение 
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while(cin >> ch && toupper(ch) != 'Q')
    {
        while(cin.get() != '\n')
            continue;
            if(!isalpha(ch))
            {
                cout << '\a';
                continue;
            }
            switch(ch)
            {
                case 'A':
                case 'a': cout << "Enter a PO number to add: "; // запрос номера заказа 
                          cin >> po;
                          if(st.isfull())
                            cout << "stack already full\n";     // стек уже полон 
                            else
                                st.push(po);
                                break;
                case 'P':
                case 'p': if(st.isempty())
                          cout << "stack already empty\n";
                          else
                          {
                              st.pop(po);
                              cout << "PO #" << po << " popped\n";
                          }
                          break;
            }
            cout << "Please enter A to add a purchase order,\n"
                 << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}
/*
Небольшой цикл while в листинге 10.12, который избавляется от остатка строки, пока что не является совершенно необходимым, однако он пригодится в  
модифицированной версии программы, которая будет рассматриваться в главе 14. */