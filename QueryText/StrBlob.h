//
// Created by carl on 2020/9/16.
//

#ifndef QUERYTEXT_STRBLOB_H
#define QUERYTEXT_STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>


typedef std::vector<std::string> vecStr;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:

    typedef std::vector<std::string>::size_type size_type;

    StrBlob() : data(std::make_shared<vecStr>()) { }
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &s) { data->push_back(s); }
    void pop_back();

    std::string &front();
    std::string &back();


    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<vecStr> data;
    void check(size_type i, const std::string &msg) const;
};

/* *******************************
 *
 *  Implementation for StrBlob
 *
 * *******************************/
inline StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<vecStr>(il)) { }


/* *******************************
*
*   StrBlobPtr class
*
* *******************************/
class StrBlobPtr {
    friend bool isEqual(const StrBlobPtr&, const StrBlobPtr&);

public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) {}
    StrBlobPtr(const StrBlob &s, const size_t sz = 0) :
        wptr(s.data), curr(sz) {};

    std::string &deref() const;
    StrBlobPtr &incr();
    StrBlobPtr &decr();
private:
    std::shared_ptr<vecStr> check(std::size_t, const std::string&) const;
    std::weak_ptr<vecStr> wptr;
    std::size_t curr;
};

inline
std::shared_ptr<vecStr> StrBlobPtr::check(std::size_t sz, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (sz >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
inline
std::string & StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
inline
StrBlobPtr & StrBlobPtr::incr() {
    check(curr, "increment past to end");
    ++curr;
    return *this;
}
inline
StrBlobPtr & StrBlobPtr::decr() {
    --curr;
    check(curr, "decrement past out of begin");
    return *this;
}

/* *******************************
 *
 *  Implementation for StrBlob
 *
 * *******************************/
inline
StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
inline
StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
inline
bool isEqual(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}
inline
bool notEqual(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !isEqual(lhs, rhs);
}

#endif //QUERYTEXT_STRBLOB_H
