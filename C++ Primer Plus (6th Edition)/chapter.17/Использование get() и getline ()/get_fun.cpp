/*
Код в листинге 17.13 демонстрирует работу getline() и get(). В нем также представлена функция-член ignore(). 
Функция ignore() принимает два аргумента: число, указывающее максимальное количество символов для чтения, и символ, служащий разделителем при вводе. 
Например, следующий вызов функции считывает и отбрасывает следующие 255 символов или все символы вплоть до символа перевода строки, в зависимости от того, что произойдет раньше: 
cin.ignore(255, '\n'); 
Этот прототип предусматривает для своих двух аргументов значения по умолчанию 1 и EOF. Функция возвращает тип istream &: 
istream & ignore (int = 1, int = EOF); 
(Значение по умолчанию EOF вынуждает функцию ignore () считывать все символы вплоть до заданного количества или до конца файла, в зависимости от того, что случится раньше.) 
Функция возвращает вызывающий объект. Это позволяет выполнять конкатенацию вызовов функции, как в следующем операторе: 
cin.ignore(255, '\n')ignore(255, '\n'); 
В этом примере первый метод ignore () считывает и отбрасывает одну строку, а второй — вторую строку. Вместе эти две функции считывают две строки. 
Теперь взгляните на код в листинге 17.13. 
Листинг 17.13. get_fun.cpp */
// getfun.cpp — использование get() и getline() 
#include <iostream>
const int Limit = 255;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char input[Limit];

    cout << "enter a string for getline() processing:\n";       // запрос на ввод строки 
    cin.getline(input, Limit, '#');
    cout << "HEre is your input:\n";
    cout << input << "\nDone with phase 1\n";

    char ch;
    cin.get(ch);
    cout << "The next input character is " << ch << endl;
    if(ch != '\n')
        cin.ignore(Limit, '\n');    // отбрасывание остальной части строки 
    cout << "Enter a string for get() processing:\n";
    cin.get(input, Limit, '#');
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 2\n";

    cin.get(ch);
    cout << "The next input character is " << ch << endl;
    return 0;
}

// Обратите внимание, что функция getline() отбрасывает ограничивающий символ # во вводе, а функция get () — нет. 
