#include <iostream>
#include "sales.h"

Sales::Sales()
{
    for(int i = 0; i < QUARTERS; i++)
    {
        sales[i] = 0;
    }
    min = 0;
    max = 0;
    average = 0;
}

Sales::Sales(const double sale[], int n)
{
    for(int i = 0; i < QUARTERS; i++)
    {
        sales[i] = sale[i];
    }
    min = sales[0];
    max = sales[0];
    average = sales[0];
    for(int i = 1; i < n; i++)
    {
        average += sales[i];
        if(min > sales[i])
            min = sales[i];
        if(max < sales[i])
            max = sales[i];
    }
    average /= 4;

    for(int i = n; i < QUARTERS; i++)
    {
        sales[i] = 0;
    }
    std::cout << "\nDone objiect initialization.\n";
}

void Sales::setSales()
{
    for(int i = 0; i < QUARTERS; i++)
    {
        std::cout << "Please enter sale # " << i+1 << " : ";
        std::cin >> sales[i]; 
    }

    min = sales[0];
    max = sales[0];
    average = sales[0];
    for(int i = 1; i < QUARTERS; i++)
    {
        if(min > sales[i])
            min = sales[i];
        if(max < sales[i])
            max = sales[i];
            average += sales[i];
    }
    average /= 4;
}

void Sales::setSales(const double [], int n)
{
    min = sales[0];
    max = sales[0];
    average = sales[0];
    for(int i = 1; i < QUARTERS; i++)
    {
        if(min > sales[i])
            min = sales[i];
        if(max < sales[i])
            max = sales[i];
            average += sales[i];
    }
    average /= 4;
}

void Sales::showSales() const
{
    std::cout << "Sales: \n";
    for(int i = 0; i < QUARTERS; i++)
    {
        std::cout << "    #" << i+1 << " : " << sales[i] << std::endl;
        std::cout << "    min : " << min << std::endl;
        std::cout << "    max : " << max << std::endl;
        std::cout << "average : " << average << std::endl;
    }
}