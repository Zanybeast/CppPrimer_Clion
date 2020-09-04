//
// Created by carl on 2020/9/4.
//

#ifndef BASIC_PERSON_H
#define BASIC_PERSON_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person {
    string name;
    string address;

    const string& getName() const { return name; }
    const string& getAddress() const { return address; }
};

ifstream &read(ifstream &is, Person& person) {
    is >> person.name >> person.address;
    return is;
}

ostream &printPerson(ostream &os, const Person& person) {
    os << person.getName() << " " << person.getAddress();
    return os;
}

#endif //BASIC_PERSON_H
