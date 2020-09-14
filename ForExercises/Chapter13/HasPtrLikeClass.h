//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_HASPTRLIKECLASS_H
#define FOREXERCISES_HASPTRLIKECLASS_H

#include <string>

class HasPtrLikeClass {
public:
    HasPtrLikeClass(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {};
    HasPtrLikeClass(const HasPtrLikeClass &p) :
        ps(p.ps), i(p.i), use(p.use) { ++*use; };
    HasPtrLikeClass &operator=(const HasPtrLikeClass &);
    ~HasPtrLikeClass();

private:
    std::string *ps;
    int i;
    std::size_t *use;
};


#endif //FOREXERCISES_HASPTRLIKECLASS_H
