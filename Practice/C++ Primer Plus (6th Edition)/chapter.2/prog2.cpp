// 2. Напишите программу на C++, которая выдает запрос на ввод расстояния в фарлонгах и преобразует его в ярды. (Один фарлонг равен 220 ярдам, или 201168 м.) 
#include <iostream>
int main(void)
{
    using namespace std;
    int furlong;
    cout << "Enter distance entry in Furlong: ";
    cin >> furlong;
    cout << "Ur " << furlong << " furlong = " << furlong * 220 << " core" << endl;
    return 0;
}