/* В листинге 7.18 демонстрируется использование указателя функции в программе. 
Функция estimate() вызывается дважды — один раз с передачей ей адреса функции betsy(), а второй — адреса функции pam(). 
В первом случае estimate() применяет betsy() для вычисления необходимого количества часов, а во втором — использует для этого же pam(). 
Такое решение упростит развитие программы в будущем. 
Когда другой программист разработает собственный алгоритм оценки затрат времени, ему не придется переписывать estimate(). 
Вместо этого он должен просто реализовать свою функцию ralph(), обеспечив для нее необходимую сигнатуру и тип возврата. 
Конечно, переписать estimate() не трудно, но те же принципы применимы и к более сложному коду. 
К тому же метод указателей на функции позволяет модифицировать поведение estimate(), даже не имея доступа к ее исходному коду. 
Листинг 7.18. fun_ptr.срр */
// fun_ptr.cpp -- указатели на функции 
#include <iostream>
double betsy(int);
double pam(int);

// Второй аргумент — указатель на функцию double, 
// которая' принимает аргумент типа int 
void estimate(int lines, double (*pf)(int));
int main(void)
{
    using namespace std;
    int code;
    cout << "How many lines of code do you need? ";  // ввод количества строк кода 
    cin >> code;
    cout << "Here's Betsy's estimate:\n";            // вывод первой оценки 
    estimate(code, betsy);
    cout << "Here's Pam's estimate:\n";              // вывод второй оценки 
    estimate(code, pam);
    return 0;
}

double betsy(int lns)
{
    return 0.05 * lns;
}
double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}
void estimate(int lines, double (*pf)(int))
{
    using namespace std;
    cout << lines << " lines will take ";
    cout << (*pf)(lines) << " hour(s)\n"; // вывод затрат времени 
}