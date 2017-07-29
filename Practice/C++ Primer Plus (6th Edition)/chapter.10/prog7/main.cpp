#include "head.h"
int main()
{
    Plorg my_plog;
    my_plog.showPlorg();
    my_plog.setCI(51);
    
    Plorg my_plog2("NewPlorg", 159);
    my_plog2.showPlorg();
    return 0;
}