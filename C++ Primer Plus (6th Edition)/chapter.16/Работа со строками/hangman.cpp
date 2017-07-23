/*Библиотека string также предоставляет связанные методы rfind(), findfirst_ of(), find_last_of(), find_first_not_of() и find_last_not_of(), 
каждый из которых имеет тот же набор сигнатур перегруженных функций, что и метод find(). 
Метод rfind() находит последнее вхождение подстроки или символа. 
Метод find_first_of() отыскивает первое вхождение в строке любого из символов, переданных в аргументах метода. 
Например, следующий оператор вернет позицию символа г в строке "cobra" (3), поскольку это первое вхождение любого из символов строки "hark" в строке "cobra": 
int where = snakel.find_first_of("hark"); 
Метод find_last_of() работает аналогично, только находит последнее вхождение. 
Поэтому следующий оператор вернет позицию символа а в строке "cobra": 
int where = snakel.last_first_of("hark"); 
Метод f ind_first_not_of() находит первый символ в вызывающей строке, который отличается от символа, переданного в аргументе. 
Таким образом, приведенный ниже оператор вернет позицию символа с в cobra, поскольку символ с не найден в hark: 
int where = snakel.find_first_not_of("hark"); 
(Примеры использования find_last_not_of() будут приведены в упражнениях в конце этой главы.) 
Существует множество других методов, однако описанных выше достаточно для создания игровой программы — упрощенной версии игры "Палач" 
(детская игра в слова; при неправильном ответе игрок рисует одну за другой части виселицы с повешенным). 
Программа хранит список слов в массиве объектов string, выбирает одно слово случайным образом и предлагает игроку угадать буквы в слове. 
Шесть неудачных попыток означают проигрыш. 
В программе используется функция find() для проверки попыток и операция += для создания объекта string, в котором хранятся неудачные попытки. 
Для отслеживания удачных попыток, в программе создастся слово такой же длины, что и загаданное, но состоящее из дефисов. 
При удачной попытке дефис заменяется угаданной буквой. Код программы приведен в листинге 16.3. 
Листинг 16.3. hangman.cрр */
// hangman.ерр — использование некоторых методов работы со строками 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using std::string;
const int NUM = 26;
const string wordlist[NUM] = {"apiary", "beetle", "cereal", "danger", "ensign", "florid", 
"garage", "health", "insult", "jackal", "keeper", "loaner", "manage", "nonce", "onset", 
"plaid", "quilt", "remote", "stolid", "train", "useful", "valid", "whence", "xenon", "yearn", "zippy"}; 

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n>";  // запуск игры в слова 
    cin >> play;
    play = tolower(play);
    while(play == 'y')
    {
        string target = wordlist[std::rand() % NUM];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length << " letters, and you quess\n" << "one letter at a time. You get " << guesses << " wrong quesses.\n";
        cout << "Your word: " << attempt << endl;   // вывод слова 
        while(guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if(badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if(loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;  // добавить к строке 
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                // Проверить, не появляется ли буква еще раз 
                loc = target.find(letter, loc + 1);
                while(loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
                cout << "Your word: " << attempt << endl;
                if(attempt != target)
                {
                    if(badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                    cout << guesses << " bad guesses left\n";
                }
            }
            if(guesses > 0)
                cout << "That's right!\n";
                else
                cout << "Sorry, the word is " << target << "\n";
                cout << "Will you play another? <y\n> ";
                cin >> play;
                play = tolower(play);
        }
        cout << "Bye\n";
        return 0;
    }
}
/*
Замечания по программе 
В программе 16.3 перегрузка операций отношения позволяет работать со строками так же, как с числовыми переменными: 
while(guesses > 0 && attempt != target) 
Такой подход проще, нежели использование, например, функции strcmp() со строками в стиле С. 
Программа применяет find() для проверки на повторное использование символа; если символ уже вводился, то он будет присутствовать либо в 
строке badchars (неудачные попытки), либо в строке attempt (удачные попытки): 
if(badchars.find(letter) != string::npos || attempt.find(lettter) != string::npos)
Переменная npos — это статический член класса string. Вспомните, что это — максимально возможное количество символов в объекте string. 
Поскольку нумерация символов в строке начинается с нуля, то это значение на единицу больше, чем максимально возможная позиция символа, и может использоваться для индикации 
неудачного поиска символа в строке. 
Также в программе используется перегруженная операция += для добавления символов к строке: 
badchars += letter; // добавление символа к объекту string 
Основная часть программы начинается с проверки на наличие введенного символа в загаданном слове: 
int loc = target.find(letter); 
Если переменная Іос имеет допустимое значение, буква может быть помещена в соответствующую позицию строки ответа: 
attempt[loc]=letter; 
Однако данная буква символ может встречаться в загаданном слове несколько раз, поэтому программе приходится продолжать проверку. 
В программе используется необязательный второй аргумент функции find(), указывающий начальную позицию в строке, с которой нужно начинать поиск. 
Поскольку буква была найдена в позиции Іос, следующий поиск должен начаться с позиции Іос + 1.
Цикл while будет повторять поиск до тех пор, пока не будет найдено больше ни одного вхождения символа. 
Обратите внимание, что find() сообщит об ошибке, если значение Іос превысит длину строки: 
// Проверка того, не появляется ли буква снова 
                loc = target.find(letter, loc + 1);
                while(loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
                */