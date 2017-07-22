/*
9. Как увеличивается стек: вверх (в сторону старших адресов) или вниз (в сторону младших адресов)? 
В каком направлении изначально (пока не было выполнено ни одного освобождения) растет выделяемая память?
Напишите программу, позволяющую выяснить это. 
*/
#include <iostream>
int main()
{
    int *mas = new int(100);
    int val = 100;
    int *in = &val;
    int all = reinterpret_cast<intptr_t>(in) - reinterpret_cast<intptr_t>(mas);
    std::cout << all << std::endl;
    return 0;
}