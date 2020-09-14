//
// Created by carl on 2020/9/13.
//

#include <utility>

#include "StrVec.h"

using namespace std;

StrVec::StrVec(const StrVec &s) {
    auto newData = alloc_n_copy(s.begin(), s.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec::StrVec(std::initializer_list<std::string> il) {
    range_initialize(il.begin(), il.end());
}

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

void StrVec::range_initialize(const std::string * b, const std::string * e) {
    auto newData = alloc_n_copy(b, e);
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec::~StrVec() {
    free();
}

StrVec & StrVec::operator=(const StrVec &s) {
    auto newData = alloc_n_copy(s.begin(), s.end());
    free();
    elements = newData.first;
    first_free = cap = newData.second;
    return *this;
}

StrVec & StrVec::operator=(StrVec &&s) noexcept {
    if (this != &s) {
        free();
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;
        s.elements = s.first_free = s.cap = nullptr;
    }
    return *this;
}

void StrVec::reallocate() {
    auto newCapacity = size() ? 2 *size() : 1;
    auto newData = alloc.allocate(newCapacity);

    auto dest = newData;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();

    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
}

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::alloc_n_move(size_t newCap) {
    auto newData = alloc.allocate(newCap);

    auto dest = newData;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();

    elements = newData;
    first_free = dest;
    cap = elements + newCap;

}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for_each(elements, first_free, [this](string &rhs) { alloc.destroy(&rhs); });
//        for (auto p = first_free; p != elements; )
//            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reserve(size_t i) {
    if (i <= capacity()) return;
    alloc_n_move(i);
}

void StrVec::resize(size_t count) {
    resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s) {
    if (count > size()) {
        if (count > capacity()) reserve(count * 2);
        for(size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    } else if(count < size()) {
        while (first_free != elements + count) alloc.destroy(--first_free);
    }
}

