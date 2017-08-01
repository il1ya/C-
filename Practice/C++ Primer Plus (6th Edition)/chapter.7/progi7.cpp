/* 7. 
Вернитесь к программе из листинга 7.7 и замените три функции обработки  
массивов версиями, которые работают с диапазонами значений, заданными парой 
указателей. Функция fill_array() вместо возврата действительного  
количества прочитанных значений должна возвращать указатель на место, следующее за 
последним введенным элементом; прочие функции должны использовать его в 
качестве второго аргумента для идентификации конца диапазона данных. 
*/

// arrfun3.cpp -- функция работы с массивами и применение const 
#include <iostream>
const int Max = 5;

// Прототипы функций
double* fill_array(double *begin, double *end); //функция возвращает указатель на последний элемент массива
void show_array(double *begin, double *end);
void revalue(double, double *begin, double *end);
int main(void)
{
    using namespace std;
    double properties[Max];
    double *end = fill_array(properties, properties+Max); // название массива=указатель на первый элемент, название+число = элемент массива[число], находим последний эллемент массива и присваеваем адрес указателю end
    show_array(properties, end);
    if((end - properties) > 0) // при отнимании результат - целочисленное значение = количеству єлементов в массиве
    {
        cout << "Enter revaluation factor: ";             // ввод коэффициента переоценки
        double factor;
        while(!(cin >> factor))                           // неправильный ввод 
        {
            cin.clear();
            while(cin.get() != '\n')
            continue;
            cout << "Bad input; Please enter a number: "; // повторный запрос на ввод числа 
        }
        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "Done.\n";
    return 0;
}

double* fill_array(double *begin, double *end)
{
    using namespace std;
    double temp;
    double *pt; // создаем временный указатель
    int i = 1;
    for(pt = begin; pt != end; pt++, i++) // присваиваем ему начало массива, цикл до последнего элемента, увеличение указателя на 1 = перемещение на следующий элемент массива
    {
        cout << "Enter value #" << i << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; input process terminated.\n";
           break;
        }
        else if (temp < 0)   
            break;
    *pt = temp; // разыменовываем указатель и присваеваем ему значение 
    }
    return pt; // возвращаем указатель, который остановился на последнем возможном элементе
}

void show_array(double *begin, double *end)
{
    using namespace std;
    double *pt;
    int i = 1;
    for(pt = begin; pt != end; pt++, i++)
    {
        cout << "Property #" << i << ": $";
        cout << *pt << endl;
    }
}

void revalue(double r, double *begin, double *end)
{
    using namespace std;
    double *pt;
    for(pt = begin; pt != end; pt++)
        *pt *= r;
}