/*
В листингах 15.10 и 15.11 добавлен еще один класс исключений bad_gmean и другая функция gmean(), которая генерирует исключение bad_gmean. 
Функция gmean() рассчитывает среднее геометрическое двух чисел — квадратный корень из их произведения. Эта функция определена, если оба аргумента неотрицательны. 
Поэтому она генерирует исключение, если обнаруживает отрицательные аргументы. 

Листинг 15.10 содержит заголовочный файл с определениями классов исключений, а листинг 15.11 — пример программы, использующей этот файл. 
Обратите внимание, что после блока try идут два блока catch подряд: 
try{       // начало блока try 
    ....
}           // конец блока try 
catch (bad_hmean & bg){     // начало блока catch
    ....
}
catch (bad_gmean & hg){

}// конец блока catch 

Если hmean() сгенерирует исключение badhmean, его перехватит первый блок catch. 
Если же gmean() сгенерирует исключение bad_gmean, оно пройдет через первый блок catch и будет перехвачено вторым. 
Листинг 15.10. exc_mean.срр */
// exc_mean.h — классы исключений для hmean() и gmean() 
#include <iostream>
class bad_hmean
{
    private:
        double v1;
        double v2;
    public:
        bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
        void mesg();
};
inline void bad_hmean::mesg()
{
    std::cout << "hmean(" << v1 << ", " << v2 << ") :" << "invalid arguments: a = -b\n";  // неверные аргументы 
}
class bad_gmean
{
    public:
        double v1;
        double v2;
        bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
        const char *mesg();
};
inline const char *bad_gmean::mesg()
{
    return "gmean() arguments should be >= 0\n";  // аргументы gmean() должны быть >= 0 
}