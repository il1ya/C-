/* В стандартной библиотеке С насчитывается свыше 140 предварительно определенных функций. 
Если какая-то из них подходит для решения вашей задачи, то, конечно же, имеет смысл ею воспользоваться. 
Однако нередко приходится писать собственные функции, в частности, при разработке классов. 
В любом случае проектировать собственные функции очень интересно, поэтому давайте рассмотрим этот процесс. 
Вы уже использовали некоторые предварительно определенные функции, и все они имели имя main(). 
Каждая программа на C++ должна иметь функцию main(), которую обязан определить пользователь. 
Предположим, что требуется добавить еще одну функцию, определяемую пользователем. 
Как и в случае с библиотечной функцией, вызов функции, определяемой пользователем, производится по ее имени. 
Вдобавок, как и для библиотечной функции, вы должны предоставить прототип функции перед ее использованием; обычно прототип размещается выше определения main(). 
Однако теперь вы, а не поставщик библиотеки, должны предоставить исходный код для новой функции. 
Проще всего это сделать, поместив нужный код в тот же файл после кода main(). Все сказанное проиллюстрировано в листинге 2.5. */
// Листинг 2.5. oufrune.epp 
// ourfunc.cpp — определение собственной функции 

#include <iostream>

void simon(int); // прототип функции simon() 

int main(void)
{
    using namespace std;
    simon(3);       // вызов функции simon()
    cout << "Pick an integer: ";
    int count;
    cin >> count;
    simon(count);   // еще один вызов simon()
    cout << "Done!" << endl;
    return 0;
}

void simon(int n)   // определение функции simon()
{
    using namespace std;
    cout << "Simon says touch your toes " << n << " times." << endl;
} // функции void не требуют операторов return