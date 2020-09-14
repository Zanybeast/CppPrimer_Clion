//
// Created by carl on 2020/9/13.
//

#include "Folder.h"
#include <iostream>

void Folder::addMsg(Message *m) {
    msgs.insert(m);
}

void Folder::removeMsg(Message *m) {
    msgs.erase(m);
}

void swap(Folder& lhs, Folder& rhs) {
    using std::swap;
    lhs.remove_all_msgs_in_Folder();
    rhs.remove_all_msgs_in_Folder();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_msgs_from_Folder(lhs);
    rhs.add_msgs_from_Folder(rhs);
}

Folder::Folder(const Folder &f) : msgs(f.msgs) {
    add_msgs_from_Folder(f);
}

Folder::~Folder() {
    remove_all_msgs_in_Folder();
}

Folder & Folder::operator=(const Folder &rhs) {
    remove_all_msgs_in_Folder();
    msgs = rhs.msgs;
    add_msgs_from_Folder(rhs);
    return *this;
}

void Folder::remove_all_msgs_in_Folder() {
    for (auto m: msgs)
        m->removeFolder(this);
}

void Folder::add_msgs_from_Folder(const Folder& f) {
    for (auto m: f.msgs)
        m->addFolder(this);
}

void Folder::print_debug() {
    for (auto m: msgs)
        std::cout << m->contents << std::endl;
}