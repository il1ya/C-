/*
Использование шаблонного класса 
Просто включение шаблона в программу не генерирует шаблонный класс — необходимо запросить создание экземпляра. 
Для этого потребуется объявить объект с типом шаблонного класса и заменить имя обобщенного типа конкретным типом. 
Например, ниже показано создание двух стеков: одного для хранения значений int, а другого — для объектов string. 

Stack<int> kernels;     // создание стека для значений int 
Stack<string> colonels; // создание стека для объектов string 

Встретив эти два определения, компилятор на основе шаблона Stack<Type> сгенерирует два различных объявления класса и два разных набора методов класса. 
Объявление класса Stack<int> заменит все Туре на int, а объявление класса Stack<string> заменит все Туре на string. 
Конечно, используемые алгоритмы должны согласоваться с типами. К примеру, класс Stack предполагает, что возможно присваивание одних элементов другим. 
Это присваивание справедливо для базовых типов, структур и классов (если не сделать операцию присваивания закрытой), но не для массивов. 

Идентификаторы обобщенных типов, такие как Туре в нашем примере, называются параметрами типа — т.е. 
они действуют примерно как переменные, но вместо присваивания числового значения параметру типа присваивается тип. 
Поэтому в объявлении kernels параметр Туре имеет значение int. Учтите, что требуемый тип необходимо указать явно. 
В этом заключается отличие от обычных шаблонных функций — в них компилятор может использовать типы аргументов для определения вида функции, которую нужно сгенерировать: 
template <class T> 
void simple (T t) { cout << t << '\n'; } 
simple(2);      // генерирует void simple(int) 
simple("two");  // генерирует void simple(const char *) 

В листинге 14.14 приведена первоначальная программа тестирования работы стека (см. листинг 10.12),
но приспособленная для использования строкового представления идентификаторов заказов вместо значений unsigned long. 
Листинг 14.14. stacktem.cpp */
// stacktem.cpp — тестирование шаблонного класса стека 

#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using std::cin;
using std::cout;

int main()
{
    Stack<std::string> st;  // создание пустого стека 
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order, \n"  // A - добавить заказ, 
         << "P to process a PO, or Q to quit.\n";         // P - обработать заказ, Q - выйти 
    while(cin >> ch && std::toupper(ch) != 'Q')
    {
        while(cin.get() != '\n')
            continue;
        if(!std::isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                        // Ввод номера добавляемого заказа 
                      cin >> po;
                      if(st.isfull())
                        cout << "stack alredy full\n";          // стек уже полон 
                      else
                        st.push(po);
                        break;
            case 'P':
            case 'p': if(st.isempty())
                        cout << "stack already empty\n";        // стек уже пуст
                      else
                      {
                          st.pop(po);
                          cout << "PO #" << po << " popped\n";  // заказ извлечен 
                          break;
                      }
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}