/*
10. 
Модифицируйте программу, описанную в упражнении 7, так, чтобы вместо вычисления текущей суммы на вашем счете она вычисляла, сколько лет потребуется для того, 
чтобы при заданной процентной ставке и величине начального вклада сумма на вашем счете достигла запрашиваемого вами значения. 
Для хранения найденного числа лет используйте переменную целого типа (можно отбросить дробную часть значения, полученного в результате расчета). 
Самостоятельно выберите тип цикла, подходящий для решения задачи.
*/
#include <iostream>
#include <iomanip>
 using namespace std;
 int main()
 {
        double first_dep, years, rate;
        char enter;
        cout << "Enter the initial deposit.\n";
        cout << "Enter the number of years.\n";
        cout << "Enter the interest rate.\n";
        while(cin >> first_dep >> years >> rate != 0)
        {
            for(int i = 0; i < years; i++)
            {
            cout << "\ncount of years: " << setw(1) << i << " deposit: ";
            cout << first_dep << " + " << first_dep << " * " << rate / 100 << " = ";
            first_dep = first_dep + (first_dep * (rate / 100));
            cout << first_dep;
            }
                cout << "\n\nEnter the initial deposit.\n";
                cout << "Enter the number of years.\n";
                cout << "Enter the interest rate.\n";
        }
        return 0;
 }