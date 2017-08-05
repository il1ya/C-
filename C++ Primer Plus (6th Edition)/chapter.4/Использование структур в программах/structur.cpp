/* Теперь, когда раскрыты некоторые из основных свойств структур, пришло время собрать все идеи вместе в программе, использующей переменные-структуры. 
В листинге 4.11 представлен пример со структурой. Также в нем показано, как ее инициализировать. 
Листинг 4.11. structur.срр */
// structur.срр -- простая структура 
#include <iostream>
struct inflatable   // объявление структуры 
{
    char name[20];
    float volume;
    double price;
};

int main(void)
{
    using namespace std;
    inflatable quest =
    {
        "Glorious Gloria",  // значение name 
        1.88,       // значение volume 
        29.99       // значение value 
    }; // guest — структурная переменная типа inflatable 
    // Инициализация указанными значениями 
    inflatable pal = 
    {
        "Audacious Arthur",
        3.12,
        32.99
    }; // pal — вторая переменная типа inflatable 
    // ПРИМЕЧАНИЕ: некоторые реализации требуют использования 
    // static inflatable guest = 
    cout << "Expand your quest list with " << quest.name;
    cout << " and " << pal.name << "!\n";  // pal.name - член name переменной pal 
    cout << " You can have both for $";
    cout << quest.price + pal.price << "!\n";
    return 0;
}