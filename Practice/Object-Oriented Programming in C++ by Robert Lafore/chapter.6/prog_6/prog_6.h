#include <iostream>
#include <string>
class Employee{
    private:
        enum etype {Laboratory_assistant, secretary, manager};
        int number;
        float salary;
    public:
        Employee() : number(0), salary(0){
        }
        Employee(int num, float sal) : number(num), salary(sal){
        }
        void input(){
            std::cout << "Enter worker number: ";
            std::cin >> number;
            std::cout << "Enter salary: ";
            std::cin >> salary;
            // getemploy();
            // show();
        }
        void show() const{
            std::cout << "Worker number: " << number << "\nWorker salary: $" << salary << std::endl;
        }
        void getemploy(){
            etype e1;
            std::string enter;
            std::cout << "Enter type of employee(Laboratory_assistant, secretary, manager): ";
            std::cin >> enter;
            if(enter == "Laboratory_assistant"){
                e1 = Laboratory_assistant;
                std::cout << "0- Laboratory_assistant.\n";
            }else if(enter == "secretary"){
                e1 = secretary;
                std::cout << "1- secretary.\n";
            }else if(enter == "manager"){
                e1 = manager;
                std::cout << "2- manager.\n";
            }
            //std::cout << "\nPosition (0- Laboratory_assistant, 1- secretary, 2- manager): " << e1;
        }
        void putemploy(){

        }
        ~Employee(){
        }
};
class Date{
private:
    int month;
    int day;
    int year;
public:
    Date() : month(0), day(0), year(0){
    }
    Date(int m, int d, int y) : month(m), day(d), year(y){
    }
    void getdate(){
        std::cout << "Month ";
        std::cin >> month;
        std::cout << "Day ";
        std::cin >> day;
        std::cout << "Year ";
        std::cin >> year;
    }
    void showdate() const{
        std::cout << month << "/" << day << "/" << year << std::endl;
    }
    ~Date(){
    }
};