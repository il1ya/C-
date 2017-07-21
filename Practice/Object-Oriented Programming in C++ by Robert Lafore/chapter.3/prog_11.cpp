/*
11. 
Создайте калькулятор, выполняющий действия над денежными суммами, выраженными в фунтах, шиллингах и пенсах (см. упражнения 10 и 12 главы 2). 
Калькулятор должен складывать и вычитать вводимые значения, а также производить умножение денежной суммы на вещественное число 
(операция умножения двух денежных сумм не имеет смысла, поскольку квадратных денежных единиц не существует. 
Деление одной денежной суммы на другую мы тоже не будем рассматривать). 
Организация взаимодействия с калькулятором описана в упражнении 4 этой главы.
*/
/*
#include <iostream>
int main()
{
    char sym = 158;
    float pounds, shil, pence, summ_1;
    std::cout << "Enter the number of pounds: ";
    std::cin >> pounds;
    std::cout << "Enter the number of shillings: ";
    std::cin >> shil;
    std::cout << "Enter the number of pence: ";
    std::cin >> pence;
    summ_1 = (shil * 12 + pence) / 2.4;
    int summ_2 = summ_1;
    std::cout << pounds << "." << summ_2 << sym << std::endl;
    return 0;
     /*while(enter_0 != 'Q'){
    if(enter_0 == '+'){
        summ_1 += summ_1;
        std::cout << summ_1 << std::endl;
        }else if(enter_0 == '-'){

            }else if(enter_0 == '*'){

                }else if(enter_0 == '/'){

                    }else{
                        std::cout << enter_0 << " error input.\n";
                        }
    }
}
*/
#include <iostream>
int main(){
    char enter_0;
    do{
        int pounds, shil, pence, summ_1, summ_2, sumall, operand;
        std::cout << "Enter the number of pounds: ";    std::cin >> pounds;
        std::cout << "Enter the number of shillings: "; std::cin >> shil;
        std::cout << "Enter the number of pence: ";     std::cin >> pence;
        summ_1 = pounds * 20 * 12 + shil * 12 + pence;
        std::cout << "Enter the desired operation: (+, -, /, *) Q-out.\n";
    std::cin >> enter_0;
    if(enter_0 == '*')
        std::cin >> operand;
        else{
            std::cout << "Type in a space pounds, shillings, pence: ";
            std::cin >> pounds >> shil >> pence;
        }
        summ_2 = pounds * 20 * 12 + shil * 12 + summ_1;
    switch(enter_0){
    case '+': sumall = pence + summ_2;
        break;
    case '-': sumall = pence - summ_2;
        break;
    case '*': sumall = pence * operand;
        break;
    default: 
        std::cout << enter_0 << " wrong input\n";
        }
        std::cout << "All: " << sumall/(20*12) << " " << sumall%(20*12)/12 << " " << sumall%(20*12)%12 << '\n';
    }while(enter_0 != 'Q');
    return 0;
}