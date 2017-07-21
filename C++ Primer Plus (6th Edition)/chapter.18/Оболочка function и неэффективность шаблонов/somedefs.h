/*
Пусть имеется следующая строка кода: 
answer = ef(q); 
Что собой представляет еf? Это может быть имя функции. Это может быть указатель на функцию. Это может быть функциональный объект. 
Это может быть имя, назначенное лямбда-выражению. Все это примеры вызываемых шипов. Обилие вызываемых типов может привести к неэффективности шаблонов. 
Чтобы увидеть это, рассмотрим простой случай. 
Для начала определим некоторые шаблоны в заголовочном файле, как показано в листинге 18.6. 
Листинг 18.6. somedefs.h */
// somedefs.h 
#include <iostream>
template <typename T, typename F>
T use_f(T v, F f)
{
    static int count = 0;
    count++;
    std::cout << " use_f count = " << count << ", &count = " << &count << std::endl;
    return f(v);
}
class Flip
{
    private:
        double z_;
    public:
        Fp(double z = 1.0) : z_(z) {}
        double operator()(double p) { return z_*p; }
};

class Fq
{
    private:
        double z_;
    public:
        Fq(double z = 1.0) : z_ (z) {}
        double operator() (double q) {return z_ + q;}
};

// Шаблон use_f() использует параметр f для представления вызываемого типа: return f(v); 
