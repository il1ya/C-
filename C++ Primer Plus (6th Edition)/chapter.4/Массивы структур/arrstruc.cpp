// Листинг 4.13. arrstruc.срр 
// arrstruc.срр -- массив структур 
#include <iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main(void)
{
    using namespace std;
    inflatable quests[2] = // инициализация массива структур 
    {
        {"Bambi", 0.5, 21.99}, // первая структура в массиве 
        {"Godzilla", 2000, 565.99} // следующая структура в массиве 
    };
    cout << "The quests " << quests[0].name << " and " << quests[1].name 
    << "\nhave a combined volume of "
    << quests[0].volume + quests[1].volume << " cubic feet.\n";
    return 0;
}