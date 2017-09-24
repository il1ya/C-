/* 5. 
Пополните класс time, рассмотренный в упражнении 3, перегруженными операциями увеличения (++) и уменьшения (--), которые работают в обеих, префиксной и постфиксной, 
формах записи и возвращают значение. 
Дополните функцию main(), чтобы протестировать эти операции. */

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
        Int operator++(int);
        Int operator--(int);
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
Int Int::operator++(int){
    return Int(i++);
}
Int Int::operator--(int){
    return Int(i--);
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
    
    pr1++;
    pr1.show();
    pr1--;
    pr1.show();
    return 0;
}