/* 
Исключения, классы и наследование 
Исключения, классы и наследование взаимодействуют несколькими способами. 
Во-первых, можно породить один класс исключения от другого класса, как это сделано в стандартной библиотеке C++. 
Во-вторых, можно добавить исключения в классы, вставив объявление класса исключения в определение класса. 
В-третьих, такое вложенное объявление может быть унаследовано и само служить базовым классом. 
Код в листинге 15.14 предназначен для исследования таких возможностей. В этом заголовочном файле объявлен простой класс Sales, содержащий значение года, и массив из 12 ежемесячных объемов продаж. 
Класс LabeledSales порожден от класса Sales и содержит дополнительный член для хранения метки данных. 

Листинг 15.14. sales.h 
*/
// sales.h — исключения и наследование 

#include <stdexcept>
#include <cstring>
class Sales
{
    public:
        enum {MONTHS = 12};     // может быть статической константой 
        class bad_index : public std::logic_error
        {
            private:
                int bi;         // недопустимое значение индекса
            public:
                explicit bad_index(int ix, const std::string &s = "index error in Sales object\n");
                                                                    // Ошибка индекса в объекте Sales 
                int bi_val() const {return bi;}
                virtual ~bad_index() throw() {}
        };
        explicit Sales(int yy = 0);
        Sales(int yy, const double *gr, int n);
        virtual ~Sales() {}
        int Year() const {return year;}
        virtual double operator[](int i) const;
        virtual double &operator[](int i);
    private:
        double gross[MONTHS];
        int year;
};

class LabeledSales : public Sales
{
    public:
        class nbad_index : public Sales::bad_index
        {
            private:
                std::string lbl;
            public:
                nbad_index(const std::string &lb, int ix, const std::string &s = "Index error in LabeledSales object\n");
                const std::string &label_val() const {return lbl;}
                virtual ~nbad_index() throw() {}
        };
        explicit LabeledSales(const std::string &lb = "none", int yy = 0);
        LabeledSales(const std::string &lb, int yy, const double *gr, int n);
        virtual ~LabeledSales() {}
        const std::string &Label() const {return label;}
        virtual double operator[](int i) const;
        virtual double &operator[](int i);
    private:
        std::string label;
};
/*
Рассмотрим некоторые особенности кода в листинге 15.14. Символьная константа MONTHS расположена в защищенном разделе Sales, поэтому ее значение доступно для производных классов, таких как LabeledSales. 
Класс bad_index находится в открытом разделе Sales; это делает его доступным в качестве типа для клиентских блоков catch. 
Правда, вовне этот тип нужно указывать как Sales::bad_index. 
Данный класс порожден от стандартного класса logic_error, он может сохранять недопустимые значения индексов и сообщать о них. 
Класс nbad_index находится в открытом разделе LabeledSales и доступен в клиентском коде как LabeledSales::nbad_index. 
Он порожден от bad_index и может дополнительно сохранять и выводить метки объектов LabeledSales. 
Поскольку класс bad_index порожден от logic_error, то и nbad_index также порожден от logic_error. 
Оба класса содержат перегруженные методы operator[](), которые предназначены для доступа к хранимым в объекте отдельным элементам массива и для генерации исключения, если индекс массива выходит за допустимые пределы. 
Оба класса, bad_index и nbad_index, используют спецификацию исключения throw(). 
Причина в том, что оба они, в конечном счете, унаследованы от базового класса exception, виртуальный деструктор которого использует спецификацию исключения throw(). 
Это характерно для С++98; в С++11 деструктор exception не имеет спецификации исключения. 
*/