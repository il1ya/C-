/*
10. Посмотрите на решение упр. 7. 
Может ли ввод вызвать переполнение массива; иначе говоря. можете ли вы ввести больше символов, чемвыделено памяти (это серьезная ошибка)? 
Что произойдет. если вы попытаетесь ввести больше символов, чем выделено памяти? 
*/
#include <iostream>
int main()
{
    char *array = new char[10];
    char enter;
    int sw = 0;
    while(std::cin >> enter && enter != '!'){
        array[sw] = enter;
        sw++;
    }
    for(int i = 0; array[i]; ++i)
        std::cout << array[i];
        std::cout << '\n';
        delete [] array;
}