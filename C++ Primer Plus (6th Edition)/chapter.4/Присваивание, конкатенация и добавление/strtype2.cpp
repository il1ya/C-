/* В листинге 4.8 приведен соответствующий пример. Обратите внимание, что складывать и добавлять к объектам string можно как другие объекты string, так и строки в стиле С. */
// Листинг 4.8. strtype2.срр 
// strtype2.cpp -- присваивание, сложение, добавление 
#include <iostream>
#include <string>   // обеспечение доступа к классу string 
int main(void)
{
    using namespace std;
    string s1 = "penguin";
    string s2, s3;
    // Присваивание одного объекта string другому 
    cout << "You can assign one string object to another: s2 = s1\n";
    s2 = s1;
    cout << "s1: " << s1 << ", s2:" << s2 << endl;
    // Присваивание строки в стиле С объекту string 
    cout << "You can assing a C-style string to a string object.\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";
    cout << "s2: " << s2 << endl;
    // Конкатенация строк 
    cout << "You can concatenate strings: s3 = s1 + s2\n";
    s3 = s1 + s2;
    cout << "s3: " << s3 << endl;
    // Добавление строки 
    cout << "You can append strings.\n";
    s1 += s2;
    cout << "s1 += s2 yields s1 = " << s1 << endl;
    s2 += " for a day";
    cout << "s2 += \" for a day\" yields s2 = " << s2 << endl;
    return 0;
}