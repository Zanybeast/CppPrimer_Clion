//
// Created by carl on 2020/9/13.
//

#include <iostream>

#include "Message.h"
#include "Folder.h"

void Message::save(Folder &f) {
    addFolder(&f);
    f.addMsg(this);
}

void Message::remove(Folder &folder) {
    removeFolder(&folder);
    folder.removeMsg(this);
}

Message::Message(Message &&m) noexcept : contents(m.contents) {
    move_Folders(&m);
}

Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message & Message::operator=(Message &&rhs) noexcept {
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

void Message::add_to_Folders(const Message &m) {
    for (auto f: m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

void Message::move_Folders(Message *m) {
    folders = std::move(m->folders);
    for (auto f: folders) {
        f->removeMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void Message::remove_from_Folders() {
    for (auto f : folders)
        f->removeMsg(this);
}

Message::~Message() {
    remove_from_Folders();
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f: lhs.folders) {
        f->removeMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->removeMsg(&rhs);
    }

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f: lhs.folders) {
        f->addMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->addMsg(&rhs);
    }
}

void Message::print_debug() {
    std::cout << contents << std::endl;
}