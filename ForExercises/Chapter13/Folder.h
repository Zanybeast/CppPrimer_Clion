//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_FOLDER_H
#define FOREXERCISES_FOLDER_H

#include <set>
#include "Message.h"

class Folder {
    friend class Message;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator= (const Folder&);
    ~Folder();

    void print_debug();
private:
    std::set<Message *> msgs;

    void addMsg(Message *m);
    void removeMsg(Message *m);

    void remove_all_msgs_in_Folder();
    void add_msgs_from_Folder(const Folder&);
};


#endif //FOREXERCISES_FOLDER_H
