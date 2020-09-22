//
// Created by carl on 2020/9/19.
//

#ifndef CHAPTER16_BLOB_H
#define CHAPTER16_BLOB_H

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <initializer_list>


template <typename> class BlobPtr;
template <typename> class ConstBlobPtr;
template <typename> class Blob;

//=================================================================================
//
//		StrBlob - custom vector<T>
//
//=================================================================================

template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator< (const Blob<T>&, const Blob<T>&);
template <typename T> bool operator> (const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob {
    //Friend function and class
    friend class ConstBlobPtr<T>;
    friend class BlobPtr<T>;

    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator> <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator<=<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator>=<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef typename std::vector<T>::size_type size_type;
    //Constructor
    Blob(): data(std::make_shared<std::vector<T>>()) { }
    Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) { }
    template <typename It> Blob(It a, It b);

    //Copy and assignment
    Blob(const Blob &b) : data(std::make_shared<std::vector<T>>(*b.data)) { }
    Blob(Blob &&rhs) noexcept : data(std::move(*rhs.data)) {}

    Blob &operator=(const Blob&);
    Blob &operator=(Blob &&) noexcept;

    //Members function
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    BlobPtr<T> begin();
    BlobPtr<T> end();
    ConstBlobPtr<T> cbegin() const;
    ConstBlobPtr<T> cend() const;

    T& operator[](size_type i);
    const T&operator[] (size_type i) const;

    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();

    T& front();
    T& back();
    const T& front() const;
    const T& back() const;

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)){ }

//Override operator
template <typename T> bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) {
    return *lhs.data == *rhs.data;
}
template <typename T> bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs) {
    return !(lhs == rhs);
}
template <typename T> bool operator< (const Blob<T>& lhs, const Blob<T>& rhs) {
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
                                        rhs.data->begin(), rhs.data->end());
}
template <typename T> bool operator> (const Blob<T>& lhs, const Blob<T>& rhs) {
    return rhs < lhs;
}
template <typename T> bool operator<=(const Blob<T>& lhs, const Blob<T>& rhs) {
    return !(rhs < lhs);
}
template <typename T> bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs) {
    return !(lhs < rhs);
}

//Member functions
template <typename T> Blob<T> & Blob<T>::operator=(const Blob<T> &lhs) {
    data = std::make_shared<std::vector<T>>(*lhs.data);
    return *this;
}
template <typename T> Blob<T> & Blob<T>::operator=(Blob<T> &&rhs) noexcept {
    if (this != &rhs) {
        data = std::move(rhs.data);
        rhs.data = nullptr;
    }
    return *this;
}
template <typename T> BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this);
}
template <typename T> BlobPtr<T> Blob<T>::end() {
    return BlobPtr<T>(*this, data->size());
}
template <typename T> ConstBlobPtr<T> Blob<T>::cbegin() const {
    return ConstBlobPtr<T>(*this);
}
template <typename T> ConstBlobPtr<T> Blob<T>::cend() const {
    return ConstBlobPtr<T>(*this, data->size());
}

template <typename T> T & Blob<T>::operator[](size_type i) {
    check(i, "out of range");
    return data->at[i];
}
template <typename T> const T & Blob<T>::operator[](size_type i) const {
    check(i, "out of range");
    return data->at[i];
}
template <typename T> void Blob<T>::pop_back() {
    check(0, "pop_back on empty blob");
    data->pop_back();
}
template <typename T> T & Blob<T>::front() {
    check(0, "front on empty blob");
    return data->front();
}
template <typename T> const T & Blob<T>::front() const {
    check(0, "front on empty blob");
    return data->front();
}
template <typename T> T & Blob<T>::back() {
    check(0, "back on empty blob");
    return data->back();
}
template <typename T> const T & Blob<T>::back() const {
    check(0, "back on empty blob");
    return data->back();
}
template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}


//=================================================================================
//
//		BlobPtr - custom vector<T>
//
//=================================================================================

