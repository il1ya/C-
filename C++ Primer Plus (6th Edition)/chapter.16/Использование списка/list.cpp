// Код в листинге 16.12 иллюстрирует работу этих методов, а также метода insert(), который определен для классов STL, моделирующих последовательности. 
// Листинг 16.12. list.cpp 
// list.cpp -- использование списка 
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void outint(int n)
{
    std::cout << n << " ";
}
int main()
{
    using namespace std;
    list<int> one(5, 2);                    // список из 5 двоек 
    int stuff[5] = { 1, 2, 4, 8, 6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int>three(two);
    three.insert(three.end(), more, more + 6);
    cout << "List one: ";                   // первый список 
    for_each(one.begin(), one.end(), outint);
    cout << endl << "List two: ";           // второй список 
    for_each(two.begin(), two.end(), outint);
    cout << endl << "List three: ";         // третий список 
    for_each(three.begin(), three.end(), outint);
    three.remove(2);
    cout << endl << "List three minus 2s: ";
                    // вычитание второго списка из третьего 
    for_each(three.begin(), three.end(), outint);
    three.splice(three.begin(), one);
    cout << endl << "List three after splice: ";    // третий список после splice() 
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List one: ";
    for_each(one.begin(), one.end(), outint);
    three.unique();
    cout << endl << "List three after unique: ";    // третий список после unique() 
    for_each(three.begin(), three.end(), outint);
    three.sort();
    three.unique();
    cout << endl << "List three after sort & unique: ";
                    // третий список после sort() и unique() 
    for_each(three.begin(), three.end(), outint);
    two.sort();
    three.merge(two);
    cout << endl << "Sorted two merged into three: ";
                    // слияние отсортированного второго списка с третьим 
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    return 0;
}
/* 
Замечания по программе 
Для отображения списков программа из листинга 16.12 использует алгоритм for_each() и функцию outint(). 
В С++11 вместо них можно было бы использовать цикл for, основанный на диапазоне: 
for(auto x : three) cout « x « " "; 
Основное различие между insert() и splice() состоит в том, что insert() вставляет копию исходного диапазона в место назначения, в то время как splice() 
перемещает исходный диапазон в место назначения. 
То есть после того, как содержимое one сливается с three, one остается пустым. (Метод splice() имеет дополнительные прототипы для перемещения отдельных элементов либо их диапазонов.) 
Метод splice() оставляет итераторы корректными. Таким образом, если определенный итератор установлен для указания на элемент из one, то он указывает на тот же 
элемент и после того, как splice() переместит его в three. 
Обратите внимание, что unique() всего лишь удаляет соседние повторяющиеся элементы, оставляя по одному экземпляру. 
После того, как программа выполнит three. unique(), список three будет по-прежнему содержать две четверки и две шестерки, которые не были соседними. 
Но применение sort(), а затем unique() обеспечит уникальность каждого элемента в списке. 
Существует автономная функция sort() (см. листинг 16.9), но она требует итераторов произвольного доступа. 
Поскольку цена быстрой вставки — отказ от произвольного доступа, автономную функцию sort() нельзя использовать со списками. 
Поэтому класс включает в себя версию-член, которая работает в рамках ограничений, накладываемых классом. 
*/