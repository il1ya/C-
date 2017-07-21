// Листинг 18.4. lambdaO. рр 
// lambdaO.cpp -- использование лямбда-выражений
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size1 = 39L;
const long Size2 = 100*Size1;
const long Size3 = 100*Size2;

bool f3(int x)
{
    return x % 3 == 0;
}
bool f13(int x)
{
    return x %13 == 0;
}

int main()
{
    using std::cout;
    std::vector<int> numbers(Size1);
    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);

    // Использование указателей на функции 
    cout << "Smaple size = " << Size1 << '\n';      // размер выборки 
    int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
    cout << "Count of numbers divisible by 3: " << count3 << '\n';

    // количество чисел, кратных 3 
    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // количество чисел, кратных 13 
    // Увеличение размера numbers 
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size2 << '\n';              // размер выборки 

    // Использование функтора 
    class f_mod
    {
        private:
            int dv;
        public:
            f_mod(int d = 1) : dv(d) 
            {

            }
            bool operator() (int x)
            {
                return x % dv == 0;
            }
    };
    count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
            // количество чисел, кратных 3 
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";
    // количество чисел, кратных 13 
    // Повторное увеличение размера numbers 
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size3 << '\n';              // размер выборки 
    
    // Использование лямбда 
    count3 = std::count_if(numbers.begin(), numbers.end(), [](int x){return x % 3 == 0;});
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    // количество чисел, кратных 3 
    count13 = std::count_if(numbers.begin(), numbers.end(), [](int x){return x % 13 == 0;});
    cout << "Count of numbers divisible by 13: " << count13 << '\n';
    // количество чисел, кратных 13 
    return 0;
}
// Вывод показывает, что не следует полагаться на статистические данные, основанные на небольших выборках. 
