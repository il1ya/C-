/*
Конструкторы переноса и операции присваивания с переносом работают со значениями rvalue. 
А что, если их необходимо использовать со значениями lvalue? 
Например, программа могла бы анализировать массив некоторых объектов, выбирать один объект для последующей работы и отбрасывать массив. 
Было бы удобно применять конструктор переноса или операцию присваивания с переносом для предохранения выбранного объекта. 
Однако предположим, что вы пытаетесь сделать следующее: 
Useless choices[10]; 
Useless best; 
int pick; 
... // выбор одного объекта, установка pick в его индекс 
best = choices[pick]; 
Объект choices[pick] представляет собой lvalue, поэтому оператор присваивания будет использовать операцию присваивания с копированием, а не операцию присваивания с переносом. 
Но если сделать так, чтобы choices[pick] выглядело как rvalue, то применялась бы операция присваивания с переносом. Этого можно  
достигнуть за счет использования операции staticcasto для приведения объекта к типу Useless &&. 
В C++11 для этого предлагается более простой способ — применение функции std::move(), которая объявлена в заголовочном файле utility. 
В листинге 18.3 приведен пример. Здесь к классу Useless добавляются многословные версии операций присваивания, а из ранее многословных конструкторов и деструктора удалены операторы вывода на экран. 
Листинг 18.3. stdmove.срр */
// stdmove.срр -- использование std::move() 

#include <iostream>
#include <utility>
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
        Useless &operator=(const Useless &f);       // операция присваивания с копированием 
        Useless &operator=(Useless && f);           // операция присваивания с переносом 
        void ShowData() const;
};
// Реализация 
int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    pc = new char[n];
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = ch;
}

Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = f.pc[i];
}

Useless::Useless(const Useless && f) : n(f.n)
{
    ++ct;
    pc = f.pc;                      // заимствовать адрес 
    f.pc = nullptr;                 // установить старый объект в нулевой указатель 
    f.n = 0;
}

Useless::~Useless()
{
    delete [] pc;
}
Useless &Useless::operator=(const Useless &f) // операция присваивания с копированием 
{
    std::cout << "copy assignment operator called:\n";
                    // вызов операции присваивания с копированием 
    if(this == &f)
        return *this;
        delete [] pc;
        n = f.n;
        pc = new char[n];
        for(int i = 0; i < n; i++)
            pc[i] = f.pc[i];
        return *this;
}

Useless &Useless::operator=(Useless &&f) // операция присваивания с переносом 
{
    std::cout << "move assignment operator called:\n";
            // вызов операции присваивания с переносом 
    if(this == &f)
        return *this;
    delete [] pc;
    n = f.n;
    pc = f.pc;
    f.n = 0;
    f.pc = nullptr;
    return *this;
}
Useless Useless::operator+(const Useless & f) const
{
    Useless temp = Useless(n + f.n);
    for(int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for(int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
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
        Useless one(10, 'x');
        Useless two = one + one;                // вызов конструктора с переносом 
        cout << "object one: ";
        one.ShowData();
        cout << " object two: ";
        two.ShowData();
        Useless three, four;
        cout << "three = one\n";
        three = one;                            // автоматическое присваивание с копированием 
        cout << "now object three = ";
        three.ShowData();
        cout << "and object one = ";
        one.ShowData();
        cout << "four = one + two\n";
        four = one + two;                       // автоматическое присваивание с переносом 
        cout << "now object four = ";
        four.ShowData();
        cout << "four = move(one)\n";
        four = move(one);                  // принудительное присваивание с переносом
        cout << "now object four = ";
        four.ShowData();
        cout << "and object one = ";
        one.ShowData();
        return 0; 
}