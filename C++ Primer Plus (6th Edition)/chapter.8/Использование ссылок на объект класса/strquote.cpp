/*
В языке C++ для передачи функциям объектов классов обычно практикуется использование ссылок. 
Например, ссылочные параметры применяются в функциях, принимающих объекты классов string, ostream, istream, ofstream и ifstream в качестве аргументов. 
Рассмотрим пример, в котором используется класс string, а также демонстрируются различные решения, в том числе неудачные. 
Замысел состоит в том, чтобы создать функцию, которая добавляет заданную строку к обеим сторонам другой строки. 
В листинге 8.7 представлены три функции, предназначенные для решения этой задачи. 
Однако одно из решений настолько ошибочное, что может привести к сбою программы или даже отказу компиляции. 
Листинг 8.7. strquote.срр */
// strquote.cpp — различные решения 
#include <iostream>
#include <string>
using namespace std;
string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2); // имеет побочный эффект 

const string & version3(string & s1, const string & s2); // неудачное решение 
int main(void)
{
    string input;
    string copy;
    string result;
    cout << "Enter a string: ";
    getline(cin, input); // ввод строки 
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***"); // отображение выведенной строки 
    cout << "Your string enhanced: " << result << endl;
         // вывод расширенной строки 
    cout << "Your original string: " << input << endl;
         // вывод исходной строки 
    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
         // вывод расширенной строки 
    cout << "Your original string: " << input << endl;
         // вывод исходной строки 
    cout << "Resetting original string.\n";
         // восстановление исходной строки 
    input = copy;
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
         // вывод расширенной строки 
    cout << "Your original string: " << input << endl; // вывод исходной строки 
    return 0;
}

string version1(const string & s1, const string & s2)
{
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}

const string & version2(string & s1, const string & s2) // имеет побочный эффект 
{
    s1 = s2 + s1 + s2;
    // Возврат ссылки, переданной функции, безопасен 
    return s1;
}

const string & version3(string & s1, const string & s2) // неудачное решение 
{
    string temp;
    temp = s2 + s1 + s2;
    // Возврат ссылки на локальную переменную небезопасен 
    return temp;
}
/*
Ниже показан пример выполнения программы из листинга 8.7: 
Enter a string: It's not ray fault. 
Your string as entered: It's not my fault. 
Your string enhanced: ***It's not my fault.*** 
Your original string: It's not my fault. 
Your string enhanced: ###It's not my fault.### 
Your original string: ###It's not my fault.###
Resetting original string. 
В этой точке программа дает сбой. 
*/