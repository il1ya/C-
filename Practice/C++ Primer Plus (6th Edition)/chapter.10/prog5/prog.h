/*
5. Пусть имеется следующее объявление структуры: 
struct customer 
{ 
    char fullname[35]; 
    double payment; 
}; 
Напишите программу, которая будет добавлять структуры заказчиков в стек и удалять их из стека, представленного объявлением класса Stack. 
Всякий раз, когда заказчик удаляется из стека, его зарплата должна добавляться к промежуточной сумме и по этой сумме выдаваться отчет. 
На заметку: вы должны иметь возможность пользоваться классом Stack без изменений; просто поменяйте объявление typedef, чтобы Item был типом customer вместо unsigned */

#include <iostream>
#include <string>
static double running_total = 0;
struct customer
{
    char fullname[35];
    double payment;
};

typedef struct customer Item;
/*
typedef используеться для приданию стандартным типам нового имени. пример:
typedef int Lalala;
typedef float FAFafa;
typedef char CACA[55];

Теперь дальше их своей программы ты можешь создавать переменные этих типов:
Lalala b;       // Создаётся переменная b типа int
CACA str[10];   // Массив типа char из 10 элеметов, в каждом из которых ещё по 55 элементов типа char
*/

class Stack
{
    private:
        enum {MAX = 10};
        Item stack_[MAX];
        int top_;
        double summ_;
    public:
        Stack();

        // constructor with default arguments
        Stack(const Item *[], int n = 0);
        bool isempty() const;
        bool isfull() const;

        // display all information in stack
        void showStack() const;

        // sums Stack values
        void sumStack();
        
        // pushes one item from stack
        bool push(const Item &item);

        // pops one item from stack
        bool pop();
};