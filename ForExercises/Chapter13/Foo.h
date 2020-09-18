//
// Created by carl on 2020/9/14.
//

#ifndef FOREXERCISES_FOO_H
#define FOREXERCISES_FOO_H

#include <vector>
#include <iostream>
#include <algorithm>

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data;
};



#endif //FOREXERCISES_FOO_H
