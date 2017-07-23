/* С++11 исправляет ситуацию, предоставляя шаблонные функции begin() и end(), которые принимают объект valarray в качестве аргумента. 
Поэтому вместо vad. begin() следует применять begin(vad). Эти функции возвращают значения, которые совместимы с требованиями диапазона STL: 
sort(begin(vad), end(vad)); // исправление С++11 
Код в листинге 16.20 иллюстрирует некоторые из относительных преимуществ классов vector и valarray. 
В нем используется метод push_back() и средства автоматического изменения размера vector для накопления данных. 
После сортировки чисел программа копирует их из объекта vector в объект valarray того же размера и выполняет несколько математических операций. 
Листинг 16.20. valvect.cpp */
// valvect.cpp -- сравнение vector и valarray 
#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>
int main()
{
    using namespace std;
    vector<double> data;
    double temp;

    cout << "Enter number (<=0 to quit):\n";        // запрос на ввод положительных чисел 
    while(cin >> temp && temp > 0)
        data.push_back(temp);
    sort(data.begin(), data.end());
    int size = data.size();
    valarray<double> numbers(size);
    int i;
    for(i = 0; i < size; i++)
        numbers[i] = data[i];
        valarray<double> sq_rts(size);
        sq_rts = sqrt(numbers);
        valarray<double> results(size);
        results = numbers + 2.0 * sq_rts;
        cout.setf(ios_base::fixed);
        cout.precision(4);
        for(i = 0; i < size; i++)
        {
            cout.width(8);
            cout << numbers[i] << ": ";
            cout.width(8);
            cout << results[i] << endl;
        }
        cout << "done\n";
        return 0;
}
/*
Класс valarray имеет множество возможностей помимо тех, что уже были описаны. 
Например, если numbers — объект valarray<double>, то следующий оператор создает массив значений типа bool, в котором vbool[i] устанавливается равным  
значению numbers[і] > 9, т.е. true или false: 
valarray<bool> vbool = numbers > 9; 
Существуют расширенные версии индексации. Рассмотрим одну из них — класс slice, представляющий срез. 
Объект класса slice может использоваться в качестве индекса массива — в этом случае он представляет не просто одно значение, а некоторый поднабор значений. 
Объект slice инициализируется тремя целочисленными значениями: началом, количеством и шагом. 
Начало указывает индекс первого элемента, который должен быть выбран, количество задает число выбираемых элементов, а шаг представляет расстояние между соседними элементами. 
Например, объект, сконструированный как slice (1,4,3), означает выбор четырех элементов с индексами 1, 4, 7 и 10. 
*/