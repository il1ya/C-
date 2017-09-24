/*4. 
Создайте класс Int, основанный на упражнении 1 из главы 6. 
Перегрузите четыре целочисленных арифметических операции (+, -, * и /) так, чтобы их можно было использовать для операций с объектами класса Int. 
Если результат какой-либо из операций выходит за границы типа int (в 32- битной системе), имеющие значение от 2 14 7 483 648 до -2 147 483 648, 
то операция должна послать сообщение об ошибке и завершить программу. 
Такие типы данных полезны там, где ошибки могут быть вызваны арифметическим переполнением, которое недопустимо. 
Подсказка: для облегчения проверки переполнения выполняйте вычисления с использованием типа long double. Напишите программу для проверки этого класса. */

#include <iostream>
using namespace std;
//#include <process.h>
class Int{
    private:
        int i;
    public:
        Int() : i(0){
        }
        Int(int ir) : i(ir){
        }
        void putInt(){
            std::cin >> i;
        }
        operator int(){     // операция преобразования (Int в int)
            return i;
        }
        void show(){
            std::cout << "result = " << i << std::endl;
        }
        ~Int(){
        }
        Int operator+(Int d2){
            return checkit(long double(i) + long double(d2));
        }
        Int operator-(Int d2){
            return checkit(long double(i) - long double(d2));
        }
        Int operator*(Int d2){
            return checkit(long double(i) * long double(d2));
        }
        Int operator/(Int d2){
            return checkit(long double(i) / long double(d2));
        }
        Int checkit(long double answer){ // проверка результатов
            if(answer > 2147483647.0L || answer < -2147483647.0L){
                std::cout << "\nError overfilling\n";
                //exit(1);
            }
            return Int(int(answer));
        }
};
int main()
{
Int alpha =20;
Int beta =7;
Int delta,gamma;
gamma =alpha +beta;     //27
cout <<"\ngamma=";gamma.putInt();
gamma =alpha -beta;      //13
cout <<"\ngamma=";gamma.putInt();
gamma =alpha *beta;      //140
cout <<"\ngamma=";gamma.putInt();
gamma =alpha /beta;      //2
cout <<"\ngamma=";gamma.putInt();
delta =2147483647;
gamma =delta +alpha;    //ошибка переполнения
delta =-2147483647;
gamma =delta -alpha;     //ошибка переполнения
cout <<endl;
return 0;
}