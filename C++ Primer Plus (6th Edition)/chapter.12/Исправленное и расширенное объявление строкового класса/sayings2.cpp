/* Использование указателей на объекты 
В программах на C++ часто применяются указатели на объекты, поэтому давайте немного попрактикуемся в этом вопросе. 
В листинге 12.6 используются значения индексов массива для отслеживания самой короткой строки и первой строки в алфавитном порядке. 
Другим примером может послужить применение указателей для указания на текущих лидеров в данных категориях. 
В листинге 12.7 реализован этот подход с использованием двух указателей на объекты String. 
Первоначально указатель shortest указывает на первый объект в массиве. 
Всякий раз, когда программа находит объект с более короткой строкой, она устанавливает указатель shortest на этот объект. 
Аналогично, указатель first отслеживает самую первую в алфавитном порядке строку. 
Обратите внимание, что эти два указателя не создают новые объекты, они просто указывают на существующие объекты. 
Поэтому они не требуют применения операции new для выделения дополнительной памяти. 
Для разнообразия программа в листинге 12.7 использует указатель, который отслеживает новые объекты: 
String * favorite = new String(sayings[choice]); 
Здесь указатель favorite обеспечивает доступ к безымянному объекту, созданному операцией new. 
Этот синтаксис означает инициализацию нового объекта String с помощью объекта sayings[choice]. 
При этом вызывается конструктор копирования, поскольку тип аргумента для конструктора копирования (const String &) соответствует инициализирующему значению (sayings [choice]). 
Для выбора случайных значений в программе используются функции srand(), rand() и time(). 
Листинг 12.7. sayings2.срр */
// sayings2.cpp — использование указателей на объекты 
// компилировать вместе с stringl.cpp 
#include <iostream> 
#include <cstdlib>  // (или stdlib.h) для rand(), srand() 
#include <ctime>    // (или time.h) для time() 
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
    using namespace std;
    String name;
    cout << "Hi, what's your name?\n>> ";
    cin >> name;
    cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n"; // ввод пословиц 
    String sayings[ArSize];
    char temp[MaxLen];                                                                             // временное хранилище для строки 
    int i;
    for(i = 0; i < ArSize; i++)
    {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while(cin && cin.get() != '\n')
            continue;
        if(!cin || temp[0] == '\0')  // пустая строка? 
            break;                   // i не инкрементируется 
        else
            sayings[i] = temp;       // перегруженное присваивание 
    }
    int total = i;      // общее количество прочитанных строк 
    if(total > 0)
    {
        cout << "Here are your sayings:\n"; // вывод пословиц
        for(i = 0; i < total; i++)
        cout << sayings[i] << "\n";
        // Указатели для отслеживания кратчайшей и первой строки 
        String *shortest = &sayings[0]; // ицициализация первым объектом 
        String *first = &sayings[0];
        for(i = 1; i < total; i++)
        {
            if(sayings[i].length() < shortest -> length())
                shortest = &sayings[i];
            if(sayings[i] < *first)         // сравнение значений 
                first = &sayings[i];        // присваивание адреса 
        }
        cout << "sShortest saying:\n" << * shortest << endl;
            // вывод кратчайшей пословицы
        cout << "First alphabetically:\n" << *first << endl;
            // вывод первой пословицы по алфавиту 
        srand(time(0));
        int choice = rand() % total; // выбор случайного индекса 
        // Создание и инициализация объекта String с помощью new 
        String * favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;
            // вывод любимой пословицы 
        delete favorite;
    }
    else
        cout << "Not much to say, eh?\n";   // ничего не было введено 
        cout << "Bye.\n";
        return 0;
}