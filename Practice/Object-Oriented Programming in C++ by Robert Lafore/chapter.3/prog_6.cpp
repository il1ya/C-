/* 6. Измените программу factor, приведенную в этой главе, таким образом, чтобы она циклически запрашивала ввод пользователем числа и вычисляла его факториал, пока пользователь не введет 0. 
В этом случае программа должна завершиться. 
При необходимости вы можете использовать соответствующие операторы программы factor в цикле do или while. */
// factor.cpp
// подсчет факториала числа с помощью цикла for 
#include <iostream> 
using namespace std; 
int main()
{
    unsigned int numb;
    unsigned long fact = 1;         // тип long для результата
    do
    {
        cout << "Enter an integer: ";
        cin >> numb;                    // ввод числа
        for(int j = numb; j > 0; j--)   // умножение 1 на
        fact *= j;                  // numb, numb-1, ..., 2, 1
        cout << "The factorial of a number is " << fact << endl; 

    }while(numb != 0);
    return 0;
}