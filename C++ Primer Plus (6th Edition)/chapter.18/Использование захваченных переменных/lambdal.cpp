// Листинг 18.5. lambdal.срр 
// lambdal.срр — использование захваченных переменных 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
const long Size = 390000L;

int main()
{
    using std::cout;
    std::vector<int> numbers(Size);
    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size << '\n';                   // размер выборки
        // Использование лямбда-функций 
    int count3 = std::count_if(numbers.begin(), numbers.end(), [](int x){return x % 3 == 0;});
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
        // количество чисел, кратных 3 
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(), [&count13](int x){count13 += x % 13 == 0;});
    cout << "Count of numbers divisible by 13: " << count13 << '\n';
        // количество чисел, кратных 13 
    // Использование одиночного лямбда-выражения 
    count3 = count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),[&](int x){count3 += x % 3 == 0; count13 += x % 13 == 0;});
    cout << "Count of numbers divisible by 3: << count3 << '\n";
        // количество чисел, кратных 3 
    cout << "Count of numbers divisible by 13: " << count13 << '\n';
        // количество чисел, кратных 13 
    return 0;
}

/*

Ниже показан вывод программы из листинга 18.5: 
Sample size = 390000 
Count of numbers divisible by 3: 130274 
Count of numbers divisible by 13: 30009 
Count of numbers divisible by 3: 130274 
Count of numbers divisible by 13: 30009 


Вывод подтверждает, что оба подхода (две отдельных лямбда-функции и одиночное лямбда-выражение) в этой программе приводят к одним и тем же результатам. 
Главной причиной добавления лямбда-функций к C++ было желание сделать возможным использование подобного функции выражения в качестве аргумента  
функции, которая ожидает на его месте указателя на функцию или функтора. 
Таким образом, типичной лямбда-функцией будет проверочное или сравнивающее выражение, которое может быть записано как единственный оператор return. 
Это сохраняет лямбда-функцию короткой и простой для понимания, а также делает возможным автоматическое выведение типа возвращаемого значения. 
Тем не менее, вполне вероятно, что сообществом программистов на C++ будут разработаны и другие сценарии использования. 
*/