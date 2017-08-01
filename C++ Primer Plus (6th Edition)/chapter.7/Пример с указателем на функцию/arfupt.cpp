// Листинг 7.19 arfupt.cpp 
// arfupt.cpp - массив указателей на функции 
#include <iostream>
// Различные нотации, одни и те же сигнатуры 
const double *f1(const double ar[], int n);
const double *f2(const double [], int);
const double *f3(const double *, int);
int main(void)
{
    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};
    // Указатель на функцию 
    const double *(*p1)(const double *, int) = f1;
    auto p2 = f2; // автоматическое выведение типа C++11 
    // До С+ + 11 можно использовать следующий код 
    // const double *(*p2)(const double *, int) = f2; 
    // Использование указателей на функции 
    cout << "Using pointers to functions:\n";
    cout << " Address Value\n"; // вывод значения адреса 
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
    // pa - массив указателей 
    // auto не работает со списковой инициализацией 
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
    // но работает с инициализацией единственным значением 
    // pb - указатель на первый элемент ра 
    auto pb = pa;
    //До C++11 можно использовать следующий код 3
    // const double *(**pb)(const double *, int) = pa; 
    // Использование массивов указателей на функции 
    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address Value\n"; // вывод значения адреса 
    for(int i = 0; i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
        // Использование указателя на указатель на функцию 
    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address Value\n"; // вывод значения адреса 
    // Простой способ объявления рс 
    auto pc = &pa;
    // До С++11 можно использовать следующий код 
    // const double *(*(*рс) [3]) (const double *, int) = &pa; 
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    // Сложный способ объявления pd 
    const double *(*(*pd)[3])(const double *, int) = &pa;
    // Сохранение возвращенного значения в pdb 
    const double *pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;
    // Альтернативная нотация 
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
    // cin.get(); 
    return 0;
}
// Простейшие функции 
const double *f1(const double *ar, int n)
{
    return ar;
}
const double *f2(const double ar[], int n)
{
    return ar+1;
}
const double *f3(const double ar[], int n)
{
    return ar+2;
}
/*
Показанные адреса являются местоположениями значений double в массиве аѵ. 
Этот пример может показаться несколько надуманным, однако указатели на массивы указателей на функции не является чем-то экзотическим. 
На самом деле такой подход используется в обычной реализации виртуальных методов класса (см. главу 13). К счастью, обо всех необходимых деталях заботится компилятор. 
*/