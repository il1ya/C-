/*
10. 
Матрица — это двумерный массив. 
Создайте класс matrix, который предоставляет те же меры безопасности, как и класс из упражнения 7, то есть осуществляет проверку индексов массива на вхождение их в границы массива. 
Полем класса matrix будет массив 10 на 10. Конструктор должен позволять программисту определить реальный размер массива (допустим, сделать его меньше, чем 10 на 10). 
Методам, предназначенным для доступа к членам матрицы, теперь нужны два индекса: по одному для каждой размерности массива. 
Вот фрагмент функции main(), которая работает с таким классом:
matrix m1(3, 4); // описываем матрицу
int temp = 12345; // описываем целое
ml.putel(7, 4, temp); // помещаем значение temp в матрицу
temp = m1.getel(7, 4); // получаем значение из матрицы */

#include <iostream>
const int SIZE = 10;
class Matrix{
private:
    int array[SIZE][SIZE];
public:
    int one, two;
    Matrix(int o, int t): one(o), two(t){}
    void putel(int o, int t, int temp){
        if(o < 0 || o > SIZE-1 || t < 0 || t > SIZE-1){
            std::cout << "Watrning!" << std::endl;
        }
        array[o][t] = temp;
    }
    int getel(int o, int t){
        if(o < 0 || o > SIZE-1 || t < 0 || t > SIZE-1){
            std::cout << "Warning!" << std::endl;
        }
        return array[o][t];
    }
};

int main()
{
    Matrix m1(3, 4);
    int temp = 12345;
    m1.putel(7, 4, temp);
    temp = m1.getel(7, 4);
    std::cout << temp << std::endl;
}
