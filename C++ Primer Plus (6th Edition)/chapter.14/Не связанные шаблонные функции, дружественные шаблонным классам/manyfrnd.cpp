/* Не связанные шаблонные функции, дружественные шаблонным классам 
В предыдущем разделе связанные шаблонные дружественные функции являются специализациями для шаблона, определенного вне класса. 
Специализация int класса дает специализацию функции int и т.д. Объявив шаблон внутри класса, можно создать не связанные дружественные функции, когда любая специализация функции будет дружественной для любой специализации класса. 
У не связанных друзей параметры типа для шаблонов друзей отличаются от параметров типа для шаблонных классов: 
template <typename T> 
class ManyFriend 
{ 
    template <typename С, typename D> friend void show2(C &, D &); 
}; 
В листинге 14.24 приведен пример применения не связанных друзей. В этом примере вызов show2 (hfil, hfІ2) соответствует следующей специализации: 
void show2<ManyFriend<int> &, ManyFriend<int> &> 
        (ManyFriend<int> & с, ManyFriend<int> & d); 
Поскольку данная функция является другом для всех специализаций ManyFriend, она имеет доступ к членам item всех специализаций. 
Однако она использует доступ только к объектам ManyFriend<int>. Аналогично, вызов show2 (hf d, hf І2) соответствует такой специализации: 
void show2<ManyFriend<double> &, ManyFriend<int> &> 
          (ManyFriend<double> & с, ManyFriend<int> & d);
Эта функции также является другом для всех специализаций ManyFriend и использует доступ к члену item объекта ManyFriend<int>, а также к члену item объекта ManyFriend<double>. 
Листинг 14.24. manyfrnd.cpp */
// manyfrnd.cpp — не связанная шаблонная функция, дружественная шаблонному классу 
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class ManyFriend
{
    private:
        T item;
    public:
        ManyFriend(const T &i) : item(i) {}
        template <typename C, typename D> friend void show2(C &, D &);
};

template <typename C, typename D> void show2(C &c, D &d)
{
    cout << c.item << ", " << d.item << endl;
}

int main()
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);
    cout << "hfi1, hfi2: ";
    show2(hfi1, hfi2);
    cout << "hfdb, hfi2: ";
    show2(hfdb, hfi2);
    return 0;
}