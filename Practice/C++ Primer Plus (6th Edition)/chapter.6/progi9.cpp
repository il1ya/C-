/* 9. Выполните упражнение 6, но измените его так, чтобы данные можно было получать из файла. 
Первым элементом файла должно быть количество меценатов, а остальная часть состоять из пар строк, в которых первая строка содержит имя, а вторая — сумму пожертвования. 
То есть файл должен выглядеть примерно так: 
4 
Sam Stone 
2000 
Freida Flass 
100500 
Tammy Tubbs 
5000 
Rich Raptor 
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //для exit(EXIT_FAILURE)

using namespace std;

struct patron
{
    string name;
    double donation;
};
int main(void)
{
    string filename;
    fstream file;
    cout << "Enter name of the file: ";
    getline(cin, filename);
    file.open(filename.c_str());
    if(!file.is_open())
    {
        cout << "Could not open the file" << filename << "." << endl;
        exit(EXIT_FAILURE);
    }
    int n;
    (file >> n).get();
    patron * p_patron = new patron[n];
    cout << "Reading the information about patrons." << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Maecenas #" << i+1 << endl;
        cout << "Enter name " << endl;
        getline(file, p_patron[i].name);
        cout << "and the amout of danations " << endl;
        (file >> p_patron[i].donation).get();
    }
    file.close();

    cout << "Grand Patrons." << endl;
    int countgr = 0;
    for(int j = 0; j < n; j++)
    {
        if(p_patron[j].donation >= 10000)
        {
        cout << p_patron[j].name << " - " << p_patron[j].donation << endl;
        countgr++;
        }
    }
    if(countgr == 0)
    cout << "none" << endl;
    cout << endl;
    cout << "Patrons." << endl;
    int countp = 0;
    for(int k = 0; k < n; k++)
    {
        if(p_patron[k].donation < 10000)
        {
            cout << p_patron[k].name << " - " << p_patron[k].donation << endl;
            countp++;
        }
    }
    if(countp == 0)
    cout << "none" << endl;
    cin.get();
    return 0;
}