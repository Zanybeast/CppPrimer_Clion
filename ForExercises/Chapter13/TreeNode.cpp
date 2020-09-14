//
// Created by carl on 2020/9/13.
//

#include "TreeNode.h"

TreeNode &TreeNode::operator=(const TreeNode &rhs) {
    ++*rhs.count;
    if (--*count == 0) {
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }

        delete count;
        count = nullptr;
    }

    value = rhs.value;
    left = rhs.left;
    right = rhs.right;
    count = rhs.count;

    return *this;
}