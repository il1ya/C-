/* Пример раскручивания стека приведен в листинге 15.12. В нем функция main() вызывает функцию means(), которая, в свою очередь, вызывает hmean() и gmean(). 
Функция means() за неимением ничего лучшего вычисляет среднее из значений арифметического, гармонического и геометрического средних. 
Обе функции, main() и means(), создают объекты типа demo ("разговорчивый" класс, сообщающий, когда используются его конструктор и деструктор), так что можно видеть, что происходит 
с этими объектами при генерации исключений. 
Блок try в функции main() перехватывает оба исключения bad_hmean и bad_gmean, а блок try в функции means() перехватывает только исключение bad_hmean. 
Соответствующий код catch выглядит следующим образом: 
catch (bad_hmean & bg)  // начало блока catch 
{ 
    bg.mesg(); 
    std::cout « "Caught in means()\n"; 
    throw;              // повторная генерация исключения 
} 
После реагирования на исключение и вывода сообщений код снова генерирует исключение, что в данном случае означает передачу исключения наверх, в функцию main(). 
(Обычно повторная генерация исключения приводит программу в следующую комбинацию try-catch, которая перехватывает данный тип исключения. 
При отсутствии обработчика исключения программа прекращает свое выполнение.) 
В листинге 15.12 используется тот же заголовочный файл, что и в листинге 15.11 — файл exc_mean.h из листинга 15.10. 
Листинг 15.12. error5.срр */
// error5.срр — раскручивание стека 
#include <iostream>
#include <cmath>        // или math.h, пользователям UNIX может потребоваться флаг -lm 
#include <string>
#include "exc_mean.h"
class demo
{
    private:
        std::string world;
    public:
        demo(const std::string &str)
        {
            world = str;
            std::cout << "demo " << world << " created\n";    // строка создана 
        }
        ~demo()
        {
            std::cout << "demo " << world << " destroyed\n";  // строка уничтожена 
        }
        void show() const
        {
            std::cout << "demo " << world << " lives!\n";     // строка существует 
        }
};
// Прототипы функций 
double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;
    {
        demo d1("found in block in main()");
        cout << "Enter two numbers: ";          // запрос на ввод двух чисел 
        while(cin >> x >> y)
        {
            try                                 // начало блока try 
            {
                z = means(x, y);
                cout << "The mean mean of " << x << " and " << y << " is " << z << endl;    // вывод среднего из средних 
                cout << "Enter next pair: ";                                                // ввод следующей пары 
            }                                                                               // конец блока try 
            catch(bad_hmean &bg)                                                            // начало блока catch 
            {
                bg.mesg();
                cout << "Try again.\n";                                                     // необходимо повторить попытку 
                continue;
            }
            catch(bad_gmean &hg)
            {
                cout << hg.mesg();
                cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
                cout << "Sorrt,you don't get to play any more.\n";
                break;
            }                                                                               // конец блока catch 
        }
        d1.show();
    }
    cout << "Bye!\n";
    cin.get();
    cin.get();
    return 0;
}
double hmean(double a, double b)
{
    if(a == -b)
        throw bad_hmean(a,b);
        return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if(a < 0 || b < 0)
        throw bad_gmean(a, b);
        return std::sqrt(a * b);
}

double means(double a, double b)
{
    double am, hm, gm;
    demo d2("found in means()");
    am = (a + b) / 2.0;             // среднее арифметическое 
    try
    {
        hm = hmean(a,b);
        gm = gmean(a,b);
    }
    catch(bad_hmean &bg)            // начало блока catch 
    {
        bg.mesg();
        std::cout << "Caught in means()\n";
        throw;                      // повторная генерация исключения 
    }
    d2.show();
    return(am + hm + gm) / 3.0;
}
/*
Замечания по программе 

Давайте проанализируем выполнение программы из предыдущего раздела. Сначала в main() с помощью конструктора demo создается объект. 
Потом вызывается функция means() и создается другой объект demo. Функция means() передает значения б и 12 
в hmean() и gmean(), а эти функции возвращают значения, на основе которых рассчитывается и возвращается результат. 
Прежде чем вернуть результат, means() вызывает d2.show(). Вернув результат, means() завершается и автоматически вызывается деструктор для d2: 

    demo found in means() lives! 
    demo found in means() destroyed 

Следующий цикл ввода передает в means() значения 6 и -6, после чего функция means() создает новый объект demo и передает значения в hmean(). 
Функция hmean() генерирует исключение bad_hmean, которое в means() перехватывается блоком catch, что видно в следующем фрагменте: 

    hmean(6, -6) : invalid arguments: a = -b 
    Caught in means() 

Оператор throw в этом блоке завершает выполнение means() и передает исключение в main(). 
Вызов d2.show не выполняется — т.е. means() завершена. 
Однако деструктор для d2 вызывается: 

    demo found in means() destroyed 

Это демонстрирует очень важный аспект исключений: когда программа раскручивает стек до места перехвата исключения, она очищает автоматические переменные класса, сохраненные в стеке. 
Если переменная является объектом класса, вызывается деструктор этого класса. 
Повторно сгенерированное исключение добирается до main(), где захватывается и обрабатывается соответствующим блоком catch: 

    hmean (6, -6) : invalid arguments: a = -b 
    Try again. 

Третий цикл ввода передает в means() значения 6 и -8. И снова means() создаст новый объект demo. 
Он передает значения 6 и -8 в функцию hmean(), которая без проблем их обрабатывает. 
Затем hmean() передает б и -8 в функцию gmean(),  которая генерирует исключение bad_gmean. Поскольку means() не перехватывает это исключение, она передает его дальше в main (), 
и никакой код из means() больше не выполняется. 
Но и в этом случае при раскручивании стека освобождаются локальные автоматические переменные, в частности, вызывается деструктор для d2: 

    demo found in means() destroyed 

Наконец, обработчик bad_gmean в main() перехватывает исключение и завершает цикл: 

    gmean() arguments should be >= О 
    Values used: 6, -8 
    Sorry, you don't get to play any more. 

Далее программа нормально завершается, выводит несколько сообщений и автоматически вызывает деструктор для dl. 
Если блок catch вызовет, скажем, exit (EXIT_FAILURE), а не break, программа завершится немедленно, и вы не увидите сообщений: 

    demo found in main() lives! 
    Bye! 
    Однако будет выдано сообщение: 
    demo found in main() destroyed 

Здесь механизм исключений также освободит автоматические переменные, помещенные в стек. 
Обратите внимание на спецификацию исключения для means(): 

    double means(double a, double b) throw(bad_hmean, bad_gmean); 
*/