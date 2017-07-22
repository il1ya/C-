/*
1. Усовершенствуйте программу •Тамагочи~ таким образом, чтобы в ней можно было указывать отсутствующий в меню вариант, 
выдающий точные значения голода и скуки, присущие тамагочи в настоящий момент.

2. Измените программу •Тамагочи~ таким образом, чтобы любимец мог точнее выражать свои ощущения, указывая, насколько он голоден или как сильно загрустил.
*/
#include <iostream>

using namespace std;

class Critter
{
public:          
    Critter(int hunger = 0, int boredom = 0); 
    void Talk();
    void Eat(int food = 0);
    void Play(int fun = 0);

private:
    int m_Hunger;
    int m_Boredom;

    int GetMood() const;
    void PassTime(int time = 0);

};

Critter::Critter(int hunger, int boredom): m_Hunger(hunger), m_Boredom(boredom)
{}

inline int Critter::GetMood()  const 
{
    return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::Talk()
{
    cout << "I'm a critter and I feel ";

    int mood = GetMood();
    if (mood > 15)
	{
        cout << "mad.\n";
	}
    else if (mood > 10)
	{
        cout << "frustrated.\n";
	}
    else if (mood > 5)
	{
        cout << "okay.\n";
	}
    else
	{
        cout << "happy.\n";
	}

    PassTime();
}

void Critter::Eat(int food) 
{
    cout << "Brruppp.\n";

    m_Hunger -= food;
    if (m_Hunger < 0)
	{
        m_Hunger = 0;
	}

    PassTime();
}

void Critter::Play(int fun)
{
    cout << "Wheee!\n";

    m_Boredom -= fun;
    if (m_Boredom < 0)
	{
        m_Boredom = 0;
	}

    PassTime();
}

int main()
{
    int enter_1, enter_2 = 0;
    cin >> enter_1 >> enter_2;
	Critter crit(enter_1, enter_2);
	crit.Talk();

	int choice;
	do
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
			case 0:	
				cout << "Good-bye.\n";
				break;
			case 1:	
				crit.Talk();
				break;
			case 2:	
				crit.Eat();
				break;
			case 3:	
				crit.Play();
				break;
			default:
				cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
	} while (choice != 0);

    return 0;
}

