/*4. 
Создайте класс Int, основанный на упражнении 1 из главы 6. 
Перегрузите четыре целочисленных арифметических операции (+, -, * и /) так, чтобы их можно было использовать для операций с объектами класса Int. 
Если результат какой-либо из операций выходит за границы типа int (в 32- битной системе), имеющие значение от 2 14 7 483 648 до -2 147 483 648, 
то операция должна послать сообщение об ошибке и завершить программу. 
Такие типы данных полезны там, где ошибки могут быть вызваны арифметическим переполнением, которое недопустимо. 
Подсказка: для облегчения проверки переполнения выполняйте вычисления с использованием типа long double. Напишите программу для проверки этого класса. */

#include <iostream>
class Int{
    private:
        int i;
    public:
        Int() : i(0){
        }
        Int(int ir) : i(ir){
        }
        void input(){
            std::cout << "\nEnter 2 number: ";
            std::cin >> i;
        }        
        void show(){
            std::cout << "result = " << i << std::endl;
        }
        ~Int(){
        }
        Int operator+(Int d2);
        Int operator-(Int d2);
        Int operator*(Int d2);
        Int operator/(Int d2);
};
Int Int::operator+(Int d2){
    int in = i + d2.i;
    return Int(in);
}
Int Int::operator-(Int d2){
    int in = i - d2.i;
    return Int(in);
}
Int Int::operator*(Int d2){
    int in = i * d2.i;
    return Int(in);
}
Int Int::operator/(Int d2){
    int in = i / d2.i;
    return Int(in);
}
int main()
{
    Int pr1, pr2, pr3;
    pr1.input();
    pr2.input();
    pr3 = pr1 + pr2;
    pr3.show();
    pr3 = pr1 - pr2;
    pr3.show();
    pr3 = pr1 * pr2;
    pr3.show();
    pr3 = pr1 / pr2;
    pr3.show();
    return 0;
}