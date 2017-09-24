/*1. 
Представьте себе издательскую компанию, которая торгует книгами и аудиозаписями этих книг. 
Создайте класс publication, в котором хранятся название (строка) и цена (типа float) книги. 
От этого класса наследуются еще два класса: book, который содержит информацию о количестве страниц в книге (типа int), 
и type, который содержит время записи книги в минутах (тип float). 
В каждом из этих трех классов должен быть метод getdata(), через который можно получать данные от пользователя с клавиатуры, и putdata(), 
предназначенный для вывода этих данных.
Напишите функцию main() программы для проверки классов book и type. 
Создайте их объекты в программе и запросите пользователя ввести и вывести данные с использованием методов getdata() и putdata(). */
#include <iostream>
class Publication{
private:
    std::string book;
    float price;
public:
    Publication(std::string b, float p): book(b), price(p){}
    Publication(): book(""), price(0.0){}
    void getdata(){
        std::cout << "Enter name book: ";
        std::cin >> book;
        std::cout << "Enter " << book << " price: ";
        std::cin >> price;
    }
    void putdata() const{
        std::cout << "Ur book: " << book << "\nPrice: " << price << std::endl;
    }
};

class Book: public Publication{
private:
    int book;
public:
    Book(int b): book(b){}
    Book(): book(0){}
    void getdata(){
        Publication::getdata();
        std::cout << "Enter number book: ";
        std::cin >> book;
    }
    void putdata() const{
        Publication::putdata();
        std::cout << "Ur number of book: " << book << std::endl;
    }
};

class Type: public Publication{
private:
    float time;
public:
    Type(float t): time(t){}
    Type(): time(0.0){}
    void getdata(){
        Publication::getdata();
        std::cout << "Enter time: ";
        std::cin >> time;
    }
    void putdata() const{
        Publication::putdata();
        std::cout << "Ur time: " << time << std::endl;
    }
};

int main()
{
    Book book1;
    Type type1;
    book1.getdata();
    book1.putdata();
    type1.getdata();
    type1.putdata();
    return 0;
}