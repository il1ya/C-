/*
Файл клиентской программы 
В листинге 10.6 представлена короткая программа для тестирования новых методов. 
Из-за того, что здесь просто используется класс Stock, код, приведенный в листинге, является клиентом класса Stock.
Как и stocklO.cpp, он включает файл stocklO.h для доступа к объявлению класса. Эта программа демонстрирует работу конструкторов и деструктора. 
В ней также используются те же команды форматирования, что и в листинге 10.3. Для компиляции полной программы применяйте приемы,  
предназначенные для многофайловых программ, которые были описаны в главах 1 и 9. 
ЛИСТИНГ 10.6. usestockl.срр */
//usestockl.срр -- использование класса Stock 
// Компилировать вместе с stocklO.cpp 
#include <iostream>
#include "stock10.h"
int main(void)
{
    {
        using std::cout;
        // Использование конструкторов для создания новых объектов 
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart", 12, 20.0);            // первый синтаксис 
        stock1.show();
        Stock stock2 = Stock ("Boffo Objects", 2, 2.0); // второй синтаксис 
        stock2.show();

        // Присваивание stockl объекту stock2 
        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;

        // Вывод stockl и stock2 
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        // Использование конструктора для сброса объекта 
        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("Nifry Foods", 10, 50.0); // временный объект 
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done\n";
    }
    return 0;
}