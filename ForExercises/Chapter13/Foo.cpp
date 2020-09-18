//
// Created by carl on 2020/9/14.
//

#include "Foo.h"

Foo Foo::sorted() &&{
    std::sort(data.begin(), data.end());
    std::cout << "called &&" << std::endl;
    return *this;
}

Foo Foo::sorted() const &{
    std::cout << "call const &" << std::endl;
    return Foo(*this).sorted();
}