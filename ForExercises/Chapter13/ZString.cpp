//
// Created by carl on 2020/9/13.
//

#include "ZString.h"

#include <algorithm>
#include <iostream>

ZString::ZString(const char *s) {
    char *str = const_cast<char *>(s);
    while (*str)
        ++str;
    range_initializer(s, ++str);
}

ZString::ZString(const ZString &rhs) {
    range_initializer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

ZString::ZString(ZString &&s) noexcept: elements(s.elements), end(s.end) {
    std::cout << "move copy called." << std::endl;
    s.elements = s.end = nullptr;
}

ZString::~ZString() {
    free();
}

ZString & ZString::operator=(const ZString &rhs) {
    auto newStr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newStr.first;
    end = newStr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

ZString & ZString::operator=(ZString &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    std::cout << "move assignment called" << std::endl;
    return *this;
}

std::pair<char *, char *> ZString::alloc_n_copy(const char *b, const char *e) {
    auto newData = alloc.allocate(e - b);
    return {newData, std::uninitialized_copy(b, e, newData)};
}

void ZString::range_initializer(const char *b, const char *e) {
    auto newStr = alloc_n_copy(b, e);
    elements = newStr.first;
    end = newStr.second;
}

void ZString::free() {
    if (elements) {
        std::for_each(elements, end, [this](char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}