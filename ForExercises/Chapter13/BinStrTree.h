//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_BINSTRTREE_H
#define FOREXERCISES_BINSTRTREE_H

#include "TreeNode.h"

//class TreeNode;

class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree& bst) : root(new TreeNode(*bst.root)) {}
    BinStrTree &operator= (const BinStrTree &);
    ~BinStrTree() { delete root; }

private:
    TreeNode *root;
};


#endif //FOREXERCISES_BINSTRTREE_H
