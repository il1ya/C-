1. Назовите три шага по созданию функции. 
    1. прототип функций
    2. инициализация
    3. обьявление функций
1. Эти три шага таковы: определение функции, предоставление прототипа и вызов функции. 

362
2. Постройте прототипы, которые соответствовали бы следующим описаниям. 
а. igor() не принимает аргументов и не возвращает значения. 
void igor(void);
б. tofu() принимает аргумент int и возвращает float. 
float tofu(int );
в. mpg() принимает два аргумента типа double и возвращает double. 
double mpg(double, double );
г. summation() принимает имя массива long и его размер и возвращает значение long. 
long summation(long arr[], long);
д. doctor() принимает строковый аргумент (строка не должна изменяться) и возвращает double. 
double doctor(const char name);
е. ofcourse() принимает структуру boss в качестве аргумента и не возвращает ничего. 
boss ofcourse(boss name);
ж. plot() принимает указатель на структуру тар в качестве аргумента и возвращает строку. 
char plot(tap name);

3. Напишите функцию, принимающую три-аргумента: имя массива int, его размер и значение int. 
Функция должна присвоить каждому элементу массива это значение int. 
void arr(int one[], int two, int three)
{
    for(int i = 0; i < two; i++)
        one[i] = three;
}

4. Напишите функцию, принимающую три аргумента: указатель на первый элемент диапазона в массиве, указатель на элемент, следующий за концом этого диапазона, и значение int. 
Функция должна присвоить каждому элементу диапазона массива это значение int. 
4. 
void arr(int array[], int *element, int size)
{   
    for(int *pt = begin; pt != end; pt++)
        pt* = value;
}

5. Напишите функцию, прийимающую имя массива double и его размер в качестве аргументов и возвращающую наибольшее значение, которое содержится в этом массиве. 
Обратите внимание, что функция не должна модифицировать содержимое массива. 
5. 
double array(const double arr[], double size)
{
    double max;
    if(size < 1)
    {
        cout << "Invalid array size of " << size << endl;
        cout << "Returning a value of 0\n";
        return 0;
    }
}

6. Почему вы не используете квалификатор const для аргументов функций, относящихся к любому из базовых типов? 
6. потому что аргумент изменяемое число.

7. Каковы три формы строк в стиле С могут встретиться в программах C++? 
7. Строка может быть сохранена в массиве char, представлена строковой  константой в двойных кавычках, а также представлена с помощью указателя, указывающего на первый символ в строке. 

8. Напишите функцию, имеющую следующий прототип: 
int replace (char * str, char cl, char c2); 
Эта функция должна заменять каждое появление сі в строке str на с2 и возвращать количество выполненных замен. 
8. 
int replace(char *str, char c1, char c2)
{
    int count = 0;
    while(*str)     // пока не достигнут конец строки 
    {
        if(*str == c1)
        {
            *str = c2;
            count++;
        }
        str++; // переход к следующему символу 
    }
    return count;
}

9. Что означает выражение *"pizza"? А как насчет "taco"[2]? 
9. Поскольку C++ интерпретирует строку "pizza" как адрес ее первого элемента, применение операции * даст значение этого первого элемента, которым является символ р. 
Так как C++ интерпретирует строку "taco" как адрес се первого элемента, то "taco" [2] будет рассматриваться как значение элемента, расположенного на две позиции дальше — т.е. символ с. 
Другими словами, строковая константа действует точно так же, как имя массива. 

10. C++ позволяет передавать структуры по значению, а также передавать адрес структуры. 
Если glitz — структурная переменная, как передать ее по значению? Как передать ее адрес? Каковы преимущества и недостатки обоих подходов? 
10. Для передачи структуры по значению нужно просто передать имя структуры glitz. 
Чтобы передать ее адрес, должна использоваться операция взятия адреса, т.е. &glitz. 
Передача по значению автоматически защищает исходные данные, однако отнимает время и расходует память. 
Передача по адресу экономит время и память, но не защищает исходные данные, если только для параметра функции не будет задан модификатор const. 
Кроме того, передача по значению означает возможность применения обычной нотации для членов структуры, а передача указателя — необходимость использования операции членства через указатель. 

11. Функция judge() имеет тип возврата int. 
В качестве аргумента она принимает адрес функции. Функция, адрес которой ей передается, в свою очередь, принимает аргумент типа const char и возвращает int. Напишите прототип функции. 
11. int judge(char *arr, const char *argym);
11. int judge (int (*pf) (const char *)); 


12. Предположим, что есть следующее объявление структуры: 
struct applicant 
{ 
    char name[30]; 
    int credit_ratings[3]; 
}; 
а. Напишите функцию, которая принимает структуру applicant в качестве аргумента и отображает ее содержимое. 
void display(applicant ap)
{
    cout << ap.name << endl;
    for(int i = 0; i < 3; i++)
        cout << ap.credit_ratings[i] << endl;
}
б. Напишите функцию, которая принимает адрес структуры applicant в качестве аргумента и отображает содержимое структуры, на которую он указывает. 
б. Обратите внимание, что если ар — это структура applicant, то ра->credit_ratings — это имя массива, a pa->credit_ratings [ і ] — элемент массива. 
void show(const applicant * pa)
{
    cout << pa->name << endl;
    for(int i = 0; i < 3; i++)
        cout << pa->credit_ratings[i] << endl;
}

13. Предположим, что функции fl() и f2() имеют следующие прототипы: 
void f1(applicant *а); 
const char * f2(const applicant * al, const applicant * a2); 
Объявите pi как указатель на функцию f1, а р2 — как указатель на f2. 
Объявите ар как массив из пяти указателей того же типа, что и рі, и объявите ра как указатель на массив из десяти указателей того же типа, что и р2. 
Воспользуйтесь typedef. 
13. 
13. typedef void (*p_fl) (applicant *); 
p_flpl = fl; 
typedef const char * (*p_f2) (const applicant *, const applicant *) ; 
p_f2 p2 = f2; 
p_fl ap[5]; 
p_f2 (*pa)[10]; 
