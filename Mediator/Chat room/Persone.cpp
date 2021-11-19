//
// Created by oleh.slabak on 11/19/2021.
//

#include "Persone.hpp"
#include "ChatRoom.hpp"
#include <iostream>

Persone::Persone(const string &name) : name(name) {}

void Persone::say(const string &message) const {
    room->broadcast(name, message);
}

void Persone::pm(const string &who, const string &message) const {
    room->message(name, who, message);
}

void Persone::receive(const string &origin, const string &message) {
    string s{origin + ":\"" + message + "\""};
    cout << "[" << name << "'s chat session]" << s << "\n";
    chatLog.emplace_back(s);
}

bool Persone::operator==(const Persone &rhs) const {
    return name == rhs.name;
}

bool Persone::operator!=(const Persone &rhs) const {
    return !(rhs == *this);
}

