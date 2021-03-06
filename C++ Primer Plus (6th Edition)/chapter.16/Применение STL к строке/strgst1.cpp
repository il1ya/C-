/* 
Класс string, хотя и не является частью библиотеки STL, спроектирован с учетом ее наличия. 
Так, например, он имеет функции-члены begin(), end(), rbegin() и rend(). 
Это значит, что он может работать с интерфейсом STL. 
Код в листинге 16.17 использует STL для отображения всех возможных  перестановок букв слова. 
Перестановка — это изменение порядка следования элементов в контейнере. Алгоритм next_permutation() преобразует содержимое диапазона в следующую перестановку; 
в случае строки перестановки выполняются в возрастающем алфавитном порядке. 
Алгоритм возвращает true при успешном продолжении и false — в ситуации, когда порядок следования элементов в диапазоне является последним из возможных. 
Чтобы получить все перестановки диапазона, следует начать с элементов, расположенных в самом первом возможном порядке, и с этой целью в программе используется алгоритм sort() из библиотеки STL. 
Листинг 16.17. strgstl.cpp 
*/
// strgstl.cpp -- применение STL к строке 

#include <iostream>
#include <string>
#include <algorithm>
int main()
{
    using namespace std;
    string letters;
    cout << "Enter the letter grouping (quit to quit): ";   // ввод группы букв 
    while(cin >> letters && letters != "quit")
    {
        cout << "Permutations of " << letters << endl;      // перестановки группы букв 
        sort(letters.begin(), letters.end());
        cout << letters << endl;
        while(next_permutation(letters.begin(), letters.end()))
            cout << letters << endl;
            cout << "Enter next sequence (quit to quit): "; // ввод следующей группы букв 
    }
    cout << "Done.\n";
    return 0;
}
/*
Обратите внимание, что алгоритм next_permutation() автоматически обеспечивает генерацию только уникальных перестановок — вот почему для слова a wl показано больше 
перестановок, чем для слова all, в котором присутствуют повторяющиеся буквы. 
*/