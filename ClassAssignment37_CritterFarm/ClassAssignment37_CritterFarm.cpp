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
    void Add(const Critter& aCritter);          //Member function requiring a Critter
    void RollCall() const;
private:
    std::vector<Critter> m_Critters;            //Holding a container of Critters
};

Farm::Farm(int spaces) {
    m_Critters.reserve(spaces);                 //reserves capacity to contain an element
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
    myFarm.Add(Critter("Dawg"));                //Instantiating Critters from the Farm class. Can be accessed like any other vector element (IE: Iterators)
    myFarm.Add(Critter("Duck"));
    myFarm.Add(Critter("Eggy"));

    std::cout << "\nCalling Roll\n";
    myFarm.RollCall();

    system("pause");
}