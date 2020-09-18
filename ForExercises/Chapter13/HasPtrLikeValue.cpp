//
// Created by carl on 2020/9/13.
//

#include "HasPtrLikeValue.h"

bool operator<(const HasPtrLikeValue &lhs, const HasPtrLikeValue &rhs) {
    return *lhs.name < *rhs.name;
}

HasPtrLikeValue & HasPtrLikeValue::operator=(HasPtrLikeValue &&rhs) noexcept {
    if (this != &rhs) {
        delete name;
        name = rhs.name;
        value = rhs.value;
        rhs.name = nullptr;

    }
    return *this;
}