/* 8. Выполните упр. 7 еще раз, но теперь считывайте символы в строку std::string, а не в динамическую память
(класс s tring знает, как использовать динамическую память).
*/
#include <iostream>
int main()
{
    std::string name;
    char enter;
    while((std::cin >> enter) && (enter != '!')){
        name += enter;
    }
    std::cout << enter << std::endl;
    return 0;
}