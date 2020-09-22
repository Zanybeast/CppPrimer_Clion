
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <forward_list>
#include <stack>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <cctype>
#include <functional>
#include <utility>
#include <cstring>
#include <type_traits>

#include "Sales_data.h"
#include "Blob.h"

using namespace std;

class DebugDelete {
public:
    DebugDelete(ostream &s = cerr) : os(s) { }
    template <typename T> void operator()(T *p) const {
        cout << "deleting unique_ptr" << endl;
        delete p;
    }
private:
    ostream &os;
};

template <typename T> int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}
template <typename P, typename T> P zFind(P begin, P end, const T& value) {
    for (; begin != end; ++begin) {
        if (*begin == value) {
            return begin;
        }
    }

    return end;
}
template <unsigned sz, typename T> void print(const T (&a)[sz]) {
    for (int i = 0; i < sz; ++i)
        cout << a[i] << " ";
}
template <typename T, unsigned sz> constexpr unsigned zSize(const T (&a)[sz]) {
    return sz;
}
template <typename T> void printContainer(const T &container) {
    typename T::size_type sz = container.size();
    for (int i = 0; i != sz; ++i) {
        cout << container.at(i) << " ";
    }
}
template <typename Container> void print16_20(const Container &c) {
    auto iter = c.cbegin();
    for (; iter != c.cend(); ++iter) {
        cout << *iter << " ";
    }
}
template <typename T1, typename T2, typename T3>
T1 sum(T2 a, T3 b) { return a + b; }
template <typename T> auto testFnc(T beg, T end) -> typename remove_reference<decltype(*beg)>::type {
    for (int i = 0; beg != end && i != 5; ++i)
        ++beg;
    return *beg;
}
template <typename T1, typename T2> auto sum16_41(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

template <typename T> string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}
template <typename T> string debug_rep(T *p) {
    ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";

    return ret.str();
}
string debug_rep(const string &s) {
    return '"' + s + '"';
}

template <typename T> void f(T) {
    cout << "f(T)" << endl;
}
template <typename T> void f(const T*) {
    cout << "f(const T*)" << endl;
}
template <typename T> void g(T) {
    cout << "g(T)" << endl;
}
template <typename T> void g(T*) {
    cout << "g(T*)" << endl;
}

template <typename T> ostream &print(ostream &os, const T &t) {
    return os << t;
}
template <typename T, typename... Args> ostream &print(ostream &os, const T &t, const Args&... rest) {
    os << t << ", ";
    return print(os, rest...);
}

void exercise() {
    //E16.54
    int i = 43;
    string s("hello");
    print(cout, i, s, "hi", 45.5);

    //P16.50
    /*int i = 42, *p = &i;
    const int ci = 0, *cp = &ci;
    g(42);
    g(p);
    g(ci);
    g(cp);
    f(42);
    f(p);
    f(ci);
    f(cp);*/

    //P16_41
    /*int a = 23;
    double d = 45.6;
    auto res = sum16_41(a, d);
    cout << res << endl;*/

    //P16.38
    /*auto ptr = make_shared<vector<int>>();
    ptr->push_back(15);
    ptr->push_back(22);
    for (auto &e: *ptr) {
        cout << e << " ";
    }*/

    //P16.37
    /*int i = 322;
    int d = 234.55;
    auto m = max(i, d);
    cout << m << endl;*/

    //P16.20
    /*vector<string> vs = {"good", "job", "baby"};
    print16_20(vs);*/

    //P16.19
    /*vector<string> vs = {"hello", "fuck", "okmybaby"};
    printContainer(vs);
    vector<int> li = {12, 4, 5, 8, 33};
    printContainer(li);*/

    //P16.12
    /*Blob<int> blob = {12, 4, 5, 88, 32};
    BlobPtr<int> bp(blob);
    cout << bp.deref() << endl;

    Blob<string> sblob = {"hello", "my", "name"};
    ConstBlobPtr<string> csblob(sblob);
//    cout << *csblob << " ";
    for (size_t i = 0; i != sblob.size(); ++i) {
        cout << *csblob++ << " ";
    }*/

    //P16.7
    /*int a[5] = {1, 2, 4, 8, 10};
    cout << zSize(a) << endl;*/

    //P16.5
    /*int a[10] = {1, 2, 3, 4, 5, 6};
    const char b[] = "hellomybaby";
    print(a);
    cout << endl;
    print(b);*/

    //P16.4
    /*vector<int> vi = {12, 4, 5, 9, 44, 83};
    list<string> ls = {"hello", "my", "good", "ok"};
    auto p = zFind(vi.begin(), vi.end(), 44);
    if (p != vi.end()) {
        cout << *p << endl;
    } else {
        cout << "No element found" << endl;
    }
    auto p2 = zFind(ls.begin(), ls.end(), "good");
    if (p2 != ls.end()) {
        cout << *p2 << endl;
    }*/

    //P16.3
    /*Sales_data s1("hello", 3, 5);
    Sales_data s2("good", 5, 4);
    compare(s1, s2);*/
}

void testAndVerify() {
    //P616
    /*string s("hi");
    cout << debug_rep(s) << endl;
    cout << debug_rep(&s) << endl;
    const string *sp = &s;
    cout << debug_rep(sp) << endl;*/

    //P612
    /*int a = 12;
    int& ra = a;
    int b = 20, *pb = &b;
    ra = pb;*/

    //P606
    /*vector<int> vi = {2, 4, 5, 8, 13, 9, 44};
    auto res = testFnc(vi.begin(), vi.end());
    cout << res << endl;*/

    //P604
    /*long lng = 23.55;
    int i = 30;
    auto res = sum<double>(lng, i);
    cout << res << endl;*/

    //P603
    /*int a = 14;
//    char c = static_cast<char>(23);
    char c = 'c';
    a = c;
    cout << a << endl;*/

    //P596
    /*double *p = new double;
    DebugDelete d;
    d(p);
    unique_ptr<int, DebugDelete> ip(new int, DebugDelete());*/

    //P587
    /*Blob<int> squares = {1, 2, 4, 5, 8};
    for (size_t i = 0; i < squares.size(); ++i) {
        squares[i] = i * i;
    }
    for (size_t i = 0; i < squares.size(); ++i) {
        cout << squares[i] << " ";
    }
    cout << endl;*/

    //P583
    /*vector<int> v1{33, 43, 83, 13};
    vector<int> v2{33, 43, 83, 13};

    cout << compare(v1, v2) << endl;

    cout << compare(1, 0) << endl;*/
}

int main() {

    exercise();

    testAndVerify();

    return 0;
}
