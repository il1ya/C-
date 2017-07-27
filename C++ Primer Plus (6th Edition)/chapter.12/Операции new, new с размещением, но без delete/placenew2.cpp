/* В листинге 12.9 устранены огрехи кода из листинга 12.8: в нем выполняется управление позициями памяти, используемыми new с размещением, а также добавлены 
правильные обращения к операции delete и явные вызовы деструкторов. 
Важно соблюдать правильный порядок удаления. Объекты, созданные операцией new с размещением, должны удаляться в порядке, обратном порядку их создания. 
Причина в том, что более поздний объект может зависеть от более ранних. А буфер, используемый для хранения объектов, можно освободить только после уничтожения всех содержащихся в нем объектов. 
Листинг 12.9. placenew2.срр */
// placenew2. срр — операции new, new с размещением, но без delete 
#include <iostream>
#include <cstring>
#include <new>
using namespace std;
const int BUF = 512;
class JustTesting
{
    private:
        string words;
        int number;
    public:
        JustTesting(const string & s = "Just Testing", int n = 0)
        {
            words = s;
            number = n;
            cout << words << " constructed\n";
        }
        ~JustTesting()
        {
            cout << words << " destroyed\n";
        }
        void Show() const
        {
            cout << words << ", " << number << endl;
        }
};
int main()
{
    char *buffer = new char[BUF];       // получение блока памяти 
    JustTesting *pc1, *pc2;
    pc1 = new(buffer) JustTesting;      // размещение объекта в buffer 
    pc2 = new JustTesting("Heap1", 20); // размещение объекта в куче 
    cout << "Memory block addresses:\n" << "buffer: " << (void *)buffer << " heap: " << pc2 << endl; // вывод адресов памяти 
    cout << "Memory contents:\n";       // вывод содержимого памяти 
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();
    JustTesting *pc3, *pc4;
    // Фиксация ячейки, с которой работает new с размещением 
    pc3 = new(buffer + sizeof(JustTesting))
    JustTesting("Better Idea", 6);
    pc4 = new JustTesting("Heap2", 10);
    cout << "Memory contents:\n";  // вывод содержимого памяти 
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();
    delete pc2;   // освобождение Heapl 
    delete pc4;   // освобождение Неар2 
    // Явное уничтожение объектов, созданных new с размещением 
    pc3->~JustTesting(); // уничтожение объекта, на который указывает рсЗ 
    pc1->~JustTesting(); // уничтожение объекта, на который указывает pel 
    delete [] buffer;    // освобождение buffer 
    cout << "Done\n";
    return 0;
}

// Программа в листинге 12.9 создает два объекта с помощью new с размещением в смежных позициях и вызывает соответствующие деструкторы. 
