//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_MESSAGE_H
#define FOREXERCISES_MESSAGE_H

#include <string>
#include <set>
//#include "Folder.h"
class Folder;

class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
//    friend void swap(Folder&, Folder&);
public:
    explicit Message(const std::string &str = "") : contents(str) { };
    Message(const Message&);
    Message(Message &&m) noexcept;
    Message &operator= (const Message&);
    Message &operator= (Message &&) noexcept;
    ~Message();

    void save(Folder&);
    void remove(Folder&);

    void addFolder(Folder *f) { folders.insert(f); }
    void removeFolder(Folder *f) { folders.erase(f); }

    void print_debug();

private:
    std::string contents;
    std::set<Folder *> folders;

    void add_to_Folders(const Message&);
    void move_Folders(Message *);
    void remove_from_Folders();
};


#endif //FOREXERCISES_MESSAGE_H
