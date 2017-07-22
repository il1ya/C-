#include <iostream>
class Critter
{
    public:
        Critter(int hunger = 0);
        int GetHunger() const;
    private:
        int m_Hunger;
};

Critter::Critter(int hunger) : m_Hunger(hunger)
{
    std::cout << "\nTest.. " << hunger << " and " << m_Hunger;
}
int Critter::GetHunger() const
        {
            std::cout << "\nfunction = ";
            return m_Hunger;
        }

int main()
{
    Critter crit(10);
    Critter crit_1(100);
    std::cout << crit.GetHunger() << std::endl;
    return 0;
}