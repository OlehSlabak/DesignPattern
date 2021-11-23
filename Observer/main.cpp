#include <iostream>
#include "Observer.hpp"
#include "Observable.hpp"
using namespace std;
// observable
class Person : public Observable<Person>
{
    int age;
public:
    Person(int age) : age(age) {}

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        if (this->age == age)
            return;
        this->age = age;
        notify(*this, "age");
    }
};

// observer
struct ConsolePersonObserver : public Observer<Person>
{
private:
    void field_changed(Person &source, const std::string &field_name) override {
        cout << "Person's " << field_name << " has changed to ";
        if (field_name == "age") cout << source.getAge();
        cout <<"\n";
    }
};

struct TrafficAdministration : Observer<Person>
{
    void field_changed(Person &source, const string &field_name) override {
        if (field_name == "age")
        {
            if (source.getAge() < 17)
                cout << " less 17" << endl;
            else
            {
                cout << " OK " << endl;
                source.unsubscribe(*this);
            }
        }

    }
};

int main() {
    Person person{10};

    ConsolePersonObserver cpo;
    person.subscribe(cpo);

    person.setAge(11);
    person.setAge(12);

    person.unsubscribe(cpo);
    person.setAge(13);

    Person p{10};
    TrafficAdministration tpo;
    p.subscribe(tpo);
    p.setAge(15);
    try {
        p.setAge(17);
    }
    catch (const std::exception &e)
    {
    cout << e.what() << endl;
    }

    return 0;
}
