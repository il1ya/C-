/* 
Один из способов выхода из создавшейся ситуации — вызов функции abort(), если один аргумент равен другому с обратным знаком. 
Прототип функции abort() находится в заголовочном файле cstdlib (или stdlib.h). 
В типичной реализации при ее вызове в стандартный поток ошибок (тот же самый, который используется объектом сегг) отправляется сообщение вроде "abnormal program termination"  
("аварийное завершение программы"), и выполнение программы прекращается. 
Кроме того, операционной системе или родительскому процессу возвращается значение, зависящее от реализации и означающее аварийное завершение. 
Выводит ли функция abort() содержимое файловых буферов (области памяти, используемые для хранения данных при операциях с файлами) или нет, также зависит от реализации. 
Можно использовать функцию exit(), которая точно выводит содержимое буферов — правда, без вывода сообщения. 
В листинге 15.7 приведена короткая программа, использующая функцию abort(). 
Листинг 15.7. errorl. ерр 
*/
//errorІ.срр -- использование функции abort() 
#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main()
{
    double x, y, z;
    std::cout << "Enter two numbers: ";  // запрос на ввод двух чисел 
    while(std::cin >> x >> y)
    {
        z = hmean(x, y);
        std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;  // вывод среднего гармонического 
        std::cout << "Enter next set of numbers <q to quit>: ";
                    // вывод среднего гармонического 
    }
    std::cout << "Bye!\n";
    return 0;
}
double hmean(double a, double b)
{
    if(a == -b)
    {
        std::cout << "untenable arguments to hmean()\n";            // неверные аргументы для hmean() 
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}
/*
Обратите внимание, что вызов функции abort() из hmean() сразу же прекращает выполнение программы без возврата в main(). 
Вообще говоря, разные компиляторы выдают разные аварийные сообщения. Вот еще одно такое сообщение: 
This application has requested the Runtime to terminate it in an unusual way. Please contact the application's support team for more information. 
Это приложение обратилось к среде времени выполнения с запросом на необычное завершение. 
Для получения дополнительной информации свяжитесь с группой поддержки приложения. 
(Наверняка вам понравилось предположение о том, что такой небольшой программы есть группа поддержки.) 
Аварийного завершения программы можно избежать, проверяя значения х и у перед вызовом функции hmean(). 
Но не очень-то надежнонадеяться, что программист достаточно знает (или беспокоится) о выполнении такой проверки. 
*/