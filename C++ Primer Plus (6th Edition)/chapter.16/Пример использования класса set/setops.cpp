/* Два удобных метода set — это lower_boind() и upper_bound(). Метод lower_ boind() принимает значение типа ключа в качестве аргумента и возвращает  
итератор, указывающий на первый член набора, который не меньше ключевого аргумента. 
Аналогично, upper_bound() принимает ключ в качестве аргумента и возвращает итератор, указывающий на первый член набора, который больше ключевого аргумента. 
Например, если имеется набор строк, эти методы можно применять для определения диапазона, включающего все строки в наборе от "Ь" до " f". 
Поскольку сортировка определяет, куда будут помещаться добавления к набору, класс имеет методы, которые лишь указывают добавляемые данные без указания позиции. 
Например, если А и В — наборы строк, можно использовать следующий код: string s("tennis"); 
A.insert(s);                    // вставка значения 
В.insert(A.begin О, A.endO);    // вставка диапазона значений 
Эти применения наборов иллюстрируются в листинге 16.13. 
*/
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
int main()
{
    using namespace std;
    const int N = 6;
    string s1[N] = {"buffon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};

    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);

    ostream_iterator<string, char> out(cout, " ");
    cout << "Set A: ";                      // набор А 
    copy(A.begin(), A.end(), out);
    cout << endl;
    cout << "Set B: ";                      // набор В 
    copy(B.begin(), B.end(), out);
    cout << endl;

    cout << "Union of A and B:\n";          // объединение А и В 
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Interesection of A and B:\n";  // пересечение А и В 
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Difference of A and B:\n";     // разность А и В 
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("grungy");
    C.insert(s3);
    cout << "Set C after insertion:\n";     // набор С после вставки 
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showin a range:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;
    return 0;
}
/*
Подобно большинству примеров в настоящей главе, код в листинге 16.13 применяет "ленивый" способ объявления пространства имен std: 
using namespace std; 
Это делается с целью упрощения представления. В приведенных примерах используется настолько много элементов из пространства имен std, что применение  
директив или операций разрешения контекста придало бы коду несколько громоздкий вид: 
std::set<std::string> B(s2, s2 + N); 
std::ostream_iterator<std::string, char> out(std::cout, " "); 
std::cout « "Set A: "; 
std: :copy (A.begin() , A.endO, out); 
*/