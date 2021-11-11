//
// Created by oleh.slabak on 9/15/2021.
//

#include "Person.hpp"
#include "PersonBuilder.hpp"

PersonBuilder Person::create() {
    return  PersonBuilder{};
}