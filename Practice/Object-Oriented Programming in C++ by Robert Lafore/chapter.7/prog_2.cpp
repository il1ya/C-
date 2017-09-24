/*
Создайте класс employee, который содержит имя (объект класса string) и номер (типа long) служащего. 
Включите в него метод getdata(), предназначенный для получения данных от пользователя и помещения их в объект, и метод putdata(), для вывода данных. 
Предполагаем, что имя не может иметь внутренних пробелов.
Напишите функцию main(), использующую этот класс. Вам нужно будет создать массив типа employee, а затем предложить пользователю ввести данные до 100 служащих. 
Наконец, вам нужно будет вывести данные всех служащих.
*/
#include <iostream>
#include <iomanip> // std::setw() 

class Employee{
    private:
        std::string name;
        long number;
    public:
        Employee(): name(""), number(0){}
        Employee(std::string n, long num): name(n), number(num){}
        void getdats(){
            std::cin >> name;
            std::cin >> number;
        }
        void putdata(){
            std::cout << "Name: " << name << " "<<  number << std::endl;
        }
        ~Employee(){}
};

int main()
{
    Employee employee[100];
    int i = 0;
    char enter;
    do{
        std::cout << "Enter the name and number of the employee: " << std::endl;
        employee[i++].getdats();
        std::cout << "Continue? (y/n)" << std::endl;
        std::cin >> enter;
    }while(enter != 'n');
        std::cout << "Your employees:\n";
        for(int j = 0; j < 100; j++){
            employee[j].putdata();
        }
        std::cout << std::endl;
    return 0;
}