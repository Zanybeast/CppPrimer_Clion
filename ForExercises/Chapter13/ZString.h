//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_ZSTRING_H
#define FOREXERCISES_ZSTRING_H

#include <memory>

class ZString {
public:
    ZString() : ZString("") { }
    ZString(const char*);
    ZString(const ZString &);
    ZString(ZString &&s) noexcept;
    ZString& operator= (const ZString &rhs);
    ZString& operator= (ZString &&) noexcept;
    ~ZString();

    const char *c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements - 1; }

private:
    std::pair<char*, char*> alloc_n_copy(const char* b, const char* e);
    void range_initializer(const char* b, const char* e);
    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};


#endif //FOREXERCISES_ZSTRING_H
