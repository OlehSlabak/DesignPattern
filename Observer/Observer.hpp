//
// Created by oleh.slabak on 11/23/2021.
//

#ifndef OBSERVER_OBSERVER_HPP
#define OBSERVER_OBSERVER_HPP
#include <string>

template<typename T>
struct Observer {
virtual void field_changed(T& source, const std::string &field_name) = 0;

};


#endif //OBSERVER_OBSERVER_HPP
