/* 6. 
Постройте программу, которая отслеживает пожертвования в Общество Защиты Влиятельных Лиц. 
Она должна запрашивать у пользователя количество меценатов, а затем приглашать вводить их имена и суммы пожертвований от каждого. 
Информация должна сохраняться в динамически выделяемом массиве структур. 
Каждая структура должна иметь два члена: символьный массив (или объект string) для хранения имени и переменную-член типа double — для хранения суммы пожертвования. 
После чтения всех данных программа должна отображать имена и суммы пожертвований тех, кто не пожалел $10 000 и более. 
Этот список должен быть озаглавлен меткой "Grand Patrons". После этого программа должна выдать список остальных жертвователей. 
Он должен быть озаглавлен "Patrons". 
Если в одной из двух категорий не окажется никого, программа должна напечатать "попе". Помимо отображения двух категорий, никакой другой сортировки делать не нужно. 
*/
#include <iostream>
using namespace std;
struct mecenats 
{
    string name;
    double donate;
};
int main()
{
    int num;
    cout << "Enter the number of patrons: ";
    cin >> num;
    mecenats *ps = new mecenats[num];
    int i  = 0;
    while(i < num)
    {
        cout << "Enter the name of a patron: ";
        getline(cin, ps[i].name);
        cout << "Enter the amount of donations: ";
        cin >> ps[i].donate;
        cin.get();
        ++i;
    }
    int j;
    while(j < num)
    {
        while(j == 0)
        cout << "GRAND PATRONS:\n";
        if((ps[j].donate) >= 10000)
        cout << ps -> name[j] << endl;
        if(j == (num - 1))
        cout << "Others partrons:\n";
        else if((ps[j].donate) <= 10000)
        {
            int i = 0;
            while(i < num)
            {
                if(ps[i].donate <= 10000)
                cout << (ps[i].name) << endl;
            }
        }
        ++j;
    }
    delete [] ps;
    return 0;
}