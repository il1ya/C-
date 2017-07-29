#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Person 
{
    private:
        static const int LIMIT = 25;
        std::string lname;
        char fname[LIMIT];
    public:
        Person() { lname = ""; fname[0] = '\0'; }
        Person(const std::string & ln, const char * fn = "Heyyou");
        void Show() const;
        void FormalShow() const; 
};

int main()
{
    Person one;
    Person two("Smythecraft"); 
    Person three("Dimwiddy", "Sam"); 
    one.Show();
    std::cout << std::endl;
    one.FormalShow();
    two.FormalShow();
    two.Show();
    three.FormalShow();
    three.Show();
 
    return 0;
}

Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    std::cout << fname << " " << lname << std::endl;
}

void Person::FormalShow() const
{
    std::cout << lname << ", " << fname << std::endl;
}
