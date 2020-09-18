//
// Created by carl on 2020/9/14.
//

#ifndef FOREXERCISES_BOUNDSTRCHECK_H
#define FOREXERCISES_BOUNDSTRCHECK_H

#include <string>

class BoundStrCheck {
public:
    BoundStrCheck(std::size_t l, std::size_t u) : lower(l), upper(u) {}
    bool operator() (const std::string &s) {
        return lower <= s.length() && s.length() <= upper;
    }

private:
    std::size_t upper;
    std::size_t lower;
};


#endif //FOREXERCISES_BOUNDSTRCHECK_H
