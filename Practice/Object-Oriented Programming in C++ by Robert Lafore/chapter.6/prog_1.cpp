/* 
*1. 
Создайте класс Int, имитирующий стандартный тип int. 
Единственное поле этого класса должно иметь тип int. 
Создайте методы, которые будут устанавливать значение поля, 
равным нулю, инициализировать его целым значением, выводить значение поля на экран и складывать два значения типа Int.
Напишите программу, в которой будут созданы три объекта класса Int, два из которых будут инициализированы. 
Сложите два инициализированных объекта, присвойте результат третьему, а затем отобразите результат на экране. 
*/

#include <iostream>
class Int{
    private:
        int i;
    public:
        Int() : i(0){
        }
        Int(int ir) : i(ir){
        }
        void show(){
            std::cout << "int = " << i << std::endl;
        }
        ~Int(){
        }
        Int plus(Int d2);
};
        Int Int::plus(Int d2){
            Int temp;
            temp.i += i + d2.i;
            return temp;
        }
int main()
{
    Int pr1(10), pr2(20), pr3;
    pr3 = pr1.plus(pr2);
    pr3.show();
    return 0;
}