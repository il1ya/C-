/* Корректное использование стека указателей 
Один из способов применения стека указателей — создание в вызывающей программе массива указателей, где все указатели указывают на разные строки. 
Помещение таких указателей в стек имеет смысл, т.к. они ссылаются на разные строки. Обратите внимание, что создание различных указателей — обязанность вызывающей программы, а не стека. 
Стек должен просто манипулировать готовыми указателями, а не создавать их. 
Предположим, что нужно смоделировать следующую ситуацию. Секретарь привез преподавателю тележку с объемными курсовыми работами студентов. 
Если входной ящик преподавателя пуст, он берет из тележки верхнюю работу и кладет во входной ящик. Если входной ящик заполнен, преподаватель берет из него верхнюю работу, проверяет ее и кладет в выходной ящик. 
Если входной ящик заполнен частично, преподаватель может проверить верхнюю работу из входного ящика, а может взять верхнюю работу из тележки и положить во входной ящик. 
Чтобы решить, как поступить в каждом таком случае, он просто подбрасывает монетку. Попытаемся исследовать влияние его действий на первоначальный порядок курсовых работ. 
Описанную ситуацию можно смоделировать с помощью массива указателей на строки, представляющие курсовые работы в тележке. Каждая строка содержит имя студента, написавшего работу. 
Для представления входного ящика можно использовать стек, а для представления выходного ящика — еще один массив указателей. 
Добавление работы во входной ящик можно представить заталкиванием указателя из входного  
массива в стек, а обработку папки — выталкиванием элемента из стека и добавлением его в выходной ящик. 
Учитывая важность исследования всех аспектов данной задачи, будет полезно иметь возможность опробовать разные размеры стека. 
В листинге 14.15 класс Stack<Type> слегка переопределен так, чтобы конструктор Stack принимал размер стека в качестве аргумента. 
Это приводит к внутреннему использованию динамического массива, поэтому классу теперь требуется деструктор, конструктор копирования и операция присваивания. 
Кроме того, определение сокращает объем кода, т.к. некоторые методы встроены в код определения. 
Листинг 14.15. stcktpl.h */
// stcktpl.h — модифицированный шаблон Stack 
#ifndef STCKTP1_H_
#define STCKTP1_H_

template <class Type>
class Stack
{
    private:
        enum{SIZE = 10};    // размер по умолчанию
        int stacksize;
        Type *items;        // хранит элементы стека 
        int top;            // индекс вершины стека 
    public:
        explicit Stack(int ss = SIZE);
        Stack(const Stack &st);
        ~Stack() {delete [] items; }
        bool isempty() {return top == 0; }
        bool isfull() { return top == stacksize; }
        bool push(const Type &item);                // добавление item в стек 
        bool pop(Type &item);                       // выталкивание верхнего элемента в item 
        Stack &operator=(const Stack &st);
};

template<class Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0)
{
    items = new Type[stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack &st)
{
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for(int i = 0; i < top; i++)
        items[i] = st.items[i];
}

template <class Type>
bool Stack<Type>::push(const Type &item)
{
    if(top < stacksize)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}
template <class Type>
bool Stack<Type>::pop(Type &item)
{
    if(top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

template <class Type>
Stack<Type> &Stack<Type>::operator=(const Stack<Type> &st)
{
    if(this == &st)
        return *this;
    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for(int i = 0; i < top; i++)
        items[i] = st.items[i];
    return *this;
}

#endif
/*
Обратите внимание, что прототип объявляет тип, возвращаемый функцией операции присваивания, как ссылку на Stack, а само определение шаблонной функции задает тип как Stack<Type>. 
Первое объявление является сокращением для второго, но может использоваться только внутри области видимости класса. 
То есть можно применять тип Stack внутри определения шаблонов и шаблонных функций, а за пределами класса — например, при указании возвращаемых типов и использовании операции 
разрешения контекста — необходима полная форма Stack<Type>. */
