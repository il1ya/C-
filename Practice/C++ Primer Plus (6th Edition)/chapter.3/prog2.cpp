/* 2. Напишите короткую программу, которая запрашивает рост в футах и дюймах и вес в фунтах. (Для хранения этой информации используйте три переменных.) 
Программа должна выдать индекс массы тела (body mass index — ВМІ). Чтобы рассчитать ВМІ, сначала преобразуйте рост в футах и дюймах в рост в дюймах (1 фут = 12 дюймов). 
Затем преобразуйте рост в дюймах в рост в метрах, умножив на 0.0254. Далее преобразуйте вес в фунтах в массу в килограммах, разделив на 2.2. 
После этого рассчитайте ВМІ, разделив массу в килограммах на квадрат роста в метрах. Для представления различных коэффициентов преобразования используйте символические константы. */
#include <iostream>
int main(void)
{
    using namespace std;
    const double fut = 12;
    const double mun = 0.0254;
    double pounds, inches, pounds1;
    cout << "Enter your height in pounds:__\b\b";
    cin >> pounds;
    cout << "Enter your height in inches:__\b\b";
    cin >> inches;
    cout << "Enter your weight in pounds:__\b\b";
    cin >> pounds1;
    double bmi = pounds / fut;
    double bmi1 = inches * mun;
    cout << "Your pounds " << bmi << endl;
    cout << "Your convert the height in inches " << bmi1 << endl;
    return 0;
}