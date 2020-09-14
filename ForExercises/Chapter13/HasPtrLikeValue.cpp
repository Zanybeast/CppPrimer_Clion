//
// Created by carl on 2020/9/13.
//

#include "HasPtrLikeValue.h"

bool operator<(const HasPtrLikeValue &lhs, const HasPtrLikeValue &rhs) {
    return *lhs.name < *rhs.name;
}