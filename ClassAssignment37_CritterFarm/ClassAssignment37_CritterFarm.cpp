#include <iostream>
#include <string>
#include <vector>

class Critter {
public:
    Critter(const std::string& name = "");
    std::string GetName() const;

private:
    std::string m_Name;
};

Critter::Critter(const std::string& name):
    m_Name(name)
{}

inline std::string Critter::GetName() const {
    return m_Name;
}

class Farm {
public:
    Farm(int spaces = 1);
    void Add(const Critter& aCritter);
    void RollCall() const;
private:
    std::vector<Critter> m_Critters;
};

Farm::Farm(int spaces) {
    m_Critters.reserve(spaces);
}

void Farm::Add(const Critter& aCritter) {
    m_Critters.push_back(aCritter);
}

void Farm::RollCall() const {
    for (std::vector<Critter>::const_iterator iter = m_Critters.begin(); iter != m_Critters.end(); ++iter) {
        std::cout << iter->GetName() << " here!\n";
    }
}

int main()
{
    Critter crit("Pooch");
    std::cout << "My critter's name is " << crit.GetName() << "\n";

    std::cout << "\nCreating critter farm. \n";
    Farm myFarm(3);

    std::cout << "\nAdding three critters to the farm. \n";
    myFarm.Add(Critter("Dawg"));
    myFarm.Add(Critter("Duck"));
    myFarm.Add(Critter("Eggy"));

    std::cout << "\nCalling Roll\n";
    myFarm.RollCall();

    system("pause");
}