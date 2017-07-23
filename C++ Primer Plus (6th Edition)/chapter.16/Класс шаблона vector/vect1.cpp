/* Применение класса vector в достаточно непритязательном приложении продемонстрировано в листинге 16.7. 
Эта программа создает два объекта vector, один из которых содержит элементы типа int, а второй — string. 
В каждом объекте находится по 5 элементов. 
Листинг 16.7. vectl.срр */
// vectl.срр — пример работы с шаблоном vector 
#include <iostream>
#include <string>
#include <vector>
const int NUM = 5;
int main()
{
    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<int> ratings(NUM);
    vector<string> titles(NUM);
    cout << "You will do exactly as told. You will enter\n" << NUM << " book titles and your ratings (0-10).\n"; // запрос книг и их рейтингов 
    int i;
    for(i = 0; i < NUM; i++)
    {
        cout << "Enter title #" << i + 1 << ": ";   // ввод названия книги 
        getline(cin, titles[i]);
        cout << "Enter your rating (0-10): ";       // ввод рейтинга книги 
        cin >> ratings[i];
        cin.get();
    }
    cout << "Thank you. You entered the following:\n" << "Rating\tBook\n";
    for(i = 0; i < NUM; i++)                        // вывод списка книг с рейтингами 
    {
        cout << ratings[i] << "\t" << titles[i] << endl;
    }
    return 0;
}

/*
Все, что делает эта программа — использует шаблон vector в качестве удобного средства создания динамического массива. В следующем разделе будет показан пример применения других методов этого класса. */
