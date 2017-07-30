/*3. 
Начните со следующего объявления структуры: 
struct chaff 
{ 
char dross[20]; 
int slag; 
); 
Напишите программу, которая использует операцию new с размещением, чтобы поместить массив из двух таких структур в буфер. 
Затем программа присваивает значения членам структуры (не забудьте воспользоваться функцией strcpy() для массива char) и отображает ее содержимое с помощью цикла. 
Вариант 1 предусматривает применение в качестве буфера памяти статического массива, как было показано в листинге 9.10. 
Вариант 2 состоит в использовании обычной операции new для выделения памяти под буфер. 
*/
#include <iostream>
#include <new>
#include <cstring>

struct chaff
{
    char dross[20];
    int slag;
};

int main(void)
{
    using namespace std;

    char *buffer = new char[sizeof(chaff) * 2];
    chaff *chaffs = new(buffer) chaff[2];

    strcpy(chaffs[0].dross, "Baus");
    chaffs[1].slag = 456;

    for(int i = 0; i < 2; i++)
    {
        cout << "--- Chaff ---" << endl;
        cout << "Dross: " << chaffs[i].dross << endl;
        cout << "Slag: " << chaffs[i].slag << endl;
        cout << endl;
    }
    delete [] buffer;
    return 0;
}