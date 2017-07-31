/*
Ссылки очень хорошо работают со структурами и классами, т.е. с типами данных C++, определяемыми пользователем. 
Собственно говоря, ссылки были введены, прежде всего, для использования именно с этими типами, а не с базовыми встроенными типами данных. 
Метод использования ссылки на структуру в качестве параметра функции ничем не отличается от метода применения ссылки на базовую переменную: 
при объявлении параметра структуры достаточно воспользоваться операцией ссылки &. Например, предположим, что есть следующее определение структуры: 
struct free_throws 
{ 
    std::string name; 
    int made; 
    int attempts; 
    float percent; 
}; 
Затем функция, использующая ссылку на этот тип, может иметь такой прототип: 
    void set_pc(free_throws & ft); // использование ссылки на структуру 
Если функция не должна изменять структуру, необходимо применить const: 
    void display(const free_throws & ft); // не разрешать изменения структуры 
Программа из листинга 8.6 именно это и делает. Кроме того, она реализует интересную идею — функция возвращает ссылку на структуру. 
Такое поведение несколько отличается от случая, когда функция возвращает структуру. Потребуется принять определенные меры предосторожности, которые вскоре будут рассмотрены. 
Листинг 8.6. strc_ref.срр */
// strc_ref.cpp — использование ссылок на структуру 
#include <iostream>
#include <string>
struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};
void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);
int main(void)
{
    // Частичные инициализации — оставшиеся неинициализированными 
    // члены устанавливаются в 0 
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};

    // Инициализация не производится 
    free_throws dup;
    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    // Использование возвращаемого значения в качестве аргумента 
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);

    // Использование возвращаемого значения в присваивании 
    dup = accumulate(team,five);
    std::cout << "Displaying team:\n";
    display(team);

    // Отображение dup после присваивания 
    std::cout << "Displaying dup after assignment:\n";
    display(dup);
    set_pc(four);

    // Неблагоразумное присваивание 
    accumulate(dup, five) = four;

    // Отображение dup после неблагоразумного присваивания 
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);
    return 0;
}

void display(const free_throws & ft)
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';              // вывод члена name 
    cout << " Made: " << ft.made << '\t';             // вывод члена made 
    cout << "Attemtps: " << ft.attempts << '\t';      // вывод члена attempts 
    cout << "Percent: " << ft.percent << '\n';        // вывод члена percent 
}

void set_pc(free_throws & ft)
{
    if(ft.attempts != 0)
        ft.percent = 100.0f *float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}
/*
Замечания по программе 
Эта программа начинается с инициализации нескольких структурных объектов. 
Вспомните, что если инициализаторов меньше, чем членов, остальные члены (как percent в данном случае) устанавливаются в 0. 
Первый вызов функции выглядит следующим образом: 
set_pc(one); 
Поскольку формальный параметр ft в setpc() является ссылкой, ft ссылается на one, и код в setpc() устанавливает член one.percent. 
Передача по значению в этом случае работать не будет, поскольку это приведет к установке члена percent временной копии one. 
*/