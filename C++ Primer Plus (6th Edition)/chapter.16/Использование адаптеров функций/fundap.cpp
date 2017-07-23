/* Однако STL предлагает функцию bindlst() для упрощения работы с классом binderlst. Ей передается имя функции и значение, используемое для создания объекта binderlst, а она возвращает объект этого типа. 
Например, бинарную функцию multiplies() можно преобразовать в унарную, которая умножает свой аргумент на 2.5. 
Для этого достаточно написать такой оператор: 
bindlst(multiplies<double>(),2.5) 
Таким образом, решение по умножению каждого элемента gr8 на 2.5 и отображению результатов имеет следующий вид: 
transform(gr8.begin(), gr8.end(), out, bindlst(multiplies<double>(), 2.5)); 
Класс binder2nd аналогичен рассмотренному, за исключением того, что он присваивает константу второму аргументу вместо первого. 
Он имеет вспомогательную функцию bind2nd, которая работает аналогично bindlst. 
В листинге 16.16 приведена короткая программа, в которой собраны вместе некоторые из последних рассмотренных примеров. 
Листинг 16.16. fundap.cpp */
// fundap.cpp — использование адаптеров функций 

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

void Show(double);
const int LIM = 6;
int main()
{
    using namespace std;
    double arr1[LIM] = {28, 29, 30, 35, 38, 59};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};
    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), Show);
    cout.precision(1);
    cout << "m8: \t";
    for_each(m8.begin(), m8.end(), Show);
    cout << endl;

    vector<double> sum(LIM);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), Show);
    cout << endl;

    vector<double> prod(LIM);
    transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), Show);
    cout << endl;

    return 0;
}

void Show(double v)
{
    std::cout.width(6);
    std::cout << v << ' ';
}

// С++11 предоставляет альтернативу функциональным указателям и функторам —лямбда-выражения, которые более подробно рассматриваются в главе 18. 
