//
// Created by oleh.slabak on 11/19/2021.
//

#ifndef CHAT_ROOM_PERSONE_HPP
#define CHAT_ROOM_PERSONE_HPP

#include <string>
#include <vector>
using namespace std;

struct ChatRoom;

struct Persone {
    string name;
    ChatRoom *room{nullptr};
    vector<string> chatLog;

    Persone(const string &name);

    void say(const string &message) const;
    void pm(const string &who, const string &message) const;
    void receive(const string &origin, const string &message);

    bool operator==(const Persone &rhs) const;

    bool operator!=(const Persone &rhs) const;
};


#endif //CHAT_ROOM_PERSONE_HPP
