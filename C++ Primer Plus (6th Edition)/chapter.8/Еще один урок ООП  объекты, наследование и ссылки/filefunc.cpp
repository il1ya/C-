/*
Классы ostream и of stream вскрывают интересное свойство ссылок. 
Как упоминалось в главе 6, объекты типа of stream могут использовать методы ostream, позволяя файловому вводу-выводу применять те же формы, что и консольный ввод-вывод. 
Средство языка, позволяющее передавать возможности из одного класса в другой, называется наследованием. 
Оно подробно рассматривается в главе 13. Вкратце, ostream называется базовым классом (поскольку класс of stream основан на нем), a of stream производным классом (т.к. он порожден от ostream). 
Производный класс наследует методы базового класса. Это означает, что объект of stream может использовать функции базового класса, такие как методы форматирования precision() и setf(). 
Другой аспект наследования состоит в том, что ссылка на базовый класс может указывать на объект производного класса, не требуя приведения типа. 
На практике это позволяет определять функцию, обладающую параметром-ссылкой на базовый класс. 
Эта функция может взаимодействовать с объектами базового класса, а также с производными объектами. 
Например, функция с параметром типа ostream & может принимать объект ostream, такой как cout или of stream. 
Их можно объявлять в функции с одинаковым успехом. 
Указанные аспекты демонстрируются в листинге 8.8, где одна и та же функция используется для записи данных в файл и отображения тех же данных на экране. 
Изменяется только аргумент, который передается вызываемой функции. Представленная программа рассчитывает фокусное расстояние объектива телескопа (его основного зеркала или линзы) и отдельных окуляров. 
Затем вычисляется кратность увеличения каждого окуляра телескопа. 
Кратность увеличения равна фокусному расстоянию объектива телескопа, деленному на фокусное расстояние используемого окуляра, так что вычисления здесь несложные. 
Кроме того, в программе используются некоторые методы форматирования, которые, как обещалось, одинаково успешно выполняются как с объектами типа cout, так и с объектами типа of stream 
(в рассматриваемом примере — fout). 
Листинг8.8. filefunc.cpp 
*/
// filefunc.cpp — функция с параметром ostream & 
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream & os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main(void)
{
    ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if(!fout.is_open())
    {
        cout << "Can't open " << fn << ". Bye.\n"; // не удается открыть файл 
        exit(EXIT_FAILURE);
    }
    double objective;
    // Ввод фокусного расстояния объектива телескопа в мм 
    cout << "Enter the focal length of your "
    "telescope objective in mm: ";
    cin >> objective;
    double eps[LIMIT];
    // Ввод фокусного расстояния окуляров в мм 
    cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
    for(int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }
    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done\n";
    return 0;
}
void file_it(ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); // сохранение исходного состояния форматирования 
    os.precision(0);
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f.l.eyepiece";
    os.width(15);
    os << "magnification" << endl;      // коэффициент увеличения 
    for(int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial);
    // восстановление исходного состояния форматирования 
}
/*
Ниже показан пример выполнения программы из листинга 8.8: 
Enter the focal length of your telescope objective in mm: 1800 
Enter the focal lengths, in mm, of 5 eyepieces: 
Eyepiece #1: 30 
Eyepiece #2: 19 
Eyepiece #3: 14 
Eyepiece #4:8.8 
Eyepiece #5: 7.5 
Focal length of objective: 1800 mm 
f.l.eyepiece magnification 
30.0 60 
19.0 95 
14.0 129 
8.8 205 
7.5 240 
Done 

Следующая строка записывает данные окуляра в файл ep-data.txt: 
file_it(fout, objective, eps, LIMIT); 
А приведенная ниже строка выводит идентичную информацию в том же формате на экран: 
file_it(cout, objective, eps, LIMIT); 
*/