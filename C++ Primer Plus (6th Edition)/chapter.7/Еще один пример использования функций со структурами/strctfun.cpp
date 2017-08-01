// Листинг7.12. strctfun.cpp 
// strctfun.cpp -- функции с аргументами-структурами 
#include <iostream>
#include <cmath>

// Объявления структур 
struct polar
{
    double distance; // расстояние от исходной точки 
    double angle;    // направление от исходной точки 
};

struct rect
{
    double x;       // расстояние по горизонтали от исходной точки 
    double y;       // расстояние по вертикали от исходной точки 
};

// Прототипы
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main(void)
{
    using namespace std;
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values: ";   // ввод значений х и у 
    while(cin >> rplace.x >> rplace.y);    // ловкое использование сіп 
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
            // Ввод следующих двух чисел (q для завершения) 
    }
    cout << "Done.\n";
    return 0;
}

// Преобразование прямоугольных координат в полярные 
polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    return answer; // возврат структуры polar 
}
// Отображение полярных координат с преобразованием радиан в градусы 
void show_polar(polar dapos)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;
    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees\n";
}
/*
Замечания по программе 
Мы уже обсудили две функции из листинга 7.12, а теперь давайте разберемся, как программа использует сin для управления циклом while: 
while (cin >> rplace.x >> rplace.y) 
Вспомните, что cin — объект класса istream. Операция извлечения (») спроектирована так, что выражение cin » rplace. х также является объектом этого типа. 
Как будет показано в главе 11, операции классов реализованы с помощью функций. Что в действительности происходит, когда используется cin » rplace.x? 
Программа вызывает функцию, которая возвращает переменную типа istream. 
Если вы  применяете операцию извлечения к объекту cin » rplace.x (как в cin » rplace.x » rplace. у), то опять получаете объект класса istream. 
Таким образом, в конечном итоге проверочное условие цикла while вычисляется как cin, что, как вы помните, 
при использовании в контексте проверочного условия преобразуется в булевское значение true или false, в зависимости от того, успешным ли был ввод. 
Например, в цикле из листинга 7.12 cin ожидает от пользователя ввода двух чисел. 
Если же вместо этого пользователь вводит q, как показано в примере вывода программы, операция cin » распознает, что q — не число. 
Она оставляет q во входной очереди и возвращает значение, преобразуемое в false, завершая выполнение цикла. 
Сравните этот подход к чтению чисел со следующим более простым: 
for (int i = 0; i < limit; i ++) 
{ 
    cout « "Enter value #" « (i + 1) « ": "; 
    cin » temp; 
    if (temp < 0) 
    break; 
    ar[i] = temp; 
} 
Чтобы прекратить этот цикл до его завершения, вы вводите отрицательное число. 
Это ограничивает ввод только неотрицательными значениями. Такой подход может быть подходящим в некоторых программах, однако чаще в качестве условия 
прекращения цикла используется то, что не будет исключать определенные  числовые значения из списка допустимых. 
Применение cin » в качестве проверочного условия исключает это ограничение, поскольку обеспечивает прием любого допустимого числового ввода. 
Вам стоит запомнить этот трюк и использовать его всякий раз, когда нужно организовать в цикле ввод чисел. 
К тому же следует иметь в виду, что нечисловой ввод выставляет условие ошибки, которое предотвращает чтение любого дальнейшего ввода. 
Если программа должна выполнять дальнейший ввод после завершения цикла, вы должны применять cin.clear(), чтобы сбросить состояние 
ошибки входного потока, и вдобавок прочитать ошибочный ввод, чтобы избавиться от него. Этот прием демонстрировался в листинге 7.7. 
*/