// myfirst.cpp -- выводит сообщение на экран
#include <iostream>                             // директива препроцессора
int main(void)                                  // заголовок функции
{                                               // начало тела функции
    using namespace std;                        // делает видимыми определения
    cout << "Come up and C++ me some time.";    // сообщение
    cout << endl;                               // начало новой строки
    cout << "You won't regret it!" << endl;     // дополнительный вывод
    cin.get();                                  // чтобы не закрылся cmd
    return 0;                                   // завершение функции main()
}                                               // конец тела функции