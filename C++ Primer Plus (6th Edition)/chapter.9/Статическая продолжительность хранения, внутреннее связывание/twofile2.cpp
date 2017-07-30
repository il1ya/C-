// Листинг 9.8. twofile2.срр 
// twofile2.срр — переменные с внутренним и внешним связыванием 
#include <iostream>
extern int tom;         // переменная torn определена в другом месте 
static int dick = 10;   // переопределяет внешнюю переменную dick 
int harry = 200;        // определение внешней переменной, конфликт с harry из twofilel отсутствует 

void remote_access()
{
    using namespace std;
    cout << "remote_access() reports the following addresses:\n"; // вывод адресов 
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}
/*
Ниже показан результат выполнения программы из листингов 9.7 и 9.8: 
main() reports the following addresses: 
0x0041a020 = &tom, 0x0041a024 = &dick, 0x0041a028 = &harry 
remote_access() reports the following addresses: 
0x0041a020 = &tom, 0x0041a450 = &dick, 0x0041a454 = &harry 

По отображаемым адресам видно, что в обоих файлах используется одна и та же переменная torn, но разные переменные dick и harry. 
(Значения адресов и формат вывода зависят от системы, в которой выполняется программа. 
Тем не менее, адреса torn будут совпадать друг с другом, тогда как адреса dick и harry — отличаться.) 
*/