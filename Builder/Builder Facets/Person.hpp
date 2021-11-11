#ifndef BUILDER_FACETS_PERSON_HPP
#define BUILDER_FACETS_PERSON_HPP

#include <string>
#include <iostream>

class PersonBuilder;

class Person {
    std::string street_address, post_code, city;
    std::string company_name, position;
    int annual_income{0};
public:
    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;

    friend std::ostream& operator<<(std::ostream& os, const Person& obj)
    {
        return os
                << "street_address: " << obj.street_address
                << " post_code: " << obj.post_code
                << " city: " << obj.city
                << " company_name: " << obj.company_name
                << " position: " << obj.position
                << " annual_income: " << obj.annual_income;
    }
};


#endif //BUILDER_FACETS_PERSON_HPP
