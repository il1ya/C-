/*
4. Создайте класс employee, используя упражнение 4 главы 4. 
Класс должен включать поле типа int для хранения номера сотрудника и поле типа float для хранения величины его оклада. 
Методы класса должны позволять пользователю вводить и отображать данные класса. 
Напишите функцию main(), которая запросит пользователя ввести данные для трех сотрудников и выведет полученную информацию на экран. */
#include <iostream>
class Employee{
    private:
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
            //show();
        }
        void show() const{
            std::cout << "Worker number: " << number << "\nWorker salary: $" << salary << std::endl;
        }
};
int main()
{
    Employee wk1, wk2, wk3;
    wk1.input();
    wk2.input();
    wk3.input();
    std::cout << "Your input\n";
    wk1.show();
    wk2.show();
    wk3.show();
    return 0;
}