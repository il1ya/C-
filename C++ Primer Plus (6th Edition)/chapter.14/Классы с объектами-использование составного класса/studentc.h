/* Пример класса student 
Нам нужно определение класса Student. Оно, конечно же, должно содержать конструкторы и, как минимум, несколько функций, реализующих интерфейс для класса Student. 
Все это показано в листинге 14.1, определяющем встроенные конструкторы и несколько дружественных функций для ввода и вывода. 
Листинг 14.1. studentc.h */
// studentc.h — определение класса Student с использованием включения 
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
    private:
        typedef std::valarray<double> ArrayDb;
        std::string name;               // включенный объект 
        ArrayDb scores;                 // включенный объект 

        // Закрытый метод для вывода оценок 
        std::ostream &arr_out(std::ostream &os) const;
    public:
        Student() : name("Null Student"), scores() {}
        explicit Student(const std::string &s) : name(s), scores() {} // Ключевое слово explicit используется для создания явных конструкторов. Другое название - «неконвертирующиеся конструкторы» (nonconverting constructors). 
        explicit Student(int n) : name("Nully"), scores(n) {}
        Student(const std::string &s, int n) : name(s), scores(n) {}
        Student(const std::string &s, const ArrayDb &a) : name(s), scores(a) {}
        Student(const char *str, const double *pd, int n) : name(str), scores(pd, n) {}
        ~Student() {}
        double Average() const;
        const std::string &Name() const;
        double &operator[](int i);
        double operator[](int i) const;

        // Друзья 
        // Ввод 
        friend std::istream &operator>>(std::istream &is, Student &stu); // 1 слово
        friend std::istream &getline(std::istream &is, Student &stu); // 1 строка
        // Вывод 
        friend std::ostream &operator<<(std::ostream &os, const Student &stu);
};
#endif

/*
С целью упрощения класс Student содержит следующее определение typedef: 
typedef std::valarray<double> ArrayDb; 
Это позволяет в остальном коде использовать вместо std::valarray<double> более удобную обозначение ArrayDb. 
Теперь методы и друзья класса могут ссылаться на тип ArrayDb. Размещение объявления typedef в закрытом разделе определения класса означает, что его можно применять только внутри реализации класса Student, 
однако оно недоступно внешним пользователям класса. Обратите внимание на использование ключевого слова explicit: 
explicit Student(const std::string &s) : name(s), scores() {}
explicit Student(int n) : name("Nully"), scores(n) {} 
Вспомните, что конструктор, который можно вызвать с одним аргументом,  работает как функция неявного преобразования типа аргумента в тип класса. 
Часто такое поведение нежелательно. Например, во втором конструкторе первый аргумент представляет количество элементов в массиве, а не значение для массива, и выполняемое 
конструктором преобразование int в Student не имеет смысла. Указание ключевого слова explicit отключает неявное преобразование. 
Без него станет возможным следующий код: 
Student doh("Homer", 10);   // сохраняет "Homer", создает массив из 10 элементов 
doh = 5;                    // сбрасывает имя в "Nully", а массив — в пустой из 5 элементов 
Здесь невнимательный программист вместо doh[0] напечатал doh. 
Без ключевого слова explicit в конструкторе значение 5 будет преобразовано во временный объект Student с помощью конструктора Student (5), и члену name будет присвоено значение "Nully". 
Затем операция присваивания заменит первоначальный doh содержимым этого временного объекта. При наличии ключевого слова explicit компилятор будет считать такую операцию присваивания ошибочной. */
