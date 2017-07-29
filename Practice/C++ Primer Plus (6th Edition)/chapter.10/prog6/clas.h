/*6. 
Пусть имеется следующее объявление класса: 
class Move 
{ 
private: 
double x; 
double y; 
public: 
Move (double a = 0, double b = 0) ; // устанавливает х, у в a, b 
showmoveO const; // отображает текущие значения х, у 
Move add (const Move & m) const; 
// Эта функция добавляет х из m к х вызывающего объекта, 
// чтобы получить новое значение х, 
// Добавляет у из m к у вызывающего объекта, чтобы получить новое 
// значение у, присваивает инициализированному объекту значения х, у 
// и возвращает его 
reset (double a = 0, double b = 0) ; // сбрасывает х, у в a, b 
}; 
Создайте определения функций-членов и напишите программу, которая использует этот класс. 
*/
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
class Move
{
    private:
        double x_;
        double y_;
    public:
        Move(double a = 0, double b = 0)
        {
            x_ = a;
            y_ = b;
        };
        void showmove() const;
        Move add(const Move &m);
        void reset(double a = 0, double b = 0);
};