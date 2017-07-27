/* В листинге 12.3 демонстрируется работа конструкторов и деструкторов StringBad. 
В программе объявления объектов размещены во внутреннем блоке, т.к. деструктор вызывается тогда, когда управление покидает блок, в котором определен объект. 
Без внутреннего блока деструкторы были бы вызваны после выхода из программы main() — в некоторых средах это не позволит увидеть сообщения деструкторов, прежде чем будет закрыто окно программы. 
Не забудьте компилировать вместе с кодом из листинга 12.3 и код из листинга 12.2. 
Листинг 12.3. vegnews.срр */
// vegnews.срр — использование операций new и delete с классами 
// компилировать вместе с strngbad.cpp 
#include <iostream>
using std::cout;
#include "strngbad.h"
void callme1(StringBad &); // передача по ссылке 
void callme2(StringBad);   // передача по значению 
int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
    return 0;
}
void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n"; // строка, переданная по ссылке 
    cout << "\"" << rsb << "\"\n";
}
void callme2(StringBad sb)
{
    cout << "String passed by value:\n";     // строка, переданная по значению 
    cout << " \"" << sb << "\"\n";
}
/*
Различные нестандартные символы, которые появляются в выводе, будут отличаться в зависимости от системы; это одна из причин, по которой класс StringBad назван неудачным (часть Bad в имени). 
Другая причина — отрицательные значения счетчика объектов. Сочетания более новых компиляторов и операционных систем, 
как правило, приводят к аварийному завершению программы непосредственно перед выводом строки с сообщением, 
что остался -1 объект (-1 left), а некоторые выдают сообщение General Protection Fault (GPF, общее нарушение защиты). 
Появление GPF означает, что программа пытается получить доступ к запрещенному для нее месту в памяти — это еще один признак неудачного проекта. 
Замечание по программе 
Программа в листинге 12.3 начинает работать нормально, но потом идет к странному аварийному завершению.
Рассмотрим сначала то, что работает нормально.  
Конструктор выдает сообщение о том, что он создал три объекта StringBad, и нумерует их. 
Программа выводит созданные объекты, используя перегруженную операцию <<: 
Starting an inner block. 
1: "Celery Stalks at Midnight" object created- 
2: "Lettuce Prey" object created 
3: "Spinach Leaves Bowl for Dollars" object created 
headlinel: Celery Stalks at Midnight 
headline2: Lettuce Prey 
sports: Spinach Leaves Bowl for Dollars 
После этого программа передает переменную headlinel в функцию callmel() и после вызова снова выводит содержимое headlinel. 
Вот этот код: 
callmel(headlinel); 
cout << "headlinel: " << headlinel << endl; 
А вот результат: 
String passed by reference: 
"Celery Stalks at Midnight" 
headlinel: Celery Stalks at Midnight 
Этот раздел кода тоже работает нормально. 
*/