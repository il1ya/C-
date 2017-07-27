/* Короткая программа, приведенная в листинге 12.6, проверяет класс String, позволяя ввести несколько строк. 
Программа запрашивает у пользователя ввод поговорок, помещает строки в объекты String, выводит их и выдает отчет о том, какая строка самая короткая, и какая идет первой в алфавитном порядке. 
Листинг 12.6. sayings 1.срр */
// sayingsl.cpp — использование расширенного класса String 
// компилировать вместе с stringl.cpp 
#include <iostream> 
#include "string1.h" 
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    String name;
    cout << "Hi, what's your name?\n>> "; // ввод имени 
    cin >> name;
    cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n"; // ввод поговорки 
    String sayings[ArSize]; // массив объектов 
    char temp[MaxLen];      // временное хранилище для строки 
    int i;
    for(i = 0; i < ArSize; i++)
    {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while(cin && cin.get() != '\n')
            continue;
            if(!cin || temp[0] == '\0')     // пустая строка? 
            break;
            else
            sayings[i] = temp;              // перегруженное присваивание 
    }
    int total = i;  // общее количество прочитанных строк 
    if(total > 0)
    {
        cout << "Here are your sayings:\n"; // вывод поговорок 
        for(i = 0; i < total; i++)
            cout << sayings[i][0] << ": " << sayings[i] << endl;
            int shortest = 0;
            int first = 0;
            for(i = 0; i < total; i++)
            {
                if(sayings[i].length() < sayings[shortest].length())
                    shortest = i;
                if(sayings[i] < sayings[first])
                    first = i;
            }
            cout << "Shortest saying:\n" << sayings[shortest] << endl;
                // Самая короткая поговорка 
            cout << "First alphabetically:\n" << sayings[first] << endl;
                // Первая по алфавиту 
            cout << "This program used " << String::HowMany() << " String objects. Bye.\n";
                // Количество используемых объектов String 
    }
    else
        cout << "No input! Bye.\n"; // ничего не было введено 
    return 0;
}
/*
На заметку! 
Более старые версии get (char *, int) не устанавливают значение false при чтении пустой строки. 
В таких версиях при вводе пустой строки первым символом в строке считается нулевой символ. 
В данном примере используется следующий код: 
if (!cin || temp[0] == '\0') // пустая строка? 
break;                      // і не инкрементируется 
Если реализация поддерживает текущий стандарт C++, то пустая строка обнаруживается при первой проверке в операторе if, а в более старых реализациях она обнаруживается при второй проверке.
*/
/*
Программа из листинга 12.6 предлагает пользователю ввести до 10 поговорок. 
Каждая поговорка считывается во временный символьный массив, а затем копируется в объект String. 
Если пользователь вводит пустую строку, оператор break завершает цикл ввода. 
После вывода введенных данных программа использует функции-члены length() и operator<() для нахождения самой короткой и самой первой в  алфавитном порядке строки. 
Программа также применяет операцию индексации ([]) для того, чтобы разместить перед каждой поговоркой ее начальный символ. 
*/

