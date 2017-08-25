/*
6. 
Расширьте содержание класса employee из упражнения 4, включив в него класс date и перечисление etype (см. упражнение 6 главы 4). 
Объект класса date будет использоваться для хранения даты приема сотрудника на работу. 
Перечисление будет использовано для хранения статуса сотрудника: лаборант, секретарь, менеджер и т. д. 
Последние два поля данных должны быть закрытыми в определении класса employee, как и номер и оклад сотрудника. 
Вам будет необходимо разработать методы getemploy() и putemploy(), предназначенные соответственно для ввода и отображения информации о сотруднике. 
Возможно, при создании методов вам понадобится ветвление switch для работы с перечисляемым типом etype. 
Напишите функцию main(), которая попросит пользователя ввести данные о трех сотрудниках, а затем выведет эти данные на экран. */
#include <iostream>
#include "prog_6.h"

int main()
{
    Employee wk1, wk2, wk3;
    wk1.input();
    wk1.getemploy();
    wk2.input();
    wk2.getemploy();
    wk3.input();
    wk3.getemploy();
    std::cout << "Your data on employees\n";
    wk1.show();
    wk2.show();
    wk3.show();

    Date pr1;
    pr1.getdate();
    pr1.showdate();
    return 0;
}