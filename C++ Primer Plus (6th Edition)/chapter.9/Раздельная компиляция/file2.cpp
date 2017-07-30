// Листинг 9.3. file2.срр 
// file2.cpp — содержит функции, вызываемые в filel.срр 
#include <iostream>
#include <cmath>
#include "coordin.h" // шаблоны структур, прототипы функций 

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
    cout << "degrees\n";
}
/*
В результате компиляции и компоновки этих двух файлов исходного кода и нового заголовочного файла получается исполняемая программа. 
Ниже приведен пример ее выполнения: 
Enter the x and у values : 120 80 
distance = 144.222, angle = 33.6901 degrees 
Next two numbers (q to quit) : 120 50 
distance = 130, angle = 22.6199 degrees 
Next two numbers (q to quit) : q 
Кстати, хотя мы обсудили раздельную компиляцию в терминах файлов, в стандарте C++ вместо термина файл используется термин единица трансляции, чтобы  
сохранить более высокую степень обобщенности; файловая модель — это не единственный способ организации информации в компьютере. 
Для простоты в этой книге будет применяться термин "файл", но помните, что под этим понимается также и "единица трансляции". 
*/