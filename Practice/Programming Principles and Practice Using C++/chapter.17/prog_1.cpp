// 1.Разместите в динамической памяти массив, состоящий из десяти чисел типа int, используя оператор new.
// 2. Выведите в поток cout значения этих десяти чисел типа int.
// 3. Освободите память, занятую массивом (используя оператор delete []).
// 4. Напишите функцию print_array10(ostream &os , int* а). выводящую в поток os значения из массива а (содержащего десять элементов).
/*
std::ostream &print_array(std::ostream &os, int *a, const int n){
    for(int i = 0; i < n; i++)
        os << a[i] << " ";
        return os;
}
std::cout << print_array(std::cout, name, 10);
*/
// 5. Разместите в динамической памяти массив, состоящий из десяти чисел типа int; инициализируйте его значениями 100, 101 , 102 и т.д.; выведите эти значения на печать.
// 6. Разместите в динамической памяти массив, состоящий из одиннадцати чисел типа int: инициализируйте его значениями 100, 101 , 102 и т.д. : выведите эти значения на печать.
// 8. Разместите в динамической памяти массив, состоящий из двадцати чисел типа int: инициализируйте его значениями 100, 101 , 102 и т.д. ; выведите эти значения на экран.
// 9. Вы не забыли удалить массивы? (Если забыли, сделайте это сейчас.)
#include <iostream>
int main(){
    int *name_0 = new int[10] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    int *name_1 = new int[11] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int *name_2 = new int[20] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
    for(int i = 0; i < 10; i++)
        std::cout << name_0[i] << " ";
    std::cout << "\n";
    for(int i = 0; i < 11; i++)
        std::cout << name_1[i] << " ";
    std::cout << "\n";
    for(int i = 0; i < 20; i++)
        std::cout << name_2[i] << " ";
    delete [] name_0;
    delete [] name_1;
    delete [] name_2;
    return 0;
}