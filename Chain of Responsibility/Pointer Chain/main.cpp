#include <iostream>
#include <string>
using namespace std;
struct Creature
{
    string name;
    int attack, defense;

    Creature(const string &name, int attack, int defense) : name(name), attack(attack), defense(defense) {}

    friend ostream &operator<<(ostream &os, const Creature &creature) {
        os << "name: " << creature.name << " attack: " << creature.attack << " defense: " << creature.defense;
        return os;
    }

};

class CreatureModifier
{
   CreatureModifier *next{nullptr};
protected:
    Creature &creature;
public:
    CreatureModifier(Creature &creature) : creature(creature) {}
    void add(CreatureModifier *cm)
    {
        if (next)
            next->add(cm);
        else
            next = cm;
    }

    virtual void handle()
    {
        if (next)
            next->handle();
    }
};

class DoubleAttackModifier : public CreatureModifier
{
public:
    DoubleAttackModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
        creature.attack *= 2;
        CreatureModifier::handle();
    }
};

class IncreaseDefenseModifier : public CreatureModifier
{
public:
    IncreaseDefenseModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
        if (creature.attack <= 2)
            creature.defense++;

        CreatureModifier::handle();
    }
};

class NoBonusesModifier : public CreatureModifier
{
public:
    NoBonusesModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {

    }
};

int main() {

    Creature goblin{"Goblin", 1, 1};
    CreatureModifier root{goblin};

    DoubleAttackModifier r1{goblin};
    DoubleAttackModifier r2{goblin};
    IncreaseDefenseModifier r3{goblin};

    root.add(&r1);
    root.add(&r2);
    root.add(&r3);

    root.handle();

    cout << goblin << endl;

    return 0;
}
