//
// Created by carl on 2020/9/11.
//

#ifndef FOREXERCISES_STRBLOB_H
#define FOREXERCISES_STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

using std::vector;
using std::string;

class StrBlobPtr;

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    StrBlobPtr begin();
    StrBlobPtr end();

    void push_back(const std::string &t) { data->push_back(t); }
    void push_back(const string &t) const { data->push_back(t); }
    void pop_back();

    std::string &front();
    std::string &back();
    const std::string &front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const std::string &back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};
//Constructor implementation
StrBlob::StrBlob() : data(std::make_shared<vector<string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<vector<string>>(il)) { }
void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}
string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    std::string &deref() const;
    StrBlobPtr & incr();
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string & msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

#endif //FOREXERCISES_STRBLOB_H
