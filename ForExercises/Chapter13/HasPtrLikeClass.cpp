//
// Created by carl on 2020/9/13.
//

#include "HasPtrLikeClass.h"

HasPtrLikeClass::~HasPtrLikeClass() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtrLikeClass & HasPtrLikeClass::operator=(const HasPtrLikeClass &rhs) {
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}