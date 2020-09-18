//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_STRVEC_H
#define FOREXERCISES_STRVEC_H

#include <memory>
#include <string>
#include <initializer_list>

#include <memory>
#include <string>
#include <initializer_list>

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec(StrVec &&s) noexcept;
    StrVec(std::initializer_list<std::string> il);
    StrVec &operator=(const StrVec&);
    StrVec &operator=(StrVec&& s) noexcept;
    StrVec &operator=(std::initializer_list<std::string> il);
    ~StrVec();

    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    std::string &at(size_t pos) { return *(elements + pos); }
    const std::string &at(size_t pos) const { return *(elements + pos); }
    std::string &operator[](size_t n);
    const std::string &operator[](size_t n) const;

    void reserve(size_t i);
    void resize(size_t count);
    void resize(size_t count, const std::string &s);
private:
    std::allocator<std::string> alloc;
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }

    std::pair<std::string *, std::string*> alloc_n_copy (const std::string* b, const std::string* e);
    void alloc_n_move(size_t newCap);
    void range_initialize(const std::string* b, const std::string * e);
    void free();
    void reallocate();

    std::string *elements;
    std::string *first_free;
    std::string *cap;
};


#endif //FOREXERCISES_STRVEC_H
