/* 3. Напишите программу на C++, которая использует три определяемых пользователем функции (включая main()) и генерирует следующий вывод: 
Three blind mice 
Three blind mice 
See how they run 
See how they run 
Одна функция, вызываемая два раза, должна генерировать первые две строки, а другая, также вызываемая два раза — оставшиеся строки. */
#include <iostream>

using namespace std;

void function1(void);
void function2(void);

int main(void)
{
    cout << "Three blind mice" << endl;
    function1();
    function2();
    return 0;
}

void function1(void)
{
    cout << "Three blind mice" << endl;
}

void function2(void)
{
    cout << "See how they run\n";
    cout << "See how they run" << endl;
}