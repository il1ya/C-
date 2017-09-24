/*
4. 
Начните с программы, которая позволяет пользователю вводить целые числа, а затем сохранять их в массиве типа int. 
Напишите функцию maxint(), которая, обрабатывая элементы массива один за другим, находит наибольший. 
Функция должна принимать в качестве аргумента адрес массива и количество элементов в нем, а возвращать индекс наибольшего элемента. 
Программа должна вызвать эту функцию, а затем вывести наибольший элемент и его индекс. 
(Смотрите программу SALES этой главы.) */

#include <iostream>
const int SIZE = 10;
int maxint(int []);

int main()
{
    char enter;
    do{
        int arr[SIZE];
        std::cout << "Enter 10 of integers: ";
        for(int i = 0; i < SIZE; i++){
            std::cin >> arr[i];
        }
        std::cout << "\nGreatest value: " << arr[maxint(arr)] << ", index into the array: " << maxint(arr);
        std::cout << "\ncontinue? (y/n): ";
        std::cin >> enter;
    }while(enter != 'n');
    std::cout << std::endl;
    return 0;
}

int maxint(int array[]){
    int max = 0, index = 0;
    for(int i = 0; i < SIZE; ++i){
        if(array[i] > max){
            max = array[i];
            index = i;
        }
    }
    return index;
}