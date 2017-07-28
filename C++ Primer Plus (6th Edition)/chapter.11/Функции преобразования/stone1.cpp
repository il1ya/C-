/* Код в листинге 11.21 тестирует новые функции преобразования. В операторе присваивания используется неявное преобразование, тогда как в последнем операторе cout применяется явное приведение типа. 
Обеспечьте совместную компиляцию кода в листингах 11.20 и 11.21. 
Листинг 11.21. stonel.срр */
// stonel.срр — определяемые пользователем функции преобразования 
// компилировать вместе с stonewtl.cpp 
#include <iostream>
#include "stonewt1.h"
int main()
{
    using std::cout;
    Stonewt poppins(9,2.8); // 9 стоунов, 2.8 фунта 
    double p_wt = poppins;  // неявное преобразование 
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";
    return 0;
}
/*
Ниже показан вывод программы из листингов 11.19, 11.20 и 11.21, который показывает результат преобразования объекта Stonewt в типы int и double: 
Convert to double => Poppins: 128.8 pounds. 
Convert to int => Poppins: 129 pounds. 
*/