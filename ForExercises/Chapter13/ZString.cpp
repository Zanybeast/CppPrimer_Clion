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
    range_initializer(rhs.elements, rhs.last);
    std::cout << "copy constructor" << std::endl;
}

ZString::ZString(ZString &&s) noexcept: elements(s.elements), last(s.last) {
    std::cout << "move copy called." << std::endl;
    s.elements = s.last = nullptr;
}

ZString::~ZString() {
    free();
}

ZString & ZString::operator=(const ZString &rhs) {
    auto newStr = alloc_n_copy(rhs.elements, rhs.last);
    free();
    elements = newStr.first;
    last = newStr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

ZString & ZString::operator=(ZString &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        last = rhs.last;
        rhs.elements = rhs.last = nullptr;
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
    last = newStr.second;
}

void ZString::free() {
    if (elements) {
        std::for_each(elements, last, [this](char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, last - elements);
    }
}

std::ostream &operator<<(std::ostream &output, const ZString &s) {
    auto c = s.c_str();
    while (*c) output << *c++;
    return output;
}

bool operator==(const ZString &lhs, const ZString &rhs) {
    return (lhs.size() == rhs.size()) &&
            (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const ZString &lhs, const ZString &rhs) {
    return !(lhs == rhs);
}

bool operator<(const ZString& lhs, const ZString& rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                        rhs.end());
}

bool operator>(const ZString& lhs, const ZString& rhs)
{
    return rhs < lhs;
}

bool operator<=(const ZString& lhs, const ZString& rhs)
{
    return !(rhs < lhs);
}

bool operator>=(const ZString& lhs, const ZString& rhs)
{
    return !(lhs < rhs);
}
