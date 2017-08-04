/* Напишите программу, которая использует массив char и цикл для чтения но одному слову за раз до тех пор, пока не будет введено слово done. 
Затем программа должна сообщить количество введенных слов (исключая done). 
Пример запуска должен быть таким: 
Вводите слова (для завершения введите слово done): 
anteater birthday category dumpsteг 
envy finagle geometry done for sure 
Вы ввели 7 слов. 
Вы должны включить заголовочный файл cstring и применять функцию strcmp() для выполнения проверки. 
*/
#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
    char name[50];
    int i = 0;
    cout << "Enter the word (for completion type the word done):";
    do
    {
        cin >> name;
        i++;
    }while (strcmp(name, "done"));
    while(strcmp(name, "done") != 0);
    cout << "You have entered " << i << " world" << endl;
    return 0;
}
