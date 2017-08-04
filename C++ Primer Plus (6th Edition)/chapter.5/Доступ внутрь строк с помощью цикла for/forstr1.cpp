/* Цикл for предоставляет прямой способ доступа к каждому символу в строке. 
Например, программа в листинге 5.6 позволяет ввести строку и отобразить ее символ за символом в обратном порядке. В этом примере можно использовать либо объект 
класса string, либо массив char, потому что оба позволяют применять нотацию массивов для доступа к индивидуальным символам строки. 
В листинге 5.6 применяется объект класса string. Метод size() класса string возвращает количество символов в строке; цикл использует это значение в выражении инициализации для установки і 
в индекс последнего символа строки, исключая нулевой символ. Для выполнения обратного отсчета в программе применяется операция декремента (--), уменьшающая 
значение индекса массива на каждом шаге цикла. 
Также в листинге 5.6 используется операцию сравнения "больше или равно" (>=), чтобы проверить, достигли цикл первого элемента. Чуть позже мы подведем итог по всем операциям сравнения. 
Листинг 5.6. f orstrl.срр */
// forstrl.cpp -- использование цикла for для строки 
#include <iostream>
#include <string>
int main(void)
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;
    // Отображение символов в обратном порядке 
    for(int i = word.size() - 1; i >= 0; i--)
    cout << word[i];
    cout << "\nBye.\n";
    return 0;
}
