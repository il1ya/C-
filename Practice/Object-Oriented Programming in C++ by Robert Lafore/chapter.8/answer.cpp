1. a
2. x3.subtract(x2, x1);
3. x3 = x1 - x2;
4. да
5. 
#include <iostream>
class Counter{
private:
    int count;
public:
    Counter(): count(0){}
    Counter(int c): count(c){}
    void display() const{
        std::cout << count << std::endl;
    }
    void operator --(){
        --count;
    }
    ~Counter(){}
};
int main(){
    Counter pr1 = 9;
    --pr1;
    pr1.display();
    return 0;
}
6. 1
7. Distance operator + (Distance) const;  //add 2 distances
};

                               //add this distance to d2
Distance Distance::operator + (Distance d2) const  //return sum
{
int f = feet + d2.feet;        //add the feet
float i = inches + d2.inches;  //add the inches
if(i >= 12.0)                  //if total exceeds 12.0,
   {                           //then decrease inches
   i -= 12.0;                  //by 12.0 and
   f++;                        //increase feet by 1
   }                           //return a temporary Distance
return Distance(f,i);          //initialized to sum
}
8.
#include <iostream>
class Counter{
private:
    int count;
public:
    Counter(): count(0){}
    Counter(int c): count(c){}
    void display() const{
        std::cout << count << std::endl;
    }
    void operator++(){
        ++count;
    }
    ~Counter(){}
};
int main(){
    Counter pr1 = 9;
    ++pr1;
    pr1.display();
    return 0;
}
9. Distance Distance:: operator++(){
    int f = ++feet;
    float i = inches;
    return Distance(f, i);
}
10.  Увеличивает переменную до ее использования как незамещенный опера- тор++.
11. в, д, б, а, г
12. истинна
13. в, г
14.  String String::operator++(){
    int len = stlen(str);
    for(int j = 0; j < len; j++)
        str[j] == toupper(str[j])
        return String(str);
}
15. г
16. нет
17. б
18. да
19. Конструктор
20. да
21. г
22. Атрибутами, операторами
23. нет
24. а