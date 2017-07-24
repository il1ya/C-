/* Исключение bad__alloc и операция new 
В настоящее время в C++ проблемы, возникающие во время выделения памяти с помощью операции new, обрабатываются путем генерации в new исключения bad_alloc. 
Заголовочный файл new включает объявление класса badalloc, открыто унаследованного от класса exception. 
Правда, в давние времена операция new возвращала нулевой указатель, если не могла выделить запрошенный объем памяти. 
Текущий подход демонстрируется в листинге 15.13. 
Если исключение перехвачено, программа выводит зависящее от реализации сообщение, которое возвращается унаследованным методом what(), и затем завершается. 
Листинг 15.13. newexcp.cpp */
// newexcp.cpp — исключение bad_alloc 
#include <iostream>
#include <new>
#include <cstdlib>  // для exit(), EXIT_FAILURE 
using namespace std;
struct Big
{
    double stuff[20000];
};
int main()
{
    Big *pd;
    try{
        cout << "Trying to get a big block of memory:\n";
                // Попытка выделения крупного блока памяти 
        pd = new Big[100000];                    // 1 600 000 000 байт 
        cout << "Got past the new request:\n";  // вывод результатов запроса new 
    }
    catch(bad_alloc &ba)
    {
        cout << "Caught the exception!\n";      // произошло исключение 
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Memory successfully allocated\n";
    pd[0].stuff[0] = 4;
    cout << pd[0].stuff[0] << endl;
    delete [] pd;
    return 0;
}
/*
В этом случае метод what() возвращает строку "std: :bad_alloc". 
Если программа выполнилась без ошибок, можно попробовать увеличить объем запрашиваемой памяти. 
*/