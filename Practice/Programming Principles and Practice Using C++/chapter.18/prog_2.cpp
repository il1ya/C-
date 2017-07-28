   /* Задание с вектором из стандартной библиотеки
1. Определите глобальный вектор vector<int> gv; инициализируйте его десятью целыми числами 1, 2, 4, 8, 16 и т.д.
2. Определите функцию f(), принимающую аргумент типа vector<int>.
3. В функции f() сделайте следующее.
    • Определите локальный вектор vector<int> lv с тем же количеством элементов, что и вектор. являющийся арrументом функции.
    • Скопируйте значения из вектора qv в вектор lv.
    • Выведите на печать элементы вектора lv.
    • Определите локальный вектор vector<int> lv2; и нициализируйте его так, чтобы он стал копией вектора, являющегося аргументом функции.
    • Выведите на печать элементы вектора lv2.
4. В функции main() сделайте следующее.
    • Вызовите функцию f() с арrументом qv.
    • Определите вектор vector<int> vv и инициализируйте его первыми десятью значениями факториала (т.е. 1, 2*1, 3*2*1, 4*3*2*1 и.д.).
    • Вызовите функцию f() с арrументом vv.

*/
#include <iostream>
#include <vector>
 
std::vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
 
void f(std::vector<int>ar){
    std::vector<int> lv {1, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    for(int i, j = 0; i < lv.size(); i++, j++){
        lv[i] = ar[j];
        std::cout << lv[i] << ' ';
    }
    std::cout << std::endl;

    std::vector<int> lv2(ar);
    for(int i, j = 0; i < lv2.size(); i++, j++){
        lv2[i] = ar[j];
        std::cout << lv2[i] << ' ';
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<int> vv {1, 2*1, 3*2*1, 4*3*2*1, 5*4*3*2*1, 6*5*4*3*2*1, 7*6*5*4*3*2*1, 8*7*6*5*4*3*2*1, 9*8*7*6*5*4*3*2*1, 10*9*8*7*6*5*4*3*2*1};
    f(gv);
    f(vv);
    return 0;
}


/*
#include <iostream>
#include <vector>
 
std::vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
 
void f(std::vector<int>ar){
    std::vector<int> lv {1, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
 
    std::vector<int> lv2(lv);
    for(int i, j = 0; i < lv2.size(); i++, j++){
        lv2[i] = lv[j];
        std::cout << lv2[i] << ' ';
    }
 
    std::cout << std::endl;
 
    for(int i, j = 0; i < lv.size(); i++, j++){
        lv[i] = gv[j];
        std::cout << lv[i] << ' ';
    }
 
    std::cout << std::endl;
 
    std::vector<int> lv3(gv);
    for(int i, j = 0; i < lv2.size(); i++, j++){
        lv3[i] = gv[j];
        std::cout << lv3[i] << ' ';
    }
}
int main()
{
    f(gv);
    return 0;
}
*/