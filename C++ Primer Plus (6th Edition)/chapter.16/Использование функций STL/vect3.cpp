/* Обратите внимание, что функция WorseThan(). сортирует объекты Review менее точно, чем operator<(). 
Если член title объектов совпадает, функция operator<() осуществляет сортировку по полю rating. 
Но если и эти два поля объектов совпадают, функция WorseThan() считает их эквивалентными. 
Первый вид упорядочения называется полным упорядочением, а второй — строгим квазиупорядочением. При полном упорядочении, если оба выражения а< Ь и Ь< а ложны, то а должно быть идентично Ъ. 
При строгом квазиупорядочении это не так. Объекты могут быть полностью идентичными, а могут совпадать только по одному критерию, такому,как поле rating в примере с функцией WorseThan(). 
Поэтому при строгом квазиупорядочении лучше говорить, что объекты эквивалентны, а не идентичны. Использование этих функций STL продемострировано в листинге 16.9. 
Листинг 16.9. vect3.срр */
// vect3.cpp — использование функций STL 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct Review {
    std::string title;
    int rating;
};
bool operator>(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);
int main()
{
    using namespace std;
    vector<Review> books;
    Review temp;
    while(FillReview(temp))
    books.push_back(temp);
    if(books.size() > 0)
    {
        cout << "Thank you. You entered the following " << books.size() << " ratings:\n" << "Rating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\n"; 
            // Список книг, отсортировванный по названию 
        for_each(books.begin(), books.end(), ShowReview);
        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\n";
            // Список книг после перемешивания 
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
        cout << "Bye.\n";
        return 0;
}
bool operator<(const Review & r1, const Review & r2)
{
    if(r1.title < r2.title)
        return true;
    else if(r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}
bool worseThan(const Review &r1, const Review & r2)
{
    if(r1.rating < r2.rating)
        return true;
    else
        return false;
}
bool FillReview(Review &rr)
{
    std::cout << "Enter book title (quit to quit): ";
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