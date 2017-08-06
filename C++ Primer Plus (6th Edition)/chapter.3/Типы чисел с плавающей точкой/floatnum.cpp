/* В листинге 3.8 показан пример использования типов float и double и продемонстрированы также их различия в точности, с которой они представляют числа (т.е. количество значащих цифр). 
В программе используется метод ostream по имени setf(), который будет рассматриваться в главе 17. 
В данном примере вызов этого метода устанавливает формат вывода с фиксированной точкой, который позволяет визуально определять точность. 
Это предотвратит переключение на экспоненциальную запись для больших чисел и заставит отображать шесть цифр справа от десятичной точки. 
Аргументы ios_base::fixed и ios_base::floatfield — это константы, которые доступны в результате включения iostream. */
// Листинг 3.8. floatnum.cpp 
// floatnum.cpp — типы с плавающей точкой 
#include <iostream>
int main(void)
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield); // фиксированная точка
    float tub = 10.0 / 3.0;                           // подходит для 6 разрядов
    double mint = 10.0 / 3.0;                         // подходит для 15 разрядов
    const float million = 1.0e6;
    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;
    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;
    return 0;
}
