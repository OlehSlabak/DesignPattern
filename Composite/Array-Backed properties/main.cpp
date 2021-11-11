#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <numeric>

using namespace std;

/*class Creature
{
    int strength, agility, intelligence;
public:
    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Creature::strength = strength;
    }

    int getAgility() const {
        return agility;
    }

    void setAgility(int agility) {
        Creature::agility = agility;
    }

    int getIntelligence() const {
        return intelligence;
    }

    void setIntelligence(int intelligence) {
        Creature::intelligence = intelligence;
    }

    double sum() const
    {
        return strength + agility + intelligence;
    }
    double average() const
    {
        return sum() / 3.0;
    }
    int max() const{
        return ::max(::max(strength, agility), intelligence);
    }
};*/

class Creature
{
    enum Abilities { str, agl, intl, count};
    array<int, count> abilities;
public:
    int get_strength() const {return abilities[str]; }
    void set_strength(int value) {abilities[str] = value;}

    int sum() const
    {
        return accumulate(abilities.begin(),abilities.end(), 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
