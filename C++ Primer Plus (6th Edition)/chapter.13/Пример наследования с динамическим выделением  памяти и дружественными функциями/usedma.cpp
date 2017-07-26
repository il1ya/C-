// Код в листинге 13.16 предназначен для проверки работы классов baseDMA, lacksDMA и hasDMA. 
// Листинг 13.16. usedma.cpp 
// usedma.cpp -- наследование, друзья и динамическое вьщеление памяти 
// Компилировать вместе с dma.срр 
#include <iostream>
#include "dma.h"
int main()
{
    using std::cout;
    using std::endl;
    baseDMA shirt("Portablly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying baseDMA object:\n";     // отображение объекта baseDMA 
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";    // отображение объекта lacksDMA 
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";      // отображение объекта hasDMA 
    cout << map << endl;
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";       // результат копирования lacksDMA 
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";   // результат присваивания hasDMA 
    cout << map2 << endl;
    return 0;

}