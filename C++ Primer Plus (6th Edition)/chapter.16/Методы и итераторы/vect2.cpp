/* Код в листинге 16.8 иллюстрирует применение методов size(), begin(), end(), push_back(), erase() и insert(). 
Для упрощения работы с данными компоненты rating и title объединены в одну структуру Review, а функции FillReview() и ShowReview() предоставляют возможности ввода и вывода для объектов Review. 
Листинг 16.8. vect2.срр */
// vect2.срр — методы и итераторы 
#include <iostream>
#include <string>
#include <vector>
struct Review{
    std::string title;
    int rating;
};
bool FillReview(Review &rr);
void ShowReview(const Review & rr);
int main()
{
    using std::cout;
    using std::vector;
    vector<Review> books;
    Review temp;
    while(FillReview(temp))
        books.push_back(temp);
        int num = books.size();
        if(num > 0)
        {
            cout << "Thank you. You entered the following:\n" << "Rating\tBook\n";
            for(int i = 0; i < num; i++)
                ShowReview(books[i]);
                cout << "Reprising:\n" << "Rating\tBook\n";
                vector<Review>::iterator pr;
                for(pr = books.begin(); pr != books.end(); pr++)
                    ShowReview(*pr);
                vector<Review> oldlist(books);  // использование конструктора копирования 
                if(num > 3)
                {
                    // Удаление двух элементов 
                    books.erase(books.begin() + 1, books.begin() + 3);
                    cout << "After erasure:\n";
                    for(pr = books.begin(); pr != books.end(); pr++)
                        ShowReview(*pr);
                        // Вставка одного элемента 
                        books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
                        cout << "After insertion:\n";
                        for(pr = books.begin(); pr != books.end(); pr++)
                            ShowReview(*pr);
                }
                books.swap(oldlist);
                cout << "Swapping oldlist with books:\n";
                for(pr = books.begin(); pr != books.end(); pr++)
                    ShowReview(*pr);
        }
        else
            cout << "Nothing entered, nothing gained.\n";
            return 0;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title(quit to quit): ";
    std::getline(std::cin, rr.title);
    if(rr.title == "quit")
        return false;
        std::cout << "Enter book rating: ";
        std::cin >> rr.rating;
        if(!std::cin)
            return false;

        // Избавиться от остальной части строки ввода 
        while(std::cin.get() != '\n')
            continue;
            return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}