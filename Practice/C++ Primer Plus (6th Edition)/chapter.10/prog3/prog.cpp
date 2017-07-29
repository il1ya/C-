#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf()
{
    setgolf(*this);
}

Golf::Golf(const char *name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}

int Golf::setgolf(Golf & g)
{
    std::cout << "Enter name: ";
    std::cin.getline(g.fullname, Len);
    if(std::cin.eof())
        return 0;
    std::cout << "Enter hadicap: ";
    std::cin >> g.handicap;
        return 1;
}

void Golf::set_handicap(int hc)
{
    handicap = hc;
}
void Golf::showgolf()
{
    std::cout << "--- Golf ---" << std::endl;
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Handicap: " << handicap << std::endl;
    std::cout << std::endl;
}