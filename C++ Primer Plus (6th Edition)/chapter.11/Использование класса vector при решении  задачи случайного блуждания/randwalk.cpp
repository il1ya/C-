/*
В листинге 11.15 приведена короткая программа, которая использует усовершенствованный класс Vector. 
Она моделирует известную задачу случайного блуждания. Идея заключается в том, что вы помещаете кого-то в исходную точку. Он начинает двигаться, 
но направление с каждым шагом случайным образом изменяется по отношению к направлению на предыдущем шаге. 
Вот как выглядит одна из формулировок этой задачи: 
сколько шагов нужно сделать этому персонажу, чтобы удалиться, скажем, на 50 футов от исходной точки? 
В терминах векторов это означает сложение множества случайно ориентированных векторов до тех пор, пока сумма не превысит 50 футов. 
Код в листинге 11.15 позволяет выбрать заданное расстояние, которое нужно преодолеть, и длину шага. 
Он поддерживает промежуточную сумму, которая представляет позицию после каждого шага (в виде вектора), и сообщает количество шагов, 
необходимых для преодоления заданного расстояния в соответствии с текущим положением (в обоих форматах). 
Как вы увидите, перемещение персонажа достаточно неэффективно. 
Путешествие из 1000 шагов, по 2 фута каждый, может увести его всего на 50 футов от начальной точки. 
Для измерения степени неэффективности общая преодоленная дистанция (в данном случае 50 футов) делится на количество шагов. 
Все случайные изменения направления делают среднюю длину перемещения значительно меньше, чем один шаг. 
Для случайного выбора направления в программе используются стандартные библиотечные функции rand(), srand() и time(), которые описаны в следующем разделе "Замечания по программе". 
Обеспечьте совместную компиляцию кода из листингов 11.15и 11.14. 
Листинг 11.15. randwalk.срр */
// randwalk.срр — использование класса Vector 
// Компилировать вместе с файлом vect.cpp 
#include <iostream>
#include <cstdlib>  // прототипы rand(), srand() 
#include <ctime>    // прототип time() 
#include "vect.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0)); // начальное значение для генератора случайных чисел 
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
        // Ввод заданного расстояния (q для завершения) 
    while(cin >> target)
    {
        cout << "Enter step length: "; // ввод длины шага
        if(!(cin >> dstep))
            break;
            while(result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            cout << "After " << steps << " steps, the subject "
                                            "has the following location:\n";
            cout << result << endl; // вывод позиции после steps шагов
            result.polar_mode();
            cout << " or\n" << result << endl;
            cout << "Average outward distance per step = " << result.magval() / steps << endl; // вывод среднего расстояния на один шаг 
            steps = 0;
            result.reset(0.0, 0.0);
            cout << "Enter target distance (q to quit): ";
                // Ввод заданного расстояния (q для завершения) 

    }
    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n')
        continue;
    return 0;
}
/*
Случайная природа этого процесса порождает различные вариации от попытки к попытке, даже если начальные условия одинаковы. 
Однако в среднем уменьшение в два раза размера шага учетверяет количество шагов, необходимых для преодоления дистанции. 
Согласно теории вероятностей, среднее количество шагов (N) длиной s, которое понадобится для преодоления суммарного расстояния Д вычисляется по следующей формуле: 
N= (D/s^2) 
Но это среднее значение, которое будет существенно варьироваться от попытки к попытке. 
Например, 1000 попыток преодоления 50 футов при 2-футовом шаге в  среднем дают 636 шагов (что близко к теоретическому значению 625) на прохождение  
этого расстояния, но оно колеблется в диапазоне от 91 до 3951. 
Соответственно, 1000 попыток преодоления 50 футов при 1-футовом шаге дают в среднем 2557 шагов (близко к теоретическому значению 2500) с диапазоном от 345 до 10882. 
Итак, если вам придется двигаться случайным образом, знайте, что лучше идти большими шагами. 
Вы никак не сможете повлиять на выбор направления, но, по крайней мере, уйдете дальше. 
*/