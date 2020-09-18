//
// Created by carl on 2020/9/14.
//

#ifndef FOREXERCISES_COMPARETWOSTRLENGTH_H
#define FOREXERCISES_COMPARETWOSTRLENGTH_H

#include <string>

class CompareTwoStrLength {
public:
    bool operator()(const std::string &a, const std::string &b) { return a.length() < b.length(); }
};


#endif //FOREXERCISES_COMPARETWOSTRLENGTH_H
