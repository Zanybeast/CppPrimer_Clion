//
// Created by carl on 2020/9/13.
//

#include "BinStrTree.h"

BinStrTree &BinStrTree::operator=(const BinStrTree &bst) {
    TreeNode *new_root = new TreeNode(*bst.root);
    delete root;
    root = new_root;
    return *this;
}