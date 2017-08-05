1. Как вы объявите следующие объекты данных? 
а. actor — массив из 30 элементов char. 
б. betsie — массив из 100 элементов short. 
в. chuck — массив из 13 элементов float. 
г. dipsea — массив из 64 элементов long double. 
a. char actor[30];
б. short betsie[100];
в. float chuck[13];
г. long double dipsea[64];

2. Выполните задание из вопроса 1, используя шаблонный класс array вместо встроенных массивов. 
a. array<char, 30> actors;
б. array<short, 100> betsie;
в. array<float, 13> chuck;
г. array<long double, 64> dispsea;

3. Объявите массив из пяти элементов int и инициализируйте его первыми пятью положительными нечетными числами. 
int array[5] = { 5, 7, 11, 13, 15 };

4. Напишите оператор, который присваивает переменной even сумму первого и последнего элементов массива из вопроса 3. 
int *even = array;
#include <iostream>
int main(void)
{
    using namespace std;
    int array[5] = { 5, 7, 11, 13, 15 };
    int *even = array;
    cout << even[0] + even[4] << endl;
    return 0;
}

5. Напишите оператор, который отображает значение второго элемента массива float по имени ideas. 
float array[2] = { 2.0, 4.8 };
float *ideas = array[1];
cout << ideas << endl;
return 0;

6. Объявите массив char и инициализируйте его строкой "cheeseburger". 
char array[] = { "cheeseburger" };
cout << array << endl;
return 0;

7. Объявите объект string и инициализируйте его строкой "Waldorf Salad". 
7. string array = "Waldorf Salad";
или, если директива using отсутствует: 
std::string lunch = "Waldorf Salad"; 

8. Разработайте объявление структуры, описывающей рыбу. Структура должна включать вид, вес в полных унциях и длину в дробных дюймах. 
struct fish
{
    char view[];
    int weight;
    float length;
};

9. Объявите переменную типа, определенного в вопросе 8, и инициализируйте ее. 
#include <iostream>
struct fish
{
    char view[20];
    float weight;
    double length;
};

int main(void)
{
    using namespace std;
    fish fishi =
    {
        "crucian", 10, 2.20
    };

    cout << fishi.view << endl << fishi.weight << endl << fishi.length << endl;
    return 0;
}

10. Воспользуйтесь enum для определения типа по имени Response с возможными значениями Yes, No и Maybe. Yes должно быть равно 1, No — 0, a Maybe — 2. 
10. enum Response = {No, Yes, Maybe}; 


11. Предположим, что ted — переменная типа double. Объявите указатель, указывающий на ted, и воспользуйтесь им, чтобы отобразить значение ted. 
11. double array = 0.1991;
    double *ted = array;

#include <iostream>
int main(void)
{
    using namespace std;
    double array = 0.1991; // только float
    double *ted;
    *ted = array;
    cout << *ted << endl;
    return 0;
}

12. Предположим, что treacle — массив из 10 элементов float. 
Объявите указатель, указывающий на первый элемент treacle, и используйте его для отображения первого и последнего элементов массива. 
12. 
#include <iostream>
int main(void)
{
    using namespace std;
    float treacle[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    float *art = treacle;
    cout << art[0] << endl << art[9] << endl;
    return 0;
}

13. Напишите фрагмент кода, который запрашивает у пользователя положительное целое число и затем создает динамический массив с указанным количеством элементов типа int. 
Сделайте это с применением операции new, а затем с использованием объекта vector. 
13. 
#include <iostream>
int main(void)
{
    using namespace std;
    int vectora;
    cin >> vectora;
    cout << vectora << endl;
    int *dyn = new int[vectora];
    vector<int> dv(vectora);
    return 0;
}

14. Правильный ли код приведен ниже? Если да, что он напечатает? 
cout « (int *) "Home of the jolly bytes"; 
14. нет отобразить int ASCII слов "";

15. Напишите фрагмент кода, который динамически выделит память для структуры, описанной в вопросе 8, и затем прочитает в нее значение для члена kind структуры. 
15. 
struct fish 
{ 
    char kind[20]; 
    int weight; 
    float length; 
}; 
    fish * pole = new fish; 
    cout « "Enter kind of fish: "; 
    cin >> pole->kind; 


16. В листинге 4.6 иллюстрируется проблема, вызванная тем, что числовой ввод следует за строчно-ориентированным вводом. Как замена оператора 
cin.getline(address, 80); 
оператором 
cin » address; 
повлияет на работу этой программы? 
#include <iostream>
int main(void)
{
    using namespace std;
    char address[80];
    cin.getline(address, 80); 
    cin >> address;
    cout << address << endl;
    return 0;
}

cin.getline функцуальней cin » address;
В результате использования cin >> address программа будет пропускать пробельные символы, пока не обнаружит символ, отличный от пробельного. 
Затем она читает символы, пока снова не будет обнаружен пробельный. 
Таким образом, будет пропущен символ новой строки, следующий за числовым вводом, что избавляет от этой проблемы. 
С другой стороны, будет прочитано только одно слово, а не вся строка. 


17. Объявите объект vector из 10 объектов string и объект array из 10 объектов string. 
Покажите необходимые заголовочные файлы и не используйте using. Для количества строк применяйте const. 
#include <string> 
#include <vector> 
#include <array> 
const int Str_num {10}; // or = 10 
std::vector<std::string> vstr(Str_num); 
std::array<std::string, Str_num> astr; 
