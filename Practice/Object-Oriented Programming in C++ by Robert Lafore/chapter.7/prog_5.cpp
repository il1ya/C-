/*5. 
Начните с класса fraction из упражнений 11 и 12 главы 6. 
Напишите функцию main(), которая получает случайные дробные числа от пользователя, сохраняет их в массиве типа fraction, вычисляет среднее значение и выводит результат. */
#include <iostream>

int main()
{
   const int SIZE = 6;             //size of array
   double sales[SIZE];             //array of 6 variables

   std::cout << "Enter widget sales for 6 days\n";
   for(int j=0; j<SIZE; j++)       //put figures in array
      std::cin >> sales[j];
			
   double total = 0;
   for(int j = 0; j<SIZE; j++)           //read figures from array
      total += sales[j];           //to find total
   double average = total / SIZE;  // find average
   std::cout << "Average = " << average << std::endl;
   return 0;
}