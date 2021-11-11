#include <iostream>
#include "DrinkFactory.hpp"


#include <string>
using namespace std;

struct Person
{
    int id;
    string name;
};

class PersonFactory
{
public:
    Person create_person(const string& name)
    {
        static int index = 0;
        Person p;
        p.id = index;
        p.name = name;
        index++;
        return  p;
    }
};

int main() {
    PersonFactory pf;
    pf.create_person("Ole");
    cout << pf.create_person("DD").id << endl;

    return 0;
}
