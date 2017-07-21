/* 7. Напишите программу, рассчитывающую сумму денег, которые вы получите при вложении начальной суммы с фиксированной процентной ставкой дохода через определенное количество лет. 
Пользователь должен вводить с клавиатуры начальный вклад, число лет и процентную ставку. Примером результата работы программы может быть следующий:
Введите начальный вклад: 3000
Введите число лет: 10
Введите процентную ставку: 5.5
Через 10 лет вы получите 5124.43 доллара.
В конце первого года вы получите 3 000 + (3 000*0.055) = 3165 долларов. 
В конце следующего года вы получите 3 165 + (3 165*0.055) = 3339.08 долларов. 
Подобные вычисления удобно производить с помощью цикла for. */
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