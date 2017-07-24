/* Вложение в шаблонах 
Мы уже видели, что шаблоны удобны для создания контейнерных классов, таких как Queue. 
Конечно, интересно, возникнут ли проблемы при преобразовании определения класса Queue в шаблон. Так вот, проблем не будет. 
В листинге 15.5 показано, каким образом можно выполнить такое преобразование. Как обычно для шаблонных классов, заголовочный файл содержит шаблон класса и функции-шаблоны методов. 
Листинг 15.5. queuetp.h */
// queuetp.h — шаблон очереди с вложенным классом 
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class QueueTP
{
    private:
        enum {Q_SIZE = 10};
        // Node - определение вложенного класса 
        class Node
        {
            public:
                Item item;
                Node *next;
                Node(const Item &i) : item(i), next(0) {}
        };
        Node *front;
        Node *rear;
        int items;
        const int qsize;
        QueueTP(const QueueTP &q) :qsize(0) {}
        QueueTP &operator=(const QueueTP &q) {return *this;}
    public:
        QueueTP(int qs = Q_SIZE);
        ~QueueTP();
        bool isempty() const
        {
            return items == 0;
        }
        bool isfull() const
        {
            return items == qsize;
        }
        int queuecount() const
        {
            return items;
        }
        bool enqueue(const Item &item);     // добавление item в конец 
        bool dequeue(Item &item);           // удаление item из начала 
};
// Методы QueueTP 

template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
    front = rear = 0;
    items = 0;
}
template <class Item>
QueueTP<Item>::~QueueTP()
{
    Node *temp;
    while(front != 0)           // пока очередь не пуста 
    {
        temp = front;           // сохранение адреса первого элемента 
        front = front->next;    // сдвиг указателя на следующий элемент 
        delete temp;            // удаление предыдущего первого 
    }
}

// Добавление элемента в очередь 
template <class Item>
bool QueueTP<Item>::enqueue(const Item &item)
{
    if(isfull())
        return false;
    Node *add = new Node(item); // создание узла 
    // В случае сбоя операция new генерирует исключение std::bad_alloc 
    items++;
    if(front == 0)              // если очередь пуста, 
        front = add;            // элемент добавляется в начало 
    else
        rear->next = add;       // иначе добавляем в конец 
        rear = add;             // последний элемент назначается новым узлом 
        return true;
}
// Помещение первого элемента в переменную item и удаление его из очереди 
template <class Item>
bool QueueTP<Item>::dequeue(Item &item)
{
    if(front == 0)
        return false;
    item = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if(items == 0)
        rear = 0;
    return true;
}
#endif
/*
Один интересный момент: класс Node определен в листинге 15.5 через общий тип Item. 
Поэтому при наличии объявления 
QueueTp<double> dq; 
Node будет содержать значения типа double, а объявление 
QueueTp<char> cq; 
приведет к тому, что Node будет хранить значения типа char. 
Эти два класса Node определены в двух раздельных классах QueueTP, поэтому конфликт имен не возникает, и один узел имеет тип QueueTP<double>::Node, а другой — тип QueueTP<char>::Node. 
*/