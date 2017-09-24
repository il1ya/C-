/**3. 
Напишите программу, вычисляющую среднее значение до 100 интервалов, введенных пользователем. 
Создайте массив объектов класса Distance, как это было сделано в примере ENGLARAY этой главы. 
Для вычисления среднего значения вы можете позаимствовать метод add_dist() из примера ENGLCON главы 6. 
Вам также понадобится метод, который выделяет целую часть из значения Distance. Вот одна из возможностей:
void Distance::div_dist(Distance d2, int divisor)
{
    float fltfeet = d2.feet + d2.inches / 12.0;
    float temp = fltfeet /= divisor;
    feet = int(fltfeet);
    inches = (temp - feet) * 12.0;
}
*/
#include <iostream>
class Distance{
    private:
        int feet;
        float inches;
    public:
        Distance() : feet(0), inches(0.0){                  // конструктор без аргументов

        }
        Distance(int ft, float in) : feet(ft), inches(in){  // конструктор с двумя аргументами
            
        }
        void getdist(){                                     // ввод длины пользователем
            std::cout << "\nEnter number of feet: ";
            std::cin >> feet;
            std::cout << "\nEnter the number of inches: ";
            std::cin >> inches;
        }
        void showdist(){                                    // вывод длины на экран
            std::cout << feet << "\'-" << inches << '\"';
        }
        void add_dist(Distance, Distance);                  // прототип
        void div_dist(Distance d2, int divisor);            // прототип
};

void Distance::add_dist(Distance dd1, Distance dd2){        // сложение длин d1 и d2
    inches = dd1.inches + dd2.inches;       // сложение дюймов
    feet = 0;
    if(inches >= 12.0){                     // если число дюймов больше 12.0,
        inches -= 12.0;
        feet++;
    }
    feet += dd1.feet + dd2.feet;            // сложение футов
}

void Distance::div_dist(Distance d2, int divisor)
{
    float fltfeet = d2.feet + d2.inches / 12.0;
    float temp = fltfeet /= divisor;
    feet = int(fltfeet);
    inches = (temp - feet) * 12.0;
}

int main()
{
    const int SIZE = 100;
    Distance arr[SIZE];
    Distance total(0, 0.0), average;
    int i = 0;
    char enter;
    do{
        std::cout << "Enter distance number " << i+1;
        arr[i++].getdist();
        std::cout << "Enter another (y/n)?:  ";
        std::cin >> enter;
    }while(enter != 'n');
    for(int j = 0; j < i; j++)
        total.add_dist(total, arr[j]);
        average.div_dist(total, i);
        std::cout << "\nAverage: ";
        average.showdist();
        std::cout << std::endl;
    return 0;
}