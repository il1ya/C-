/*
Наличие неявно унаследованных компонентов вместо объектов-членов влияет на кодирование этого примера, поскольку для описания объекта уже нельзя использовать идентификаторы name и score. 
Вместо этого придется вернуться к технологии, применяемой при открытом наследовании. Конструктор, используемый при включении, имеет вид: 
Student (const- char *str, const double * d, int n) 
: name(str), scores(pd, n) { } // используются имена объектов для включения 

В новой версии примера для наследуемых классов должен использоваться список инициализаторов членов, в котором для указания конструктора вместо имени члена применяется имя класса: 
Student (const char *str, const double *pd, int n) 
: std::string(str), ArrayDb (pd, n) { } // используются имена классов 
// для наследования 
Здесь, как и в предыдущем примере, ArrayDb — это typedef для std::valarray<double>. 
He забывайте, что список инициализаторов членов вместо name (str) использует определение std::string(str). 
Это второе главное отличие между двумя рассматриваемыми подходами. 
В листинге 14.4 приведено новое определение класса. 
Единственным отличием является отсутствие явно указанных имен объектов и применение имен классов вместо имен членов во встроенных конструкторах. 
Листинг 14.4. studenti.h */
// studenti.h — определение класса Student через закрытое наследование 
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <valarray>
#include <string>

class Student: private std::string, private std::valarray<double>
{
    private:
        typedef std::valarray<double> ArrayDb;
        // Закрытый метод для вывода оценок 
        std::ostream &arr_out(std::ostream &os) const;
    public:
        Student() : std::string("Null Student"), ArrayDb() {}
        explicit Student(const std::string &s) : std::string(s), ArrayDb() {}
        explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}
        Student(const std::string &s, int n) : std::string(s), ArrayDb(n) {}
        Student(const std::string &s, const ArrayDb &a) : std::string(s), ArrayDb(a) {}
        Student(const char *str, const double *pd, int n) : std::string(str), ArrayDb(pd, n) {}
        ~Student() {}
        double Average() const;
        double &operator[](int i);
        double operator[](int i) const;
        const std::string &Name() const;
        // Друзья 
        // Ввод 
        friend std::istream &operator>>(std::istream &is, Student &stu); // 1 слово
        friend std::istream &getline(std::istream &is, Student &stu); // 1 строка
        // Вывод 
        friend std::ostream &operator<<(std::ostream &os, const Student &stu);
};
#endif
/*
Доступ к методам базового класса 
Закрытое наследование позволяет использовать Методы базового класса только 
внутри методов производного класса. Но иногда необходимо обращаться к методам 
базового класса извне. Например, объявление класса Student предполагает  
возможность вызова функции Average(). При использовании включения для этого  
нужно вызывать методы size() и sum() класса valarray внутри открытой (функции 
Student: :average () */