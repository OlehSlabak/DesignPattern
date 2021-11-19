//
// Created by oleh.slabak on 11/19/2021.
//
#include "Persone.hpp"
#include "ChatRoom.hpp"
#include <algorithm>

void ChatRoom::broadcast(const string &origin, const string &message) {
    for (auto p : people)
        if(p->name != origin)
            p->receive(origin, message);
}

void ChatRoom::join(Persone *p) {
    string join_msg = p->name + " joins the chat";
    broadcast("room", join_msg);
    p->room = this;
    people.push_back(p);

}

void ChatRoom::message(const string &origin, const string &who, const string &message) {
    auto target = std::find_if(begin(people), end(people), [&](const Persone *p)
                               {
                                   return p->name == who;
                               });
    if (target != end(people))
        (*target)->receive(origin, message);


}
