//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_HASPTRLIKEVALUE_H
#define FOREXERCISES_HASPTRLIKEVALUE_H

#include <string>
#include <iostream>

class HasPtrLikeValue {
    friend bool operator<(const HasPtrLikeValue &, const HasPtrLikeValue &);
public:
    friend void swap(HasPtrLikeValue&, HasPtrLikeValue&);
    HasPtrLikeValue(const std::string &s = std::string()) : name(new std::string(s)), value(0) {}
    HasPtrLikeValue(const HasPtrLikeValue& hp) : name(new std::string(*hp.name)), value(hp.value) { }
    HasPtrLikeValue &operator= (const HasPtrLikeValue &hpr) {
        auto new_p = new std::string(*hpr.name);
        delete name;
        name = new_p;
        value = hpr.value;
        return *this;
    }
    ~HasPtrLikeValue() {delete name;}
    std::string getName() {return *name;}
    int getValue() {return value;}
private:
    std::string *name;
    int value;
};
inline void swap(HasPtrLikeValue &lhs, HasPtrLikeValue &rhs) {
    using std::swap;
    swap(lhs.name, rhs.name);
    swap(lhs.value, rhs.value);
    std::cout << "Swap has happended" << std::endl;
}


#endif //FOREXERCISES_HASPTRLIKEVALUE_H
