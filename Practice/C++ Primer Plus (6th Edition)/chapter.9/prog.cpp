1. 
Какой схемой хранения вы воспользуетесь в следующих ситуациях? 
а. homer — это формальный аргумент(параметр)функции. 
a. homer является автоматической переменной. 
int homer = 10;
б. Переменная secret должна совместно использоваться в двух файлах. 
int secret = 20;
extern secret;
б. secret должна быть определена как внешняя переменная в одном файле и объявлена с использованием extern — в другом. 
в. Переменная topsecret должна быть доступна функциям одного файла, но скрыта от других файлов. 
static topsecret;
в. topsecret может быть определена как статическая переменная с внешним связыванием за счет помещения перед внешним определением ключевого слова static. 
Либо ее можно определить в неименованном пространстве имен. 

г. Переменная beencalled фиксирует количество вызовов функции, которая ее содержит. 
static beencalled;
г. beencalled должна быть определена как локальная статическая переменная за счет помещения перед объявлением в функции ключевого слова static. 


2. 
Опишите различия между объявлением using и директивой using. 
2. Объявление using делает доступным одиночное имя из пространства имен и имеет область видимости, соответствующую декларативной области, в которой встречается объявление using. 
Директива using делает доступными все имена из пространства имен. Применение директивы using равносильно объявлению имен в наименьшей декларативной области, которая содержит объявление 
using и само пространство имен. 

3. Перепишите следующий код таким образом, чтобы в нем не использовалось ни объявление, ни директива using.
#include <iostream> 
using namespace std; 
int main() 
{ 
    double x; 
    cout << "Enter value: "; 
    while (! (cin » x)) 
    { 
        cout « "Bad input. Please enter a number: "; // неверный ввод 
        cin.clear(); 
        while (cin.get () != '\n') 
        continue; 
    } 
    cout « "Value = " « x « endl; 
    return 0; 
} 

#include <iostream>
int main()
{
    double x;
    std::cout << "Enter value: ";
    while(!(std::cin >> x))
    {
        std::cout << "Bad input. Please enter a number: ";
        std::cin.clear();
        while(std::cin.get() != '\n')
        continue;
    }
    std::cout << "Value = " << x << std::endl;
    return 0;
}


4. Перепишите следующий код таким образом, чтобы в нем использовались объявления using вместо директивы using. 
#include <iostream> 
using namespace std;
int main()
{
    double x;
    cout << "Enter value: ";
    while(!(cin >> x))
    {
        cout << "Bad input, Please enter a number: "; // неверный ввод
        cin.clear();
        while(cin.get() != '\n')
        continue;
    }
    cout << "Value = " << x << endl;
    return 0;
}

#include <iostream>
int main(void)
{
    using std::cout;
    using std::cin;
    using std::endl;
    double x;
    cout << "Enter value: ";
    while(!(cin >> x))
    {
        cout << "Bad input, Please enter a number: "; // неверный ввод
        cin.clear();
        while(cin.get() != '\n')
        continue;
    }
    cout << "Value = " << x << endl;
    return 0;
}


5. Предположим, что функция average(3,6) должна возвращать значение int, которое является средним арифметическим двух аргументов типа int, когда 
она вызывается в одном файле, и значение double, которое является средним арифметическим от двух аргументов типа int, когда вызывается в другом файле одной и той же программы. 
Как это можно реализовать? 
5. В каждом файле можно было бы иметь отдельные определения статической функции. 
Либо же в каждом файле можно было бы определить соответствующую функцию average() в неименованном пространстве имен. 


6. Какие данные будет выводить следующая программа, состоящая из двух файлов? 
// file1.cpp
#include <iostream>
using namespace std;
void other();
void another();
int x = 10;
int y;
int main()
{
    cout << x << endl; // 10
    {
        int x = 4;
        cout << x << endl; // 4
        cout << y << endl; // 0
    }
    other(); // 10, 1
    another(); // 10, -4
    return 0;
}
void other()
{
    int y = 1;
    cout << "Other: " << x << ", " << y << endl;
}

// file2.cpp
#include <iostream>
using namespace std;
extern int x;
namespace
{
    int y = -4;
}
void another()
{
    cout << "another(): " << x << ", "<< y << endl;
}

6. 10 
4 
0 
Other: 10, 1 
another(): 10, -4 

7. Что будет выводить следующая программа? 
#include <iostream>
using namespace std;
void other();
namespace n1
{
    int x = 1;
}
namespace n2
{
    int x = 2;
}
int main(void)
{
    using namespace n1;
    cout << x << endl; // 1
    {
        int x = 4;
        cout << x << ", " << n1::x << ", " << n2::x << endl; // 4, 1, 2
    }
    using n2::x;
    cout << x << endl; // 2
    other();
    return 0;
}

void other()
{
    using namespace n2;
    cout << x << endl; // 2
    {
        int x = 4;
        cout << x << ", " << n1::x << ", " << n2::x << endl; // 4, 1, 2
    }
    using n2::x;
    cout << x << endl; // 2
}

7. 1 
4, 1, 2 
2 
2 
4, 1, 2 
2 
