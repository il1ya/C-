/* 3. Пусть имеется следующее объявление структуры: 
struct box 
{ 
    char maker[40]; 
    float height; 
    float width; 
    float length; 
    float volume; 
}; 
а. Напишите функцию, принимающую структуру box по значению и отображающую все ее члены. 
б. Напишите функцию, принимающую адрес структуры box и устанавливающую значение члена volume равным произведению остальных трех членов. 
в. Напишите простую программу, которая использует эти две функции. 
*/

#include <iostream>
using namespace std;
struct box 
{ 
    char maker[40]; 
    float height; 
    float width; 
    float length; 
    float volume; 
};
void firststruct(box str);
void twoststruct(box *first);

int main(void)
{
    box first = { "Illya", 10, 05, 19, 91};
    box two = { "Now", 2, 0, 1, 7};
    firststruct(first);
    twoststruct(&two);
    return 0;
}



void firststruct(box str)
{
    cout << str.maker << endl;
    cout << str.height << "." << str.width << "." << str.length << str.volume << endl;
}

void twoststruct(box *first)
{
    cout << first->maker << endl;
    cout << first->height << first->width << first->length << first->volume << endl;
    cout << "End!";
}