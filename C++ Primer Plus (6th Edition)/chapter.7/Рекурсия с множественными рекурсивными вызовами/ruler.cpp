/* Рекурсия, в частности, удобна в тех ситуациях, когда нужно вызывать повторяющееся разбиение задачи на две похожие подзадачи меньшего размера. 
Например, рассмотрим применение такого подхода для рисования линейки. Сначала нужно отметить два конца, найти середину и пометить ее. 
Затем необходимо применить ту же процедуру для левой половины линейки и правой ее половины. 
Если требуется больше частей, эта же процедура применяется для каждой из существующих частей. 
Такой рекурсивный подход иногда называют стратегией "разделяй и властвуй". В листинге 7.17 
данный подход иллюстрируется на примере рекурсивной функции subdivide(). 
Она использует строку, изначально заполненную пробелами, за исключением символов | на каждом конце. 
Затем главная программа запускает цикл из шести вызовов subdivide(), каждый раз увеличивая количество уровней рекурсии и печатая  результирующую строку.
Таким образом, каждая строка вывода представляет дополнительный уровень рекурсии. 
Чтобы напомнить о подобной возможности, вместо директивы using в программе применяется квалификатор std::. 
Листинг7.17. ruler.срр */
// ruler.срр — использование рекурсии для разделения линейки 
#include <iostream>
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int higt, int level);
int main(void)
{
    char ruler[Len];
    int i;
    for(i = 1; i < Len - 2; i++)
        ruler[i] = ' ';
        ruler[Len - 1] = '\0';
        int max = Len - 2;
        int min = 0;
        ruler[min] = ruler[max] = '|';
        std::cout << ruler << std::endl;
        for(i = 1; i <= Divs; i++)
        {
            subdivide(ruler, min, max, i);
            std::cout << ruler << std::endl;
            for(int j = 1; j < Len - 2; j++)
                ruler[j] = ' '; // очистка линейки 
        }
        return 0;
}
void subdivide(char ar[], int low, int high, int level)
{
    if(level == 0)
        return;
        int mid = (high + low) / 2;
        ar[mid] = '|';
        subdivide(ar, low, mid, level - 1);
        subdivide(ar, mid, high, level - 1);
}
/*
Замечания по программе 
Функция subdivide() из листинга 7.17 использует переменную level для управления уровнем рекурсии. 
Когда эта функция вызывает саму себя, она уменьшает level на единицу, и как только level достигает нуля, функция завершается. 
Обратите  внимание, что subdivide() вызывает себя дважды — один раз для левой части линейки и один — для правой. 
Исходная средняя точка становится правым концом для одного вызова и левым — для другого. 
Как видите, количество вызовов растет в геометрической прогрессии. 
То есть один вызов генерирует два, которые генерируют четыре вызова, те в свою очередь — восемь и т.д. 
Вот почему уровень 6 способен заполнить 64 элемента (2б = 64).
Это непрерывное удвоение количества вызовов функции (а вместе с ними и количества сохраняемых переменных) делает такую форму рекурсии плохим решением при достаточно большом числе уровней. 
Если же уровней не слишком много, то это — простое и элегантное решение. 
*/