/* 5. Напишите программу, которая запрашивает текущую численность населения Земли и текущую численность населения США (или любой другой страны). 
Сохраните эту информацию в переменных типа long long. В качестве результата программа должна отображать процентное соотношение численности 
населения США (или выбранной страны) и всего мира. Результат выполнения программы должен выглядеть следующим образом: 
Enter the world's population: 6898758899 
Enter the population of the US: 310783781 
The population of the US is 4.50492% of the world population. 
Можете поискать в Интернете более точные значения. */
#include <iostream>
int main(void)
{
    using namespace std;
    cout.setf(ios_base::fixed);
    long long world_population, population_japan;
    cout << "Enter the world's population (7296000000):  \b";
    cin >> world_population;
    cout << "Enter the population of the Japan (126910000):  \b";
    cin >> population_japan;
    double decides = world_population % population_japan;
    cout << "The population of the US is " << decides << "% of the world population." << endl;
    return 0;
}