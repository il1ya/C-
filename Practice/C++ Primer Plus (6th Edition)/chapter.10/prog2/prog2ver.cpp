#include "prog2ver1.h"
int main()
{
    Person one; // use default constructor
    Person two("Smythecraft"); // use #2 with one default argument
    Person three("Dimwiddy", "Sam"); // use #2, no defaults
    one.Show();
    std::cout << std::endl;
    one.FormalShow();
    two.FormalShow();
    two.Show();
    three.FormalShow();
    three.Show();
 
    return 0;
}