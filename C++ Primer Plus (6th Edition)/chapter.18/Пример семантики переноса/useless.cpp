/*
Давайте рассмотрим пример, который поможет прояснить работу семантики переноса и ссылок rvalue. 
В листинге 18.2 определяется и используется класс Useless, инкорпорирующий динамическое выделение памяти, обычный конструктор копирования и конструктор переноса, 
в котором применяется семантика переноса и ссылка rvalue. Для иллюстрации работы конструкторы и деструктор, как обычно, выдают  
сообщения, а класс использует переменную состояния, позволяющую отслеживать количество объектов. 
Кроме того, некоторые важные методы, такие как операция присваивания, опущены. 
Листинг 18.2. useless.срр 
*/
// useless.срр — класс с семантикой переноса 
#include <iostream>
using namespace std;

// Интерфейс 
class Useless
{
    private:
        int n;                      // количество элементов 
        char *pc;                   // указатель на данные 
        static int ct;              // количество объектов 
        void ShowObject() const;
    public:
        Useless();
        explicit Useless(int k);
        Useless(int k, char ch);
        Useless(const Useless &f); // обычный конструктор копирования 
        Useless(Useless && f);     // конструктор переноса
        ~Useless();
        Useless operator+(const Useless &f) const;
        // В версиях копирования и переноса необходима operator=() 
        void ShowData() const;
};
// Реализация 
int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;

    // Вызов конструктора по умолчанию; вывод количества объектов 
    cout << "default constructor called; number of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    // Вызов конструктора int; вывод количества объектов 
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    // Вызов конструктора int, char; вывод количества объектов 
    cout << "int, char constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = ch;
        ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    // Вызов конструктора копирования; вывод количества объектов 
    cout << "copy const called; number of objects: " << ct << endl;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}

Useless::Useless(const Useless && f) : n(f.n)
{
    ++ct;
    // Вызов конструктора переноса; вывод количества объктов
    cout << "move constructor called; number of objects: : " << ct << endl;
    pc = f.pc;                      // заимствовать адрес 
    f.pc = nullptr;                 // установить старый объект в нулевой указатель 
    f.n = 0;
    ShowObject();
}

Useless::~Useless()
{
    // Вызов деструктора; вывод количества объектов 
    cout << "destructor called; objects left: " << --ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete [] pc;
}

Useless Useless::operator+(const Useless & f) const
{
    cout << "Entering operator+()\n";       // начало operator+() 
    Useless temp = Useless(n + f.n);
    for(int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for(int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "temp object:\n";               // временный объект 
    cout << "Leaving operator+()\n";        // конец operator+() 
    return temp;
}

void Useless::ShowObject() const
{
    cout << "Number of elements: " << n;                // количество элементов 
    cout << " Data address: " << (void *) pc << endl;   // адрес данных 
}

void Useless::ShowData() const
{
    if(n == 0)
        cout << " (object empty)";
    else
        for(int i = 0; i < n; i++)
            cout << pc[i];
        cout << endl;
}

// Приложение 
int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;              // вызов конструктора копирования 
        Useless three(20, 'o');
        Useless four(one + three);      // вызов operator+(), конструктора переноса 
        cout << "object one: ";
        one.ShowData();
        cout << " object two: ";
        two.ShowData();
        cout << " object three: ";
        three.ShowData();
        cout << "object fout: ";
        four.ShowData();
    }
}
/*
Ключевыми определениями являются два конструктора копирования и переноса. 
Ниже приведен код конструктора копирования без операторов вывода:, 
Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct; 
    pc = new char[n]; 
    for (int i = 0; i < n; i++) 
    pc[i] = f.pc[i]; 
}

Этот конструктор делает обычную детальную копию и вызывается в следующем операторе: 
Useless two = one;      // вызов конструктора копирования 
Ссылка f ссылается на объект lvalue по имени one. 
Далее приведен код конструктора переноса без операторов вывода: 
Useless::Useless(Useless && f) : n(f.n) 
{
    ++ct; 
    pc = f .рс;         // заимствовать адрес 
    f.рс = nullptr;     // установить старый объект в нулевой указатель 
    f.п = 0;  
}
Он получает право владения существующими данными, устанавливая указатель рс на эти данные. В этот момент реи f .pc указывают на одни и те же данные. 
Это может привести к проблемам при вызове деструкторов, поскольку операцию delete [] нельзя применять дважды для одного и того же адреса. 
Во избежание этой проблемы исходный указатель в конструкторе устанавливается в nullptr, т.к. применение delete [] к нулевому указателю не является ошибкой. 
Такое изъятие прав владения иногда называют заимствованием. В коде также устанавливается в 0 счетчик элементов исходного объекта. 
Это не обязательно, но делает вывод в примере более согласованным. 
Обратите внимание, что изменения объекта f требуют отсутствия const в объявлении параметра. 
Именно этот конструктор используется в следующем операторе: 
Useless four (one + three);     // вызов конструктора переноса 
Выражение one + three вызывает Useless::operator+(), и ссылка rvalue no имени f привязывается к временному объекту rvalue, возвращаемому методом. 
Обратите внимание, что объект two является отдельной копией объекта one: оба отображают один и тот же вывод, но адреса данных (006F4B68 и 006F4BB0) отличаются. 
С другой стороны, адрес данных (006F4C48) объекта, созданного в методе Useless::operator+() — тот же, что и адрес данных, сохраненный в объекте four, который был создан конструктором переноса. 
Кроме того, в выводе видно, что после создания объекта four был вызван деструктор для временного объекта. 
Можно сказать, что это временный объект, который был удален из-за того, что размер и адрес данных являются нулевыми. 
*/