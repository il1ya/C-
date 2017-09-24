/*1. 
Добавьте в класс Distance из программы ENGLPLUS этой главы перегруженную операцию -, которая вычисляет разность двух интервалов. 
Она должна позволять выполнение выражений типа dist3 = dist1-dist2;. 
Предполагаем, что эта операция никогда не будет использоваться для вычитания большего интервала из меньшего (так как отрицательного интервала быть не может). */
#include <iostream>
class Distance{
private:
   int feet;
   float inches;
public:                        
   Distance() : feet(0), inches(0.0){}            
   Distance(int ft, float in) : feet(ft), inches(in){}
   void getdist(){
      std::cout << "\nEnter feet: ";  std::cin >> feet;
      std::cout << "Enter inches: ";  std::cin >> inches;
      }
   void showdist() const{ 
       std::cout << feet << "\'-" << inches << '\"'; 
    }

   Distance operator-(Distance);
};
//--------------------------------------------------------------
                               
Distance Distance::operator-(Distance d2)
{
int f = feet - d2.feet;        
float i = inches - d2.inches;  
    if(i < 0){                           
   i += 12.0;                  
   f--;                        
   }                           
return Distance(f,i);
}
////////////////////////////////////////////////////////////////
int main()
{
    Distance dist1, dist3;  
    Distance dist2(11, 6.25);

    dist1.getdist();
    
    dist3 = dist1 - dist2;

    std::cout << "dist1 = ";  dist1.showdist(); std::cout << std::endl;
    std::cout << "dist2 = ";  dist2.showdist(); std::cout << std::endl;
    std::cout << "dist3 = ";  dist3.showdist(); std::cout << std::endl;

    return 0;
}