template <typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator< (const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator> (const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator<=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator>=(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr {
    friend bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator< (const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator> (const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator<=(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator>=(const BlobPtr<T> &, const BlobPtr<T> &);

public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &blob, size_t n = 0) : wptr(blob.data), curr(0) { }

    T& deref() const;
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    BlobPtr &operator+=(size_t);
    BlobPtr &operator-=(size_t);
    BlobPtr operator+(size_t) const;
    BlobPtr operator-(size_t) const;

    T& operator[](size_t n);
    const T& operator[](size_t n) const;
private:
    std::shared_ptr<std::vector<T>> check(size_t sz, const std::string& msg) const;
    std::weak_ptr<std::vector<T>> wptr;
    size_t curr;
};

template <typename T> std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_t sz, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound BlobPtr");
    }
    if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

template <typename T> T & BlobPtr<T>::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T> BlobPtr<T> & BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}
template <typename T> BlobPtr<T> & BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past to the begin of BlobPtr");
    return *this;
}
template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr<T> ret = *this;
    ++*this;
    return ret;
}
template <typename T> BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr<T> ret = *this;
    --*this;
    return ret;
}
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return lhs.curr == rhs.curr;
}
template <typename T> bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return !(lhs == rhs);
}
template <typename T> bool operator<(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr < y.curr;
}
template <typename T> bool operator>(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr > y.curr;
}
template <typename T> bool operator<=(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr <= y.curr;
}
template <typename T> bool operator>=(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr >= y.curr;
}
template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of Blob<T>Ptr");
    return *this;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of Blob<T>Ptr");
    return *this;
}
template <typename T> inline BlobPtr<T> BlobPtr<T>::operator+(size_t n) const
{
    BlobPtr<T> ret = *this;
    ret += n;
    return ret;
}

template <typename T> inline BlobPtr<T> BlobPtr<T>::operator-(size_t n) const
{
    BlobPtr<T> ret = *this;
    ret -= n;
    return ret;
}
template <typename T> inline T& BlobPtr<T>::operator[](size_t n)
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}
template <typename T> inline const T& BlobPtr<T>::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

//=================================================================================
//
//		ConstStrBlob - custom vector<T>
//
//=================================================================================

template <typename T>
bool operator==(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator!=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator<(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator<=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator>=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);

template <typename T> class ConstBlobPtr {
    friend bool operator==<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    friend bool operator!=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    // clang-format off
    friend bool operator< <T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    friend bool operator> <T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    // clang-format on
    friend bool operator<=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    friend bool operator>=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);

public:
    ConstBlobPtr() : curr(0) {}
    ConstBlobPtr(const Blob<T>& s, size_t sz = 0) : wptr(s.data), curr(sz) {}

    const T& operator*() const;
    const T* operator->() const;
    ConstBlobPtr& operator++();
    ConstBlobPtr& operator--();
    ConstBlobPtr operator++(int);
    ConstBlobPtr operator--(int);
    ConstBlobPtr& operator+=(size_t);
    ConstBlobPtr& operator-=(size_t);
    ConstBlobPtr operator+(size_t) const;
    ConstBlobPtr operator-(size_t) const;

    const T& operator[](size_t n) const;

private:
    std::shared_ptr<std::vector<T>> check(size_t, const T&) const;

    std::weak_ptr<std::vector<T>> wptr;
    size_t curr;
};

//------------------------------------------------------------------------------
//  friend function.
//------------------------------------------------------------------------------

template <typename T>
bool operator==(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr > rhs.curr;
}

template <typename T>
bool operator<=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr <= rhs.curr;
}

template <typename T>
bool operator>=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr >= rhs.curr;
}

//------------------------------------------------------------------------------
//  member function.
//------------------------------------------------------------------------------

template <typename T> inline const T& ConstBlobPtr<T>::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T> inline const T* ConstBlobPtr<T>::operator->() const
{
    return &this->operator*();
}

template <typename T> inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator++()
{
    check(curr, "increment past end of ConstBlob<T>Ptr");
    ++curr;
    return *this;
}

template <typename T> inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator--()
{
    --curr;
    check(-1, "decrement past begin of ConstBlob<T>Ptr");
    return *this;
}

template <typename T> inline ConstBlobPtr<T> ConstBlobPtr<T>::operator++(int)
{
    ConstBlobPtr<T> ret = *this;
    ++*this;
    return ret;
}

template <typename T> inline ConstBlobPtr<T> ConstBlobPtr<T>::operator--(int)
{
    ConstBlobPtr<T> ret = *this;
    --*this;
    return ret;
}

template <typename T>
inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of ConstBlob<T>Ptr");
    return *this;
}

template <typename T>
inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of ConstBlob<T>Ptr");
    return *this;
}

template <typename T>
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator+(size_t n) const
{
    ConstBlobPtr<T> ret = *this;
    ret += n;
    return ret;
}

template <typename T>
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator-(size_t n) const
{
    ConstBlobPtr<T> ret = *this;
    ret -= n;
    return ret;
}

template <typename T>
inline std::shared_ptr<std::vector<T>> ConstBlobPtr<T>::check(size_t i,
const T& msg) const
{
auto ret = wptr.lock();
if (!ret) throw std::runtime_error("unbound Blob<T>Ptr");
if (i >= ret->size()) throw std::out_of_range(msg);
return ret;
}

template <typename T>
inline const T& ConstBlobPtr<T>::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

#endif //CHAPTER16_BLOB_H
