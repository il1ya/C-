/* Давайте продолжим рассмотрение особенностей операции деления (/). Поведение этой операции зависит от типа операндов. Если оба операнда являются  целочисленными, то C++ выполнит целочисленное деление. 
Это означает, что любая дробная часть результата будет отброшена, приводя результат к целому числу. Если один или оба операнда являются значениями с плавающей точкой, то дробная часть остается, 
поэтому результатом будет число с плавающей точкой. 
В листинге 3.11 показано, как операция деления в C++ осуществляется над значениями различных типов. Как и в листинге 3.10, в листинге 3.11 вызывается функция-член setf () для изменения  формата отображаемых результатов. */
// Листинг 3.11. divide.cрр 
// divide.cрр -- деление целых чисел и чисел с плавающей точкой 
#include <iostream>
int main(void)
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Integer division: 9/5 = " << 9 / 5 << endl;
    cout << "Floating-point division: 9.0 / 5.0 = ";
    cout << 9.0 / 5.0 << endl;
    cout << "Mixed division: 9.0 / 5 = " << 9.0 / 5 << endl;
    cout << "double constants: 1e7/9.0 = ";
    cout << 1.e7 / 9.0 << endl;
    cout << "float constants: 1e7f/9.0f = ";
    cout << 1.e7f / 9.0f << endl;
    return 0;
}