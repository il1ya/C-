// Листинг 3.1. limits.срр 
// limits.срр -- некоторые ограничения целых чисел 
#include <iostream>
#include <climits>              // используйте заголовочный файл limits.h для старых систем 

int main(void)
{
    using namespace std;
    int n_int = INT_MAX;        // инициализация n_int максимальным значением int 
    short n_short = SHRT_MAX;   // символы, определенные в файле climits 
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // Операция sizeof выдает размер типа или переменной 
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
    return 0;
}
