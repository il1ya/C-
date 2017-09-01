/*
10. 
Создайте класс с именем ship, который будет содержать данные об учетном номере корабля и координатах его расположения. 
Для задания номера корабля следует использовать механизм, аналогичный описанному в упражнении 8. 
Для хранения координат используйте два поля типа angle (см. упражнение 7). 
Разработайте метод, который будет сохранять в объекте данные о корабле, вводимые пользователем, и метод, выводящий данные о корабле на экран. 
Напишите функцию main(), создающую три объекта класса ship, затем запрашивающую ввод пользователем информации о каждом из кораблей и выводящую на экран всю полученную информацию.
*/
#include <iostream>
class ship{
private:
    int degrees;
    static int number;
    int number_1;
    float minut;
    char direct;
public:
    ship(int d, int n, float m, char di): degrees(d), number_1(n), minut(m), direct(di){}
    ship(): number_1(0), degrees(0), minut(0.0), direct(' '){
        number++;
        number_1 = number;
    }
    void input(){
        std::cout << "Enter the coordinates\n";
        std::cout << "Degrees: ";
        std::cin >> degrees;
        std::cout << "\nMinutes: ";
        std::cin >> minut;
        std::cout << "\nDirection(N, S, E, W): ";
        std::cin >> direct;
    }
    void screen(){
        std::cout << "serial_number: " << number_1 << " " << degrees << '\xF8' << minut << "\' " << direct << std::endl;
    }
    ~ship(){}
};
int ship::number = 0;
int main()
{
    ship pr1, pr2, pr3;

    pr1.input();
    pr2.input();
    pr3.input();

    pr1.screen();
    pr2.screen();
    pr3.screen();

    return 0;
}