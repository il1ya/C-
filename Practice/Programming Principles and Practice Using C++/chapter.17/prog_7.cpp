/*7. 
Напишите программу считывающую символы из потока cin в массив, выделенный в динамической памяти. 
Читайте отдельные символы, пока не встретится восклицательный знак (!). 
Не используйте класс std::string и не беспокойтесь об исчерпании памяти. 
*/
#include <iostream>
char *func(char *, int);
int main()
{
    char *block = new char[0];
    char enter_0;
    int enter_1 = 0;
    while(std::cin >> enter_0 && enter_0 != '!'){
        block = func(block, 1);
        enter_1++;
        block[enter_1-1] = enter_0;
    }
        for(int i = 0; block[i]; ++i)
            std::cout << block[i];
            std::cout << std::endl;
            delete [] block;
    return 0;
}

char *func(char *a, int b){
    int i = 0;
    while(a[i] != '\0')
        i++;
    char *mas = new char[i + b + 1];
    for(int d = 0; a[d]; ++d)
        mas[d] = a[d];
        mas[i + b + 1] = '\0';
        delete[] a;
        return mas;
}