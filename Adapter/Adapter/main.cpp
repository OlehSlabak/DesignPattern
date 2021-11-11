#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Target
{
public:
    virtual ~Target() = default;

    virtual string Request() const
    {
        return "Target: the default target's behavior.";
    }
};

class Adaptee
{
public:
    std::string SpecificRequest() const
    {
        return "test etst test tes";
    }
};

class Adapter : public Target
{
private:
    Adaptee *adaptee;
public:
    Adapter(Adaptee *adaptee) : adaptee(adaptee) {}

    string Request() const override {
        string to_revers = this->adaptee->SpecificRequest();
        reverse(to_revers.begin(), to_revers.end());
        return "Addapter: " + to_revers;
    }
};

void ClientCode(const Target *tar)
{
    cout << tar->Request();
}

int main() {
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target *target = new Target;
    ClientCode(target);
    std::cout << "\n\n";
    Adaptee *adaptee = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    Adapter *adapter = new Adapter(adaptee);
    ClientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

}
