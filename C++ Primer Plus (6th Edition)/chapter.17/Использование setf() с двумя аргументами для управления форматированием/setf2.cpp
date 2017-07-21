// Листинг 17.9. setf2.cpp 
// setf2.cpp — использование setf() с двумя аргументами для управления форматированием 
#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    // Использовать выравнивание влево, показать знак плюс, 
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.setf(ios_base::showpos);
    cout.setf(ios_base::showpoint);     // показать завершающую десятичную точку 
    cout.precision(3);                  // показать завершающие нули с точностью, равной 3 

    // Использовать экспоненциальную запись и сохранить старые установки формата 
    ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << "Left Justification:\n";
    long n;
    for(n = 1; n <= 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    // Переключиться на внутреннее выравнивание 
    cout.setf(ios_base::internal, ios_base::adjustfield);

    // Восстановить стиль отображения значений с плавающей точкой, заданный по умолчанию 
    cout.setf(old, ios_base::floatfield);
    cout << "Internal Justification:\n";
    for(n = 1; n <= 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }
    // Использовать выравнивание по правому краю и форму записи с фиксированной точкой 
    cout.setf(ios_base::right, ios_base::adjustfield);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Right Justification:\n";
    for(n = 1; n <= 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }
    return 0;
}
/*
Обратите внимание, как установка точности в 3 ведет к отображению всего трех разрядов при отображении по умолчанию чисел с плавающей точкой 
(используемом в этой программе для внутреннего выравнивания), в то время как фиксированный и научный режимы отображают три разряда справа от десятичной точки. 
(Количество разрядов, отображаемое в экспоненциальной части для экспоненциальной записи, зависит от реализации.) 
Эффекты вызова функции setf() можно отменить с помощью функции unsetf(), имеющей следующий прототип: 
void unsetf(fmtflags mask); 
Здесь mask — битовый шаблон. Все биты mask, установленные в 1, вызывают сброс соответствующих битов. То есть setf() устанавливает биты в 1, a unsetf() возвращает биты к состоянию 0. 
*/