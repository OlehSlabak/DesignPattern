//
// Created by oleh.slabak on 11/19/2021.
//

#ifndef CHAT_ROOM_CHATROOM_HPP
#define CHAT_ROOM_CHATROOM_HPP


struct ChatRoom {
    vector<Persone*> people;
    void broadcast(const string& origin, const string& message);
    void join(Persone *p);
    void message( const string& origin, const string& who, const string& message);

};


#endif //CHAT_ROOM_CHATROOM_HPP
