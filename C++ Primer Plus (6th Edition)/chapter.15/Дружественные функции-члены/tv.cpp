/* В листинге 15.2 приведены остальные определения. Функции управления громкостью изменяют уровень звука на единицу, пока он не достигнет максимального или минимального значения. 
Функции выбора канала используют циклический возврат: за минимальным значением канала, равным 1, сразу следует максимальный канал, равный maxchannel, и наоборот. 
Многие методы для переключения между двумя состояниями используют условную операцию: 
void onoff () {state = (state == On)? Off : On;} 
Поскольку значениями state могут быть только true и false — или эквивалентные им 0 и 1 — это действие можно записать более компактно с помощью операции  
исключающего "ИЛИ", объединенной с операцией присваивания (А=; см. приложение Д): 
void onoff () {state л= 1;} 
На самом деле в переменной unsigned char можно хранить до восьми двоичных состояний и переключать их по отдельности. 
Но это совсем другая история, и для нее нужны побитовые операции, которые также описаны в приложении Д. 
Листинг 15.2. tv.cpp */
// tv.cpp - методы для класса Тѵ (методы Remote являются встроенными) 
#include <iostream>
#include "tvfm.h"

bool Tv::volup()
{
    if(volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if(volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if(channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if(channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;            // выключен или включен 
    if(state == On)
    {
        cout << "Volume setting = " << volume << endl;                   // уровень громкости 
        cout << "Channel setting = " << channel << endl;                 // номер канала 
        cout << "Mode = "
             << (mode == Antenna ? "antenna" : "cable") << endl;         // антенна или кабель 
             cout << "Input = " << (input == TV ? "TV" : "DVD") << endl; // вход: TV или DVD 
    }
}