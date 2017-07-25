/* Программа в листинге 14.16 использует новый шаблон стека для моделирования действий преподавателя. 
Как и в предыдущих примерах, для генерации случайных чисел в ней используются функции rand(), srand() и time(). 
Случайно сгенерированные 0 и 1 моделируют подбрасывание монеты. 
Листинг 14.16. stkoptrl.cpp */
// stkoptrl.cpp — тестирование стека указателей 

#include <iostream>
#include <cstdlib>      // для rand(), srand() 
#include <ctime>        // для time() 
#include "stcktp1.h"

const int Num = 10;
int main()
{
    std::srand(std::time(0));                   // рандомизация rand() 
    std::cout <<"Please enter stack size: ";    // ввод размера стека 
    int stacksize;
    std::cin >> stacksize;

    // Создание пустого стека размером stacksize 
    Stack<const char *> st(stacksize);

    // Входной ящик 
    const char *in[Num] = 
    {
        " 1: Hank Gilgamesh", "2: Kiki Ishtar",
        " 3: Betty Rocker", "4: Lan Flagranti",
        " 5: Wolfgang Kibble", "6: Portia Koop",
        " 7: joy Almondo", "8: Xaveria Paprika",
        " 9: Juan Moore", "10: Misha Mache"
    };
    // Выходной ящик 
    const char *out[Num];
    int processed = 0;
    int nextin = 0;
    while(processed < Num)
    {
        if(st.isempty())
            st.push(in[nextin++]);
        else if(st.isfull())
            st.pop(out[processed++]);
        else if(std::rand() % 2 && nextin < Num)    // шансы 50 на 50 
            st.push(in[nextin++]);
            else
            st.pop(out[processed++]);
    }
    for(int i = 0; i < Num; i++)
        std::cout << out[i] << std::endl;
        std::cout << "bye\n";
        return 0;
}
/*
Замечания по программе 
Строки в программе, представленной в листинге 14.16, никуда не перемещаются. 
При заталкивании строки в стек просто создается новый указатель на уже существующую строку. 
То есть создается указатель с адресом существующей строки. При выталкивании строки из стека этот адрес копируется в выходной массив. 
В программе используется тип const char *, т.к. массив указателей инициализируется набором строковых констант. 
Как воздействует деструктор стека на строки? Никак. Конструктор класса использует операцию new для создания массива, содержащего указатели. 
Деструктор класса уничтожает этот массив, а не строки, на которые ссылаются элементы массива. 
*/