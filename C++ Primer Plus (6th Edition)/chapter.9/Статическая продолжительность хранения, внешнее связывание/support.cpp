// Листинг9.6. support.срр 
// support.срр — использование внешних переменных 
// Компилировать вместе с external.срр 
#include <iostream>
extern double warming;  // использование переменной warming из другого файла 

// Прототипы функций 
void update(double dt);
void local();

using std::cout;
void update(double dt)  // модифицирует глобальную переменную 
{
    extern double warming; // необязательное повторное объявление 
    warming += dt;  // использование глобальной переменной warming 
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local()  // использует локальную переменную 
{
    double warming = 0.8; // новая переменная скрывает внешнюю переменную 
    cout << "Local warming = " << warming << " degrees.\n";
    // Доступ к глобальной переменной с помощью операции разрешения контекста 
    cout << "But global waming = " << ::warming;
    cout << " degrees.\n";
}
/*
Ниже показан вывод программы из листингов 9.5 и 9.6: 
Global warming is 0.3 degrees. 
Updating global warming to 0.4 degrees. 
Global warming is 0.4 degrees. 
Local warming =0.8 degrees. 
But global warming =0.4 degrees. 
Global warming is 0.4 degrees. 


Язык C++ расширяет возможности С за счет новой операции разрешения контекста (::). 
Если поместить эту операцию перед именем переменной, будет использоваться глобальная версия этой переменной. 
Таким образом, local() отображает для warming значение 0.8, но для ::warming — значение 0.4. 
Эта операция еще будет неоднократно встречаться при обсуждении пространств имен и классов. 
Для обеспечения ясности и во избежание ошибок было бы лучше и безопаснее применять ::warming в функции update() вместо просто warming, не полагаясь на правила области видимости. 
*/