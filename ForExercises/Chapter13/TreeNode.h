//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_TREENODE_H
#define FOREXERCISES_TREENODE_H

#include <string>

class TreeNode {
public:
    TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode& rhs)
        : value(std::string(rhs.value)), count(rhs.count), left(rhs.left), right(rhs.right)
    {
        ++*count;
    }
    ~TreeNode() {
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
    }
    TreeNode& operator= (const TreeNode &);
private:
    std::string value;
    int* count;
    TreeNode *left;
    TreeNode *right;
};


#endif //FOREXERCISES_TREENODE_H
