//
// Created by carl on 2020/9/14.
//

#ifndef FOREXERCISES_COMPARESTRINGLENGTHWITHSIZE_H
#define FOREXERCISES_COMPARESTRINGLENGTHWITHSIZE_H

#include <string>

class CompareStringLengthWithSize {

public:
    CompareStringLengthWithSize(int n) : sz(n) { }
    bool operator()(const std::string &s) { return s.length() >= sz; }
private:
    int sz;
};


#endif //FOREXERCISES_COMPARESTRINGLENGTHWITHSIZE_H
