/* А как насчет получения информации об объекте multimap? 
Функция-член count() принимает в качестве аргумента ключ и возвращает количество элементов, имеющих такое значение ключа. Функции-члены lower_bound() и upper_bound() принимают ключ и работают так же, как в классе set. 
Функция-член equal_range() также принимает в качестве аргумента ключ и возвращает итераторы, представляющие диапазон значений, соответствующих этому ключу. 
Чтобы вернуть два значения, метод упаковывает их в один объект pair, на этот раз с обоими аргументами шаблона — итераторами. 
Например, следующий код выведет список городов из объекта codes, у которых код региона равен 718: 
pair<multimap<KeyType, string>::iterator, 
multimap<KeyType, string>::iterator> range = codes.equal_range(718); 
cout « "Cities with area code 718:\n"; 
std::multimap<KeyType, std::string>::iterator it; 
for(it = range, first; it != range. second; ++it) 
cout << (*it) .second << endl; 
Объявления, подобные приведенному выше, способствовали появлению средства автоматического выведения типа С++11, которое позволяет упростить код следующим образом: 
auto range = codes.equal_range(718); 
cout « "Cities with area code 718:\n"; 
for (auto it = range, first; it != range. second; ++it) 
cout << (*it) .second « endl; 
В листинге 16.14 демонстрируется применение большей части описанных методик. 
В нем также используется typedef для упрощения написания кода. 
Листинг 16.14. multimap.срр */
// multimap.срр -- использование multimap 
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
    using namespace std;
    MapCode codes;
    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Staten Island"));
    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Berkeley"));

    cout << "Number of cities with area code 415: " << codes.count(415) << endl;    // количество городов с кодом региона 415 
    cout << "Number of cities with area code 718: " << codes.count(718) << endl;    // количество городов с кодом региона 718 
    cout << "Number of cities witch area code 510: " << codes.count(510) << endl;   // количество городов с кодом региона 510
    cout << "Area Code City\n";
    MapCode::iterator it;
    for(it = codes.begin(); it != codes.end(); ++it)
        cout << " " << (*it).first << " " << (*it).second << endl;
    pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
    cout << "Cities with area code 718:\n";
    for(it = range.first; it != range.second; ++it)
    cout << (*it).second << endl;
    return 0;
}