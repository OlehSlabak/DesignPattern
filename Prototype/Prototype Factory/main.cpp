#include <iostream>
#include <string>
#include <memory>
#include <ostream>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

struct Point
{
    int x{ 0 }, y{ 0 };

    Point(){}

    Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line
{
    Point *start, *end;

    Line(Point* const start, Point* const end)
            : start(start), end(end)
    {
    }

    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        return Line{
                new Point(start->x, start->y),
                new Point(end->x, end->y)
        };
        // TODO
    }
};



using namespace std;
using namespace boost;

struct Address
{
    Address() {}

    string street, city;
    int suit;

    Address(const string &street, const string &city, int suit) : street(street), city(city), suit(suit) {}

    friend ostream &operator<<(ostream &os, const Address &address) {
        os << "street: " << address.street << " city: " << address.city << " suit: " << address.suit;
        return os;
    }
  /*  friend class serialization::access;

    template<class archive> void serialize(archive& ar, const unsigned version)
    {
        ar &street;
        ar &city;
        ar &suit;
    }*/
};

struct Contact
{
    Contact() {}

    string name;
    Address *address;

    Contact(const string &name, Address *address) : name(name), address(address) {}

    Contact(const Contact& other) : name {other.name},
                                    address {new Address {other.address->street, other.address->city, other.address->suit}}
    {

    }

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }

private:
   /* friend class serialization::access;

    template<class archive> void serialize(archive& ar, const unsigned version)
    {
        ar &name;
        ar &address;
    }*/
};

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_employee(const string& name, const int suite)
    {
        static Contact p {"", new Address{"123 East ", "London", 0}};
        return new_employee(name, suite, p);
    }
private:
    static unique_ptr<Contact> new_employee(const string& name, int suite, const Contact& prototype)
    {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suit = suite;
        return result;
    }
};

int main() {

   auto john = EmployeeFactory::new_main_office_employee("John", 123);
    cout << *john << endl;

 /* auto clone = [] (const Contact& c)
  {
      ostringstream oss;
      archive::text_oarchive oa(oss);
      oa << c;

      string s = oss.str();
      cout << s << endl;

      istringstream iss;
      archive::text_iarchive ia(iss);
      Contact result;
      ia >> result;
      return result;
  };
    auto john = EmployeeFactory::new_main_office_employee("John", 123);
    auto jane = clone(*john);*/
    return 0;
}
