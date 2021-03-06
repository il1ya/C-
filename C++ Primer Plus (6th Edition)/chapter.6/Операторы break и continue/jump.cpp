/* В листинге 6.12 демонстрируется работа этих двух операторов. 
Программа позволяет ввести строку текста. Цикл отображает каждый ее символ и использует break, чтобы завершить цикл, если очередной символ строки окажется точкой. 
Это показывает, как с помощью break прервать цикл изнутри, если некоторое условие окажется истинным. 
Далее программа подсчитывает пробелы, пропуская остальные символы. 
Здесь в цикле используется continue, чтобы пропустить оставшуюся часть цикла, если окажется, что символ не является пробелом. 
Листинг 6.12. jump.срр */
// jump.срр -- использование операторов continue и break 
#include <iostream>
const int ArSize = 80;
int main(void)
{
    using namespace std;
    char line[ArSize];
    int spaces = 0; 
    cout << "Enter a line of text:\n";          // запрос на ввод строки текста 
    cin.get(line, ArSize);
    cout << "Complete line:\n" << line << endl; // вывод полной строки 
    cout << "Line through first period:\n";     // вывод строки до первой точки 
    for(int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];                        // отображение символа 
        if(line[i] == '.')                      // завершение, если это точка 
        break;
        if(line[i] != ' ')
        continue;
        spaces++;
    }
    cout << "\n" << spaces << " spaces\n";
    cout << "Done.\n";
    return 0;
}
/*
Замечания по программе 
Обратите внимание, что в то время как оператор continue вынуждает программу из листинга 6.12 пропустить оставшуюся часть тела цикла, он не пропускает выражение обновления цикла. 
В цикле for оператор continue заставляет программу перейти непосредственно к выражению обновления, а затем — к проверочному выражению. 
В цикле while, однако, continue заставляет программу сразу выполнить проверочное условие. 
Поэтому любое обновляющее выражение в теле цикла while, которое следует за continue, будет пропущено. 
В некоторых случаях это может приводить к проблемам. 
В этой программе можно было бы обойтись без continue. Вместо этого можно было бы использовать следующий код: 
if (line[i] == ' ') 
spaces++; 
Однако оператор continue может сделать программу более читабельной, когда за continue следует несколько операторов. 
В таком случае нет необходимости делать. эти операторы частью if. 
В C++, как и в С, присутствует оператор goto. Следующий оператор означает, что нужно перейти в место, помеченное меткой paris :: 
goto paris; 
То есть в программе может присутствовать следующий код: 
char ch; 
cin >> ch; 
if (ch == 'P') 
goto paris; 
cout «... 
paris: cout << "You've just arrived at Paris.\n"; 
В большинстве случаев (некоторые скажут — во всех случаях) применение goto — неудачное решение, 
и для управления потоком выполнения программы вы должны стараться применять структурные управляющие конструкции вроде if else, switch, continue и т.п. 
*/