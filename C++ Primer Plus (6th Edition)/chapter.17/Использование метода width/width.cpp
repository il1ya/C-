/*
Внимание! 
Метод width() оказывает влияние только на следующий отображаемый элемент, после чего восстанавливается значение поля по умолчанию. 
C++ никогда не усекает данные, поэтому при попытке вывода семизначного числа в двузначном поле C++ расширит это поле, чтобы вместить данные. 
(Некоторые языки заполняют поле звездочками, если ширина поля оказывается недостаточной для отображения данных. Разработчики C/C++ придерживаются подхода, в соответствии 
с которым отображение всех данных важнее сохранения аккуратного вида столбцов; 
C++ ставит на первое место сущность, а не форму.) Работа функции-члена width() 
продемонстрирована в листинге 17.4. 
Листинг 17.4. width.срр */
// width.срр — использование метода width 
#include <iostream>
int main()
{
    using std::cout;
    int w = cout.width(30);
    cout << "default field width = " << w << ":\n";     // ширина поля по умолчанию 
    cout.width(5);
    cout << "N" << ':';
    cout.width(8);
    cout << "N * N" << ":\n";
    for(long i = 1; i <= 100; i *= 10)
    {
        cout.width(5);
        cout << i << ':';
        cout.width(8);
        cout << "i * i" << ":\n";
    }
    return 0;
}
/*
Вывод отображает значения, выравнивая их по правому краю соответствующих полей. Поля вывода дополняются пробелами. 
То есть cout обеспечивает заданную ширину поля, добавляя пробелы. 
При выравнивании по правому краю пробелы вставляются слева от значений. 
Символ, используемый для дополнения поля, называется символом-заполнителем. 
По умолчанию устанавливается выравнивание по правому краю. 
Обратите внимание, что программа в листинге 17.4 применяет ширину поля, равную 30, к строке, отображенной первым оператором cout, но не к значению w. 
Это объясняется тем, что метод width() оказывает влияние только на следующий одиночный отображаемый элемент. 
Обратите также внимание, что w имеет значение 0. 
Это обусловлено тем, что cout.width(30) возвращает предыдущую ширину поля, а не ширину, в которую оно только что было установлено. 
То, что значение w равно 0, означает, что нуль — значение поля по умолчанию. 
Поскольку C++ всегда расширяет поле, чтобы оно вместило данные, этот единственный размер подходит для всех возможных случаев. 
И, наконец, программа использует width() для выравнивания заголовков столбцов и данных, используя ширину равную пяти символам для первого столбца и равную восьми символам — для второго. 
*/