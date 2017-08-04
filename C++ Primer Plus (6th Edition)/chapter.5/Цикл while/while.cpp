// Листинг 5.13. while.срр 
// while.срр — представление цикла while 
#include <iostream>
const int ArSize = 20;
int main(void)
{
    using namespace std;
    char name[ArSize];
    cout << "Tour first name, please: "; // ввод имени
    cin >> name;
    // Вывод имени посимвольно и в кодах ASCII 
    cout << "Here is your name, verticalized and ASCIIized:\n";
    int i = 0; // начать с начала строки 
    while(name[i] != '\0') // обрабатывать до конца строки 
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++; // не забудьте этот шаг 
    }
    return 0;
}