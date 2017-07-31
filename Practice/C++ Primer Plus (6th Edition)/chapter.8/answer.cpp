1. Какие разновидности функций являются хорошими кандидатами на то, чтобы быть встроенными? 
1. любиые.
1. Хорошими кандидатами на то, чтобы быть встроенными функциями, являются короткие нерекурсивные функции, которые могут уместиться в одну строку кода. 


2. Предположим, что функция song() имеет следующий прототип: void song(char * name, int times); 
а. Как модифицировать этот прототип, чтобы для переменной times по умолчанию принималось значение 1? 
б. Какие изменения следует внести в определение функции? 
в. Можно ли переменной name присвоить используемое по умолчанию значение "О, My Papa"? 

2.  a. void song(char *name, int times = 1);
    a. void song(const char * name, int times = 1); 
2. б. Никаких. Информацию о значениях по умолчанию содержат только прототипы. 
2. в. Да, при условии сохранения значения по умолчанию для times: void song(char * name = "О, My Papa", int times = 1); 


3. Напишите перегруженные версий функции iquote(), которая отображает аргументы, заключенные в двойные кавычки. 
Напишите три версии: одну для аргумента типа int, другую для аргумента типа double и третью для аргумента типа string. 
3. ;
#include <iostream>
void iquote(int ar);
void iquote(double ar);
void iquote(string ar);

void iquote(int ar)
{
    cout << "\"" << ar << "\"";
}
void iquote(double ar)
{
    cout << "\"" << ar << "\"";
}
void iquote(string ar)
{
    cout << "\"" << ar << "\"";
}

4. Пусть имеется следующая структура: 
struct box 
{ 
    char maker[40]; 
    float height; 
    float width; 
    float length; 
    float volume; 
}; 
а. Напишите функцию, которая имеет формальный аргумент — ссылку на структуру box и отображает значение каждого члена структуры. 
б. Напишите функцию, которая имеет формальный аргумент — ссылку на структуру box и устанавливает член volume в результат произведения членов height, width и length. 

4. 
a.
void funtk(box & boxx); 
void funtk(box & boxx)
{
    using namespace std;
    cout << boxx.maker << endl;
    cout << boxx.height << endl;
    cout << boxx.width << endl;
    cout << boxx.length << endl;
    cout << boxx.volume << endl;
}
б.
void funtk(box & boxx); 
void funtk(box & boxx)
{
    boxx.volume = boxx.height * boxx.width * boxx.length;
}



5. Какие изменения понадобится внести в листинг 7.15, чтобы функции fill() и show() использовали ссылочные параметры? 
//arrobj.cpp - функции с объектами array (С++11) 
#include <iostream>
#include <array>
#include <string>
// Константные данные 
const int Seasons = 4;
const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "winter"};
// Функция для изменения объекта array 
void fill(std::array<double, Seasons> & pa);
// Функция, использующая объект array, но не изменяющая его 
void show(std::array<double, Seasons> & da);
int main(void)
{
    std::array<double, Seasons> expenses;
    fill(expenses);
    show(expenses);
    return 0;
}
void fill(std::array<double, Seasons> & pa)
{
    using namespace std;
    for(int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: "; // ввод расходов по временам года 
        cin >> pa[i];
    }
}
void show(std::array<double, Seasons> & da)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";                     // вывод расходов по временам года 
    for(int i = 0; i < Seasons; i++)
    {
        cout << Seasons[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl; // вывод общей суммы расходов 
}

5. Сначала измените прототипы следующим образом: 
// Функция для изменения объекта array 
void fill(std::array<double, Seasons> & pa); 
// Функция, использующая объект array, но не изменяющая его 
void show(const std::array<double, Seasons> & da) ; 
Обратите внимание, что в show() должен использоваться квалификатор const для защиты объекта от изменения. 
Далее, внутри main() измените вызов fill(), как показано ниже: 
fill(expenses); 
Вызов show() изменений не требует. 
Затем приведите код функции fill() к следующему виду: 
void fill(std::array<double, Seasons> & pa) // изменена 
{ 
using namespace std; 
for (int i = 0; i < Seasons; i++) 
{ 
 cout « "Enter " « Snames[i] « " expenses: "; 
 cin » pa[i] ; // изменена 
} 
} 
Обратите внимание, что вместо (*ра)[і] используется просто ра[і]. 
Наконец, show() требует только изменения в заголовке функции: void show(std::array<double, Seasons> & da) 

6. Ниже дано описание результатов, которые требуется обеспечить. Укажите, может ли каждый из них быть получен с помощью аргументов по умолчанию,  
путем перегрузки функций, тем и другим способом, или же можно обойтись без этих средств. 
Предоставьте необходимые прототипы. 
а. Функция mass(density, volume) возвращает массу тела, имеющего плотность density и объем volume, а функция mass (density) возвращает массу тела, имеющего плотность density и объем 1.0 кубический метр. 
Все величины имеют тип double. 
б. Вызов repeat(10, "I'm OK") отображает указанную строку 10 раз, а вызов repeat ("But you're kind of stupid") отображает заданную строку 5 раз. 
в. Вызов average(3,6) возвращает среднее значение типа int двух аргументов int, а вызов average (3.0, 6.0)— среднее значение типа double двух значений double. 
г. Вызов mangle ("I 'm glad to meet you") возвращает символ І или указатель на строку "I'm glad to meet you" в зависимости от того, присваивается возвращаемое значение переменной типа char или переменной типа char*. 

6. а. Это можно сделать за счет использования значения по умолчанию для второго аргумента: 
double mass(double d, double v = 1.0); 
Это также можно сделать с помощью перегрузки функции: 
double mass(double d, double v); 
double mass(double d); 
б. Значение по умолчанию нельзя использовать для количества повторений, потому что значения по умолчанию должны предоставляться справа налево. 
В этом случае можно воспользоваться перегрузкой: 
void repeat(int times, const char * str); 
void repeat(const char * str); 
в. Можно использовать перегрузку функции: 
int average (int a, int b); 
double average(double x, double y); 
г. Это сделать не получится, поскольку оба варианта будут иметь одну и ту же сигнатуру. 


7. Напишите шаблон функции, которая возвращает больший из двух ее аргументов. 
7. 
template <typename I>
I ar(I one, I two);
{
    return one > two ? one : two;
}

8. Используя шаблон из вопроса 7 и структуру box из вопроса 4, предоставьте специализацию шаблона, которая принимает два аргумента типа box и возвращает 
тот из них, у которого больше значение volume. 
template<> box ar(box one, box two)
{
    return one.volume > b2.volume ? one : two;
}

9. Какие типы назначены переменным ѵ1, ѵ2, ѵЗ, ѵ4 и ѵ5 в следующем коде  (предполагается, что код является частью завершенной программы)? 
int g(int x); 
float m = 5.5f; 
float & rm = m; 
decltype(m) vl = m; 
decltype(rm) v2 = m; 
decltype((m)) v3 = m; 
decltype(g(100)) v4; 
decltype(2.0 * m) v5; 

9. vl назначается тип float, v2 — тип float &, v3 — тип float &, v4 — тип int и v5 — тип double. Литерал 2.0 имеет тип double, поэтому произведение 2.0* m также относится к double. 
