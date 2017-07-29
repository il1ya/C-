#include "bank.h"
int main(void)
{
    Bank first("Illya Skwvortsov", "22222223KD", 2500);
    first.show();
    first.amount_adding(450);
    first.show();
    first.amount_withdrawals(500);
    first.show();
    return 0;
}