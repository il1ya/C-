/* 6. В этой главе ничего не говорилось о том, что произойдет, если, используя оператор new, вы столкнетесь с нехваткой памяти. 
Это называется исчерпанием памяти (memory exhaustion). 
Выясните, что случится.
У вас есть две очевидные альтернативы: обратиться к документации или написать программу с бесконечным циклом, в котором происходит
многократное выделение памяти и не выполняется ее освобождение.
Попробуйте оба варианта. Сколько примерно памяти вы сможете выделить, пока она не исчерпается? */

#include <iostream>
#include <stdexcept>
#include <string>

int main() try{
    int i = 0;
    while(true){
        double *ch = new double(1);
        std::cout << i << '\n';
        i++;
    }
}

catch(std::runtime_error &e){
    std::cout << e.what() << '\n';
}
catch(...){
    std::cout << "Unknown error" << '\n';
}