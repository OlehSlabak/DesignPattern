#include <iostream>
#include <string>

using namespace std;

struct Address
{
    string street, city;
    int suit;

    Address(const string &street, const string &city, int suit) : street(street), city(city), suit(suit) {}

    friend ostream &operator<<(ostream &os, const Address &address) {
        os << "street: " << address.street << " city: " << address.city << " suit: " << address.suit;
        return os;
    }
};

struct Contact
{
    string name;
    Address *address;

    Contact(const string &name, Address *address) : name(name), address(address) {}

    Contact(const Contact& other) : name {other.name},
                                    address {new Address
                                                        {other.address->street,
                                                         other.address->city,
                                                          other.address->suit}
                                             }
    {

    }

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }
};


int main() {

  //  Contact john{"John Doe", Address{"123 east ", "London", 123}};
    //Contact jane{"Jane Doe", Address{"123 east ", "London", 103}};
  //  Contact jane = john;
  //  jane.name = "Jane Doe";
  //  jane.address.suit = 103;
  //  cout << john << " \n" << jane << endl;
    return 0;
}
