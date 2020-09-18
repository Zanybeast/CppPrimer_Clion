//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_ZSTRING_H
#define FOREXERCISES_ZSTRING_H

#include <memory>
#include <iostream>

class ZString {
    friend std::ostream &operator<<(std::ostream & output, const ZString &);
    friend bool operator==(const ZString &, const ZString &);
    friend bool operator!=(const ZString &, const ZString &);
    friend bool operator<(const ZString&, const ZString&);
    friend bool operator>(const ZString&, const ZString&);
    friend bool operator<=(const ZString&, const ZString&);
    friend bool operator>=(const ZString&, const ZString&);
public:
    ZString() : ZString("") { }
    ZString(const char*);
    ZString(const ZString &);
    ZString(ZString &&s) noexcept;
    ZString& operator= (const ZString &rhs);
    ZString& operator= (ZString &&) noexcept;
    char &operator[](size_t n) { return elements[n]; }
    const char &operator[](size_t n) const { return elements[n]; }
    ~ZString();

    const char *c_str() const { return elements; }
    size_t size() const { return last - elements; }
    size_t length() const { return last - elements - 1; }

    char * begin() const { return elements; }
    char * end() const { return last; }

private:
    std::pair<char*, char*> alloc_n_copy(const char* b, const char* e);
    void range_initializer(const char* b, const char* e);
    void free();

private:
    char *elements;
    char *last;
    std::allocator<char> alloc;
};

#endif //FOREXERCISES_ZSTRING_H
