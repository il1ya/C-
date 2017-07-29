/*
Выполните упражнение 1 из главы 9, но замените показанный там код подходящим объявлением класса golf. 
Замените setgolf(golf &, const chart *, int) конструктором с соответствующими аргументами для выполнения инициализации. 
Оставьте интерактивную версию setgolf(), но реализуйте ее с использованием этого конструктора. 
(Например, в коде setgolf() получите данные, передайте их конструктору для создания временного объекта и присвойте
 временный объект вызвавшему, представленному через *this.) 
*/
#ifndef GOLF_H_
#define GOLF_H_
#include <iostream>
const int Len = 40;
class Golf
{
    private:
        char fullname[Len];
        int handicap;
    public:
        Golf();
        Golf(const char *name, int hc);
        int setgolf(Golf & g);
        void set_handicap(int hc);
        void showgolf();
};
#endif