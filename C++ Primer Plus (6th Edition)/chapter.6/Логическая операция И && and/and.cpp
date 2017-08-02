/* В листинге 6.5 демонстрируется использование && в стандартной ситуации, когда нужно прервать цикл while по двум разным причинам. 
В этом листинге цикл while читает значения в массив. Одно условие (і < ArSize) прерывает цикл, когда массив заполнен. 
Вторая (temp >= 0) предоставляет пользователю возможность прервать цикл раньше, введя отрицательное значение. 
Программа использует операцию &&, чтобы скомбинировать эти две проверки в одно условие. В программе также  
присутствуют два оператора if, один оператор if else и цикл for, т.е. иллюстрируется несколько тем из этой главы и главы 5. 
Листинг 6.5. and.cpp */
// and.cpp — использование логической операции "И" 
#include <iostream>
const int ArSize = 6;
int main(void)
{
    using namespace std;
    float naaq[ArSize];
    cout << "Enter the NAAQs (New Age Awareness Quotients)"
    << "of\nyour neighbors. Program terminates "
    << "when you make\n" << ArSize << " entries "
    << "or enter a negative value.\n";
    int i = 0;
    float temp;
    cout << "First value: "; // ввод первого значения 
    cin >> temp;
    while(i < ArSize && temp >= 0) // два критерия завершения 
    {
        naaq[i] = temp;
        ++i;
        if(i < ArSize)  // в массиве еще есть место 
        {
            cout << "Next value: ";
            cin >> temp; // ввод следующего значения 
        }
    }
        if(i == 0)
        cout << "No data--bye\n"; // данные отсутствуют 
        else
        {
            cout << "Enter your NAAQ: ";
            float you;
            cin >> you;
            int count = 0;
            for(int j = 0; j < i; j++)
            if(naaq[j] > you)
            ++count;
            cout << count;
            cout << " of your neighbors have greater awareness of\n"
            << "the New Age than you do.\n";
        }
    return 0;
}
/*
Обратите внимание, что программа в листинге 6.5 помещает вывод во временную переменную temp. 
И только после того, как введенное значение будет проверено, и станет ясно, что введено корректное значение, программа помещает новое значение в массив. 
*/