#include <iostream>

#include "Persone.hpp"
#include "ChatRoom.hpp"

int main() {
    ChatRoom room;

    Persone john{"John"};
    Persone ave{"Ave"};

    room.join(&john);
    room.join(&ave);

    john.say("Hi room");
    ave.say("oh, hey john");

    Persone simon{"Simon"};
    room.join(&simon);
    simon.say("hi everyone!");

    ave.pm("Simon", "glad you found us, simon!");
    return 0;
}
