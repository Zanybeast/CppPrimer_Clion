//
// Created by carl on 2020/9/4.
//

#ifndef FOREXERCISES_PERSON_H
#define FOREXERCISES_PERSON_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person;

ifstream &read(ifstream &is, Person& person);
ostream &printPerson(ostream &os, const Person& person);

class Person {
    friend ifstream &read(ifstream &is, Person& person);
    friend ostream &printPerson(ostream &os, const Person& person);
    //构造函数
public:
    Person() = default;
    Person(const string n, const string a) :
        name(n), address(a) { }
    Person(ifstream &is) { read(is, *this); }
    //成员函数
    string getName() const { return name; }
    string getAddress() const { return address; }

private:
    //数据成员
    string name;
    string address;

};

ifstream &read(ifstream &is, Person& person) {
    is >> person.name >> person.address;
    return is;
}

ostream &printPerson(ostream &os, const Person& person) {
    os << person.getName() << " " << person.getAddress();
    return os;
}


#endif //FOREXERCISES_PERSON_H
