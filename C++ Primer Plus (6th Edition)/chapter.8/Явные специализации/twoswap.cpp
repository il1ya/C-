/* Как уже упоминалось ранее, если существует более одного из перечисленных прототипов, компилятор отдает предпочтение нешаблонной версии перед явными  
специализациями и шаблонными версиями, и предпочитает явную специализацию перед версией, сгенерированной из шаблона. 
В следующем примере первый вызов функции Swap() использует обобщенный шаблон, а второй вызов — явную специализацию, основанную на типе job: 
template <class T> // шаблон 
void Swap(T &, T &) ; 
// Явная специализация для типа job 
template о void Swap<job> (job &, job &) ; 
int main () 
{ 
    double u, v; 
    Swap(u,v); // используется шаблон 
    int a, b; 
    Swap(a,b); // используется void Swap<job>(job &, job &) 
} 
Конструкция <job> в выражении Swap<job> необязательна, поскольку типы аргументов функции указывают, что Это специализация для структуры job. 
Поэтому прототип может иметь и такой вид: 
template о void Swap(job &, job &); // упрощенная форма 
В старых версиях компиляторов используется правила специализации, предшествующие стандарту C++, но давайте сначала посмотрим, как должны работать явные специализации. 
Пример явной специализации Программа, представленная в листинге 8.13, иллюстрирует работу явной специализации. 
Листинг8.13. twoswap.cpp */
// twoswap.cpp -- специализация переопределяет шаблон 
#include <iostream>
template <typename T>
void Swap(T &a, T &b);
struct job
{
    char name[40];
    double salary;
    int floor;
};

// Явная специализация 
template <> void Swap<job>(job &j1, job &j2);
void Show(job &j);

int main(void)
{
    using namespace std;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;

    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i,j); // генерирует void Swap (int &, int &) 
    cout << "Now i, j = " << i << ", " << j << ".\n";
    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "Before job swapping:\n";

    Show(sue);
    Show(sidney);
    Swap(sue, sidney); // использует void Swap (job &, job &) 
    cout << "After job swapping:\n";

    Show(sue);
    Show(sidney);
    // cin.get();
    return 0;
}

template <typename T>
void Swap(T &a, T &b) // обобщенная версия 
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// Обменивается только содержимым полей salary и floor структуры job 
template <> void Swap<job>(job &j1, job &j2) // специализация 
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job &j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}
/*
i, j = 10, 20. 
Using compiler-generated int swapper: 
Now i, j = 20, 10. 
Before job swapping: 
Susan Yaffee: $73000.60 on floor 7 
Sidney Taffee: $78060.72 on floor 9 
After job swapping: 
Susan Yaffee: $78060.72 on floor 9 
Sidney Taffee: $73000.60 on floor 7 
*/