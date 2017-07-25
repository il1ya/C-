Вопросы для самоконтроля 798
1. Для каждого набора классов из столбца А укажите, какое наследование —  общедоступное или закрытое — лучше подходит для столбца Б. 
A : Б
class Bear (Медведь)
class PolarBear (Белый медведь) : class Bear (Медведь)

Б: A
class Home (Дом) 
class Kitchen (Кухня) : class Home (Дом) 

А : Б
class Person (Человек) 
class Programmer (Программист) : class Person (Человек) 

A : Б
class Person (Человек) 
class HorseAndJockey (Лошадь и жокей) : class Person (Человек) 

A : Б
class Person, class Automobile (Человек, Автомобиль)
class Drive (Поездка) : class Person, class Automobile (Человек, Автомобиль)



2. Пусть имеются следующие определения: 
class Frabjous { 
    private: 
        char fab[20]; 
    public: 
        Frabjous (const char * s = "C++") : fab(s) { } 
        virtual void tell() { cout « fab; } 
}; 
class Gloam { 
    private: 
        int glip; 
        Frabjous fb; 
    public: 
    Gloam(int g = 0, const char * s = "C++") ; 
    Gloam(int g, const Frabjous & f) ; 
    void tell(); 
};
// Напишите определения для трех методов класса Gloam, если функция tell() из класса Gloam выводит значения glip и fb. 
2.
Gloam::Gloam(int g, const char *s) : glip(g), fb(s) {}
Gloam::Gloam(int g, const Frabjous &fr) : glip(g), fb(fr) {}
// примечание: выше используется конструктор 
// копирования Frabjous по умолчанию 
void Gloam::tell()
{
    fb.tell();
    cout << glip << endl;
}

3. Пусть имеются следующие определения: 
class Frabjous { 
    private: 
        char fab[20]; 
    public: 
        Frabjous (const char * s = "C++") : fab(s) { } 
        virtual void tell() { cout « fab; } 
}; 
class Gloam : private Frabjous{ 
    private: 
        int glip; 
    public: 
        Gloam(int g = 0, const char * s = "C++"); 
        Gloam(int g, const Frabjous & f) ; 
        void tell(); 
}; 
// Напишите определения для трех методов класса Gloam, если функция tell () из класса Gloam выводит значения glip и f b. 
3. 
Gloam::Gloam(int g, const char *s)      : glip(g), Frabjous(s) {}
Gloam::Gloam(int gm const Frabjous &fr) : glip(g), Frabjous(fr) {}
// примечание: выше используется конструктор 
// копирования Frabjous по умолчанию 
void Gloam::tell()
{
    Frabjous::tell();
    cout << glip << endl;
}

4. Пусть имеется следующее определение, основанное на шаблоне Stack из листинга 14.13 и на классе Worker из листинга 14.10: 
Stack<Worker *> sw; 
Напишите объявление класса, который будет сгенерирован (только объявление, без встроенных методов). 
4. class Stack<Worker *>
{
    private:
        enum {MAX = 10};
        Worker *items[MAX];
        int top;
    public:
        Stack();
        Boolean isempty();
        Boolean isfull();
        Boolean push(const Worker *&item);  // добавляет элемент в стек 
        Boolean pop(Worker *&item);         // выталкивает элемент 
};                                          // с вершины стека 

5. Воспользуйтесь определениями шаблонов, рассмотренных в этой главе, чтобы определить: 
• массив объектов string; 
• стек массивов значений double; 
• массив стеков указателей на объекты Worker. 
Сколько определений шаблонов классов сгенерировано в листинге 14.18? 
5.
ArrayTP<string> sa;
StackTP<ArrayTP<double> > stck_arr_db;
ArrayTP< StackTP<Worker *> > arr_stk_wpr;
В листинге 14.18 генерируется четыре шаблона: ArrayTP<int, 10>, ArrayTP<double, 10>, ArrayTP<int, 5> и Array< ArrayTP<int, 5>, 10>. 


6. Объясните разницу между виртуальными и невиртуальными базовыми классами. 
6. Если две цепочки наследования класса имеют общего предка, то класс будет иметь две копии членов этого предка. 
Проблему можно решить, сделав класс предка виртуальным базовым классом по отношению к его непосредственным наследникам. 
