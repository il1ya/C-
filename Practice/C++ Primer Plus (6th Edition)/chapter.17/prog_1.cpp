/*7. Напишите программу, которая запрашивает следующую информацию и форматирует ее, как показано ниже: 
Enter your name: Billy Gruff 
Enter your hourly wages: 12 
Enter number of hours worked: 7.5 
First format: 
Billy Gruff: $ 12.00: 7.5 
Second format: 
Billy Gruff : $12.00 :7.5 
*/

#include <iostream>
#include <iomanip>
const int Size = 20;
int main()
{
    using namespace std;
    char name[Size];
    float number;
    float wages;
    cout << "Enter your name: ";
    cin.get(name, 20).get(); 
    cout << "Enter your hourly wages: ";
    cin >> wages;
    cout << "Enter number of hours worked: ";
    cin >> number;
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::right, ios::adjustfield);
    cout << "First format:\n" << name << ": $ " << wages << setprecision(2) << ": " << number << setprecision(1) << endl;
    cout.setf(ios::left, ios::adjustfield); 
    cout << "Second format :\n" << name << ": $" << wages << setprecision(2) << " :" << number << setprecision(1) << endl;
    return 0;
}