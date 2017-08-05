/* Программа string. срр имеет недостаток, скрытый за часто используемой в литературе техникой тщательного выбора примеров ввода. 
В листинге 4.3 демонстрируется тот факт, что строковый ввод может оказаться непростым. */
// Листинг 4.3. insrtl.срр 
// insrtl.срр -- чтение более одной строки 
#include <iostream>
int main(void)
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    cout << "Enter your name:\n";   // запрос имени 
    cin >> name;
    cout << "Enter your favorite dessert:\n"; // запрос любимого десерта 
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}