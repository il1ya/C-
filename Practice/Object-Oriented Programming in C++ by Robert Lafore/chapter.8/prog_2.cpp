/**2. 
Напишите программу, которая заменяет перегруженную операцию + на перегруженную операцию += в программе STRPLUS этой главы. 
Эта операция должна позволять записывать выражения типа:
s1 += s2;
где s2 прибавляется (объединяется) к строке s1, результат при этом остается в s1. 
Операция должна также позволять использовать результат для других вычислений, например в выражениях типа s3 = s1 += s2; */
#include <iostream>
#include <cstring>
class Class{
    private:
        enum {SZ = 80};
        char str[SZ];
    public:
        Class()
        {strcpy(str, "");}
        Class(char s[])
        {strcpy(str, s);}
        void display() const{
            std::cout << str;
        }
        Class operator+=(Class ss){
            Class temp;
            if(strlen(str) + strlen(ss.str) < SZ){
                std::cout << "\nOverflow String";
            }
            strcat(str, ss.str);
            return Class(str);
        }
};

int main()
{
    Class s1 = "\nMerry Christmas!  ";   // uses constructor 2
    Class s2 = "Happy new year!";        // uses constructor 2
    Class s3;                            // uses constructor 1

    s3 = s1 += s2;                        // add s2 to s1, assign to s3
    std::cout << "\nns1 = ";
    s1.display();
    std::cout << "\nns2 = ";
    s2.display();
    std::cout << "\nns3 = ";
    s3.display();

    std::cout << std::endl;

    return 0;
}