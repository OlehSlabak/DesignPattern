#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend class ResponsiblePerson;
    int age;
public:
    Person(int age) : age(age) {}

    int get_age() const { return age; }
    void set_age(int age) { this->age=age; }

    string drink() const { return "drinking"; }
    string drive() const { return "driving"; }
    string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
public:
    ResponsiblePerson(const Person &person) : person(person) {}

    int get_age() const { return person.age; }
    void set_age(int value) { person.age = value; }

    string drink() const {
        if (person.age >= 18)
            return "drinking";
        else
            return "too young";
    }
    string drive() const {
        if (person.age >= 16)
            return "driving";
        else
            return "too young";
    }

    string drink_and_drive() const {
        return "dead";
    }

private:
    Person person;
};

int main() {
    ResponsiblePerson p(15);
    cout << p.drink() << endl;
    cout << p.drive() << endl;
    cout << p.drink_and_drive() << endl;

    return 0;
}
