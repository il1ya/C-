/* В листинге 6.11 иллюстрируется применение enum для определения набора взаимосвязанных констант в операторе switch. 
В общем случае входной поток cin не распознает перечислимые типы (он не может знать, как вы определите их), поэтому программа читает выбор как int. 
Когда оператор switch сравнивает значение int с перечислимой меткой case, он приводит перечисление к типу int. 
Точно также перечисления приводятся к int в проверочном условии цикла while. 
Листинг 6.11. enum.cpp 
enum.cpp -- использование enum 
*/
#include <iostream>
// создание именованный констант для значений 0-6 
enum {red, orange, yellow, green, blue, violet, indigo };
int main(void)
{
    using namespace std;
    cout << "Enter color code (0-6): "; // ввод кода цвета
    int code;
    cin >> code;
    while(code >= red && code <= indigo)
    {
        switch(code)
        {
            case red : cout << "Her lips were red.\n"; break;
            case orange : cout << "Her hair was orange.\n"; break;
            case yellow : cout << "Her shoes were yellow.\n"; break;
            case green : cout << "Her nails were green.\n"; break;
            case blue : cout << "Her sweatsuit was blue.\n"; break;
            case violet : cout << "Her eyes were violet.\n"; break;
            case indigo : cout << "Her mood was indigo.\n"; break;
        }
        cout << "Enter color code (0-6): ";
        cin >> code;
    } 
    cout << "Bye\n";
    return 0;
}