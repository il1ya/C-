/*1. 
Напишите функцию reversit(), которая переворачивает строку (массив типа char). 
Используйте цикл for, который меняет местами первый и последний символы, затем следующие и т. д. до предпоследнего. 
Строка должна передаваться в функцию reversit() как аргумент.
Напишите программу для выполнения функции reversit(). 
Программа должна принимать строку от пользователя, вызывать функцию reversit(), а затем выводить полученный результат. 
Используйте метод ввода, который позволяет использовать внутренние пробелы. 
Протестируйте программу на примере фразы «Аргентина манит негра».*/

#include <iostream>
#include <cstring> // для strlen()

const int SIZE = 100;
void reversit(char []);

int main()
{
    char array[SIZE];
    std::cout << "Enter string: ";
    std::cin.get(array, SIZE);
    reversit(array);
    std::cout << "Inverted string: " << array << std::endl;

    return 0;
}
void reversit(char arr[]){
    int len = strlen(arr);
    for(int i = 0; i < len / 2; i++){
        char temp = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = temp;
    }
}