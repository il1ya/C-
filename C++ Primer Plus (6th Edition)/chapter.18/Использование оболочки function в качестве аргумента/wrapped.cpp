/*
Различные вызываемые аргументы в листинге 18.7 имеют одну и ту же сигнатуру вызова — double (double). 
Таким образом, чтобы исправить код в листинге 18.7 и сократить количество создаваемых экземпляров, можно с помощью 
function<double (double)> создать шесть оболочек для шести функций, функторов и лямбда. Затем все шесть вызовов use_f() могут быть сделаны с одним и тем же 
типом (function<double (double >) для F, что даст в результате только один экземпляр. 
Модифицированный код представлен в листинге 18.8. 
Листинг 18.8. wrapped.срр */
// wrapped.срр -- использование оболочки function в качестве аргумента 
#include "somedefs.h"
#include <iostream>
#include <functional>

double dub(double x) 
{
    return 2.0 * x;
}
double square(double x)
{
    return x * x;
}
int main()
{
    using std::cout;
    using std::endl;
    using std::function;
    double y = 1.21;
    function<double(double)>ef1 = dub;
    function<double(double)>ef2 = aquare;
    function<double(double)>ef3 = Fq(10.0);
    function<double(double)>ef4 = Fq(10.0);
    function<double(double)>ef5 = [](double u){return u*u;};
    function<double(double)>ef6 = [](double u){return u+u / 2.0;};
    cout << "Function pointer dub:\n";      // указатель на функцию dub 
    cout << " " << use_f(y, ef1) << endl; 
    cout << "Function pointer aquare:\n";   // указатель на функцию aquare 
    cout << " " << use_f(y, ef2) << endl;
    cout << "Function pointer Fq:\n";       // функциональный обьект Fq 
    cout << " " << use_f(y, ef3) << endl;
    cout << "Function pointer Fq:\n";       // функциональный обьект Fq 
    cout << " " << use_f(y, ef4) << endl;
    cout << "Lambda expression 1:\n";       // лямбда-выражение 1
    cout << " " << use_f(y, ef5) << endl;
    cout << "Lambda expression 2:\n";       // лямбда-выражение 2
    cout << " " << use_f(y, ef6) << endl;
    
    return 0;
}
/*
Ниже показан вывод программы из листинга 18.8: 
Function pointer dub: 
use_f count = 1, &count = 0x404020 
2.42 
Function pointer sqrt: 
use_f count = 2, &count = 0x404020 
1.1 
Function object Fp: 
use_f count = 3, &count = 0x404020 
11.21 
Function object Fq: 
use_f count = 4, &count = 0x404020 
12.1 
Lambda expression 1: 
use_f count = 5, &count = 0x404020 
1.4641 
Lambda expression 2: 
use_f count = 6, &count = 0x404020 
1.815 
Как показывает вывод, для count используется только один адрес, а значение count отражает, что шаблон use_f() вызывался шесть раз. 
Так что теперь имеется только один экземпляр, вызываемый шесть раз, и это сокращает размер исполняемого кода. 
*/