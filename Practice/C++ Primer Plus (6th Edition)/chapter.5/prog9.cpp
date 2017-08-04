/* Напишите программу, соответствующую описанию программы из упражнения 8, но с использованием объекта string вместо символьного массива. 
Включите заголовочный файл string и применяйте операции отношений для выполнения проверки. 
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(void)
{
    string name;
    int i = 0;
    cout << "Enter the word (for completion type the word done):";
    do
    {
        cin >> name;
        i++;
    }while(name != "done");
    cout << "You have entered " << i << " world" << endl;
    return 0;
}
