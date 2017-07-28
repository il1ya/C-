/*1. Модифицируйте код в листинге 11.15 так, чтобы обеспечить запись в файл последовательных позиций при случайном блуждании. 
Каждая позиция должна помечаться номером шага. Также программа должна записывать в файл начальные условия 
(целевое расстояние и длину шага) и суммарные результаты. 
Содержимое файла может выглядеть примерно так: 
Target Distance: 100, Step Size: 20 
0: (x,y) = (0, 0) 
1: (x,y) = (-11.4715, 16.383) 
2: (x,y) = (-8.68807, -3.42232) 
26: (x,y) = (42.2919, -78.2594) 
27: (x,y) = (58.6749, -89.7309) 
After 27 steps, the subject has the following location: 
(х,у) = (58.6749, -89.7309) 
or 
(m,a) = (107.212, -56.8194) 
Average outward distance per step = 3.97081 
*/
#include <iostream>
#include<cstdlib>
#include <ctime>
#include "vect2.h"
#include <fstream>
int main()
{
	using namespace std;

	// create ofstream object and open it
	ofstream myfile;
	myfile.open("q1_log.txt");
	

	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		// print output to file
		myfile << steps << ": " << result << endl;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;

			// print output to file
			myfile << steps << ": " << result << endl;
		}
		myfile << "After " << steps << " steps, the subject "
			"has the following location:\n";
		myfile << result << endl;
		result.polar_mode();
		myfile << "or\n" << result << endl;
		myfile << "Average outward distance per step = "
		<< result.magval()/steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";

	// close file
	myfile.close();

	return 0;
}