/* Класс map обладает интересной особенностью: для получения доступа к хранимым значениям можно использовать нотацию массивов с ключами в качестве индексов. 
Например, wordmap ["the"] представляло бы значение, связанное с ключом "the", что в данном случае означает количество появлений строки "the" во введенном тексте. 
Поскольку контейнер wordset содержит все ключи, используемые wordmap, следующий код может выступать альтернативным и более привлекательным способом для сохранения результатов: 
for(si = wordset.begin(); si != wordset.end(); si++) 
wordmap[*si] = count(words.begin(), words.end(), *si); 
Так как si указывает на строку в контейнере wordset, *si — это строка, которая может служить ключом для wordmap. 
Этот код помещает ключи и значения в карту wordmap. Аналогично, нотацию массивов можно применить для выдачи результатов: 
for (si = wordset.begin(); si != wordset.end(); si ++) 
cout << *si << ": " << wordmap[*si] << endl; 
Если ключ является недопустимым, то соответствующее ему значение будет равно 0. 
Программа, представленная в листинге 16.19, объединяет эти идеи и включает в себя код для отображения содержимого этих трех контейнеров 
(вектора с вводом, набора со списком слов и карты с числом слов). 
Листинг 16.19. usealgo.срр */
// usealgo.срр -- использование нескольких элементов STL 
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;

char toLower(char ch)
{
    return tolower(ch);
}
string &ToLower(string &st);
void display(const string &s);
int main()
{
    vector<string> words;
    cout << "Enter words (enter quit to quit):\n";  // запрос на ввод слов 
    string input;
    while(cin >> input && input != "quit")
        words.push_back(input);

    cout << "You entered the following words:\n";   // отображение введенных слов 
    for_each(words.begin(), words.end(), display);
    cout << endl;

    // Помещение слов в набор с преобразование букв в строчные 
    set<string> wordset;
    transform(words.begin(), words.end(), insert_iterator<set<string> > (wordset, wordset.begin()), ToLower);
    cout << "\nAlphabetic list of words:\n";        // список слов в алфавитном порядке 
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    // Помещение и частоты его помещения в карту
    map<string, int> wordmap;
    set<string>::iterator si;
    for(si = wordset.begin(); si != wordset.end(); si++)
        wordmap[*si] = count(words.begin(), words.end(), *si);
    
    // Отображение содержимого карты 
    cout << "\nWord frequency:\n";                  // частота появления слов 
    for(si = wordset.begin(); si != wordset.end(); si++)
        cout << *si << ": " << wordmap[*si] << endl;
        return 0;
}

string &ToLower(string &st)
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

void display(const string & s)
{
    cout << s << " ";
}
/* 
Мораль этой демонстрации в том, что при использовании STL следует максимально избегать написания собственного кода. 
Обобщенное и гибкое проектное решение, положенное в основу STL, должно сэкономить массу работы. 
Кроме того, разработчики STL — люди, мыслящие алгоритмически и стремящиеся к высокой эффективности. 
Таким образом, алгоритмы хорошо подобраны и отлажены. 
*/