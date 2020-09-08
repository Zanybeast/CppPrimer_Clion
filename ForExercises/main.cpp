// ForExercises.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <forward_list>
#include <stack>
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"
#include "Window_mgr.h"
#include "MyDate.h"

#define NDEBUG

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int fact(int n) {
    int res = 1;
    while (n > 1) {
        res *= n;
        n--;
    }
    return res;
}
void E6_04() {
    int i = 0;
    cout << "Please enter a number: " << endl;
    cin >> i;
    cout << "The factorial of the number is " << fact(i) << endl;
}
int absValue(int i) {
    return (i >= 0) ? i : -i;
}
bool isPrefixVector(vector<int> vi1, vector<int> vi2) {
    vector<int>::size_type sz = vi1.size() > vi2.size() ? vi2.size() : vi1.size();

    if (sz == 0) {
        return true;
    }
    for (int i = 0; i < sz; ++i) {
        if (vi1[i] != vi2[i])
            return false;
    }

    return true;
}
void swap(int *a, int *b) {
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swapUsingRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
bool hasCapital(const string &s) {
    for (auto &c: s) {
        if (isupper(c))
            return true;
    }
    return false;
}
void stringToLowercase(string &s) {
    if (!s.empty()) {
        for (auto &c: s) {
            c = tolower(c);
        }
    }
}
int biggerInteger(int a, const int *p) {
    return a >= *p ? a : *p;
}
void swapPointer(int *&a, int *&b) {
    auto temp = a;
    a = b;
    b = temp;
}
void printf(const int &i) {
    cout << i << endl;
}
void printf(const int* beg, const int* end) {
    while (beg != end) {
        cout << *beg++ << " ";
    }
}
void print6_24(const int ia[10]) {

    for (size_t i = 0; i != 10; ++i) {
        cout << *ia++ << " ";
    }

}
int sum(initializer_list<int> il) {
    int sum = 0;
    for (auto begin = il.begin(); begin != il.end(); ++begin) {
        sum += *begin;
    }

    return sum;
}
int &get(int *array, int index) {
    return array[index];
}
void vectorOutput(vector<int> &vi, vector<int>::iterator it) {
    if (it == vi.end()) {
        return;
    } else {
        cout << *it << " ";
        vectorOutput(vi, it + 1);
    }
}
string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}
constexpr bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}
void printVector(vector<int> &vi) {
#ifdef NDEBUG
    cout << "Vector size: " << vi.size() << endl;
#endif
    if (!vi.empty()) {
        auto tmp = vi.back();
        vi.pop_back();
        printVector(vi);
        cout << tmp << " " ;
    }
}
void f() {
    cout << "f()" << endl;
}
void f(int, int) {
    cout << "f(int, int)" << endl;
}
void f(int) {
    cout << "f(int)" << endl;
}
void f(double, double d = 3.55) {
    cout << "f(double, double d = 3.55)" << endl;
}
istream &E8_01(istream & input) {
    string s;
    while (input >> s)
        cout << s << endl;

    input.clear();
    return input;
}

int sum(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiple(int a, int b) {
    return a * b;
}
int divide(int a, int b) {
    return a / b;
}

bool valid(string number) {
    if (number.size() < 8)
        return false;
    return true;
}
string format(string number) {
    string formatStr = "+86-" + number;
    return formatStr;
}

bool findInt(vector<int>::iterator begin, vector<int>::iterator end, int sought) {
    while (begin != end) {
        if (*begin == sought)
            return true;
        begin++;
    }
    return false;
}
vector<int>::iterator findIntReturnIterator(vector<int>::iterator begin, vector<int>::iterator end, int sought) {
    while (begin != end) {
        if (*begin == sought)
            return begin;
        ++begin;
    }
    return end;
}
void printVector09(string s, vector<int> vi) {
    cout << s << ": ";
    for (const auto i: vi) {
        cout << i << " ";
    }
    cout << endl;
}

void insertString09_28(forward_list<string> &fls, const string& s1, const string& s2) {
    auto curr = fls.begin();
    auto prev = fls.before_begin();
    int count = 0;
    while (curr != fls.end()) {
        if (*curr == s1) {
            curr = fls.insert_after(curr, s2);
            ++count;
        }
        prev = curr;
        ++curr;
    }
    if (curr == fls.end() && count == 0) {
        fls.insert_after(prev, s2);
    }
}
void replaceString09_43(string &s, const string &oldVal, const string &newVal) {
    for (auto beg = s.begin(); distance(beg, s.end()) >= distance(oldVal.begin(), oldVal.end()); ) {
        if (string{beg, beg + oldVal.size()} == oldVal) {
            beg = s.erase(beg, beg + oldVal.size());
            beg = s.insert(beg, newVal.cbegin(), newVal.cend());
            advance(beg, newVal.size());
        } else
            ++beg;
    }
}
void replaceString09_44(string &s, const string &oldVal, const string &newVal) {
    for (size_t i = 0; i < s.size(); i++) {
        if (string(s, i, oldVal.size()) == oldVal) {
            s.replace(i, oldVal.size(), newVal);
            i = i + newVal.size() - 1;
        }
    }
}
string &formatName(string &name, const string &prefix, const string &suffix) {
    if (!prefix.empty()) {
        auto beg = name.begin();
        beg = name.insert(beg, prefix.begin(), prefix.end());
        name.insert(prefix.size(), " ");
    }

    if (!suffix.empty()) {
        name.append(" " + suffix);
    }

    return name;
}
string &formatName2(string &name, const string &prefix, const string &suffix) {
    name.insert(0, prefix + " ");
    auto currSize = name.size();
    name.insert(currSize, " " + suffix);

    return name;
}
void findString09_47(string &s) {
    const string numbers{"0123456789"};
    const string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string::size_type pos = 0;
    while ((pos = s.find_first_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos << " ---element is: " << s[pos] << endl;
        ++pos;
    }
    pos = 0;
    while ((pos = s.find_first_of(alphabet, pos)) != string::npos) {
        cout << "found alphabet at index: " << pos << "---element is: " << s[pos] << endl;
        ++pos;
    }
    cout << endl;
}
void findString09_48(string &s) {
    const string numbers{"0123456789"};
    const string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    cout << "Numbers: " << endl;
    for (string::size_type pos = 0; (pos = s.find_first_not_of(alphabet, pos)) != string::npos; ++pos) {
        cout << "s[" << pos << "] = " << s[pos] << endl;
    }
    cout << "Alphabet" << endl;
    for (string::size_type pos = 0; (pos = s.find_first_not_of(numbers, pos)) != string::npos; ++pos) {
        cout << "s[" << pos << "] = " << s[pos] << endl;
    }

}

int chapter02() {

    //E2.37
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    ++c;
    ++d;
    cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;


    //E2.36
    //int a = 3, b = 4;
    //decltype(a) c = a;
    //decltype((b)) d = a;
    //++c;
    //++d;
    //cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;     //a=4, b=4, c=4, d=4
    ////加了括号的decltype其推断结果必然是引用



    //E2.32
    /*constexpr int null = 0;
    int* p = null;*/
    //constexpr int null = 0, * p = null;
    //可能是在考察constexpr变量一定是一个常量, 而且必须用常量表达式初始化


    //E2.21
//    int i = 0;
//    double* dp = &i;
//    int* ip = i;
//    int* p = &i;
//    前面两个非法，第一个指针类型和指针所指向类型要匹配；第二个不能把变量直接赋值给指针


    //E2.20
    /*int i = 20;
    int* pi = &i;
    *pi = *pi * *pi;
    cout << "i = " << i << ", *pi = " << *pi << endl;*/


    //E2.19
    /*指针存放对象的地址，指针可以在定义的时候不初始化，指针本身是一个对象，指针在定义了另一个对象之后可以重新让其指向另一个对象；
    引用是对象的别名，所以引用在定义的时候必须初始化，而且引用一旦定义了之后不能更改，它始终与初始对象绑定在一起；*/


    //E2.18
    /*int ival = 1024;
    int ival2 = 1000;
    int* ip = &ival;
    cout << "ival = " << ival << ", ip = " << ip << endl;
    *ip = 2048;
    cout << "ival changed and its value is " << ival << endl;
    ip = &ival2;
    cout << "ip changed, ival = " << ival << ", ip = " << ip << endl;*/


    //E2.17
    /*int i, & ri = i;
    i = 5;
    ri = 10;
    cout << "i = " << i << ", ri = " << ri << endl;*/

    return 0;

}
int chapter03() {

    //E3.44
    int ia[3][4] = {
            {3, 5, 7, 9},
            {6, 8, 11, 4},
            {20, 30 ,40, 50}
    };
    using int4_array = int[4];
    for (int4_array *p = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }




    //E3.43
//    int ia[3][4] = {
//            {3, 5, 7, 9},
//            {6, 8, 11, 4},
//            {20, 30 ,40, 50}
//    };
//    cout << "ia[3][4] = " << endl;
//    for (const auto &row: ia) {
//        for (auto element: row) {
//            cout << element << " ";
//        }
//        cout << endl;
//    }
//    cout << "using index: " << endl;
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            cout << ia[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << "using pointer: " << endl;
//    for (auto p = begin(ia); p != end(ia); ++p) {
//        for (auto q = begin(*p); q != end(*p); ++q) {
//            cout << *q << " ";
//        }
//        cout << endl;
//    }


    //E3.36
//    int a[5] = {1, 3, 5, 7, 9};
//    int b[6] = {1, 3, 5, 7, 9, 8};
//    auto abegin = begin(a);
//    auto aend = end(a);
//    auto asize = aend - abegin;
//    auto bbegin = begin(b);
//    auto bend = end(b);
//    auto bsize = bend - bbegin;
//    if (asize != bsize) {
//        cout << "Two arrays not equal." << endl;
//        return -1;
//    }
//    for (int i = 0; i < asize; ++i) {
//        if (a[i] != b[i]) {
//            cout << "Two arrays not equal." << endl;
//            return -1;
//        }
//    }
//    cout << "Two arrays equal." << endl;


    //E3.35
//    int a[10];
//    int *p = a;
//    for (int i = 0; i < 10; ++i) {
//        *(p + i) = 5;
//    }
//    for(auto i: a) {
//        cout << i << " ";
//    }
//    cout << endl;


    //E3.34
//    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int *p1 = a + 2;
//    int *p2 = a + 6;
//    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;
//    p1 += p2 - p1;
//    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;



    //E3.32
//    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int a2[10] = {};
//    for(size_t i = 0; i < 10; ++i) {
//        a2[i] = array[i];
//    }
//    for(auto i: a2) {
//        cout << i << " ";
//    }
//    cout << endl;



    //E3.25
//    vector<unsigned> vi {42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93, 8, 17, 84, 66};
//    //result should be {1 1 0 1 1 0 3 3 3 4 1}
//    vector<unsigned> result(11, 0);
//    auto ri = result.begin();
//    for(auto it = vi.begin(); it != vi.end(); ++it) {
//        if (*it <= 100) {
//            ++(*(ri + (*it) / 10));
//        }
//    }
//    for(const auto i: result) {
//        cout << i << " ";
//    }
//    cout << endl;


    //E3.24
//    vector<int> vi = {12, 4, 5, 9, 8, 17, 6, 33, 42};
//    for(auto it = vi.begin(); it != (vi.end() - 1); ++it) {
//        cout << *it + *(it + 1) << " ";
//    }
//    cout << endl;
//    for(auto b = vi.begin(), e = vi.end() - 1; b != vi.end(); ++b, --e) {
//        cout << *b + *e << " ";
//    }
//    cout << endl;


    //E3.23
//    vector<int> vi = {12, 3, 5, 33, 44, 108, 9, 14, 7, 54};
//    for(auto it = vi.begin(); it != vi.end(); ++it) {
//        *it = (*it) * (*it);
//    }
//    for (auto i: vi) {
//        cout << i << " ";
//    }
//    cout << endl;
//    auto b = vi.begin(); auto e = vi.end();
//    cout << e - b << endl;



    //E3.22
//    vector<string> text {"My name is Jack.", "", "I come from California.", "", "Nice to meet you guys."};
//    for(auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
//        for (auto &c: *it) {
//            c = toupper(c);
//        }
//    }
//    for (auto s: text) {
//        cout << s << " ";
//    }

    //E3.21
//    vector<int> v1;
//    vector<int> v2(10);
//    vector<int> v3(10, 42);
//    vector<int> v4{10};
//    vector<int> v5{10, 42};
//    vector<string> v6{10};
//    vector<string> v7{10, "hi"};
//    for (auto it = v1.begin(); it != v1.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << "v1 size is " << v1.size() << endl;
//    for (auto it = v2.begin(); it != v2.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << "v2 size is " << v2.size() << endl;
//    for (auto it = v3.begin(); it != v3.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << "v3 size is " << v3.size() << endl;
//    for (auto it = v4.begin(); it != v4.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << "v4 size is " << v4.size() << endl;
//    for (auto it = v5.begin(); it != v5.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << "v5 size is " << v5.size() << endl;
//    for (auto it = v6.begin(); it != v6.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << "v6 size is " << v6.size() << endl;
//    for (auto it = v7.begin(); it != v7.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << "v7 size is " << v7.size() << endl;




    //E3.20
//    vector<int> vi {12, 33, 23, 35, 48, 16, 29, 11, 7, 9};
//    for(int i = 0; i < vi.size(); ++i) {
//        cout << vi[i] + vi[vi.size() - 1 - i] << " ";
//    }
//    cout << endl;



    //E3.17
//    vector<string> vs;
//    string word;
//    while (cin >> word) {
//        vs.push_back(word);
//    }
//    for (auto &s: vs) {
//        for(auto &c: s) {
//            c = toupper(c);
//        }
//        cout << s << endl;
//    }



    //E3.15
//    string s;
//    vector<string> vi;
//    while (cin >> s) {
//        vi.push_back(s);
//    }
//    for (auto s : vi) {
//        cout << s << " ";
//    }
//    cout << endl;



    //E3.14
//    int i;
//    vector<int> vi;
//    while (cin >> i) {
//        vi.push_back(i);
//    }
//    for (auto i : vi) {
//        cout << i << " ";
//    }
//    cout << endl;



    //E3.10
//    string s = "Hello every, it's me again!!!";
//
//    for (auto &c: s) {
//        if (!ispunct(c)) {
//            cout << c;
//        }
//    }
//    cout << endl;


    //E3.9
//    string s = "";
//    cout << s[100] << endl;
//    cout << "Hello world" << endl;


    //E3.7
//    string s;
//    cout << "Enter a word: " << endl;
//    cin >> s;
//    for (char c : s) {
//        c = 'X';
//    }
//    cout << s << endl;

    //E3.6
    /*string s;
    cout << "Enter a word: " << endl;
    cin >> s;
    for (auto& c : s) {
        c = 'X';
    }
    cout << s << endl;*/


    //E3.5
    /*string word, s;
    while (cin >> word)
    {
        s += word;
    }
    cout << s;*/
    /*string s, word;
    while (cin >> word)
    {
        s += (word + " ");
    }
    cout << s;*/


    //E3.4
    /*string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
    {
        cout << "s1 equals to s2" << endl;
    }
    else if (s1 > s2)
    {
        cout << s1 << endl;
    }
    else
    {
        cout << s2 << endl;
    }*/


    //E3.3
    /*string会将字符串前面的空白字符忽略掉, 直到真正有字符输入为止; 而且在遇到下一个空白的时候结束;
    getline不会忽略空白,只对换行符敏感. 在遇到换行符后结束输入*/

    return 0;
}
int chapter04() {

    //E4.36
//    int i = 3;
//    double d = 2.5;
//    cout << (i *= static_cast<int>(d)) << endl;


    //E4.29
//    int x[10]; int *p = x;
//    cout << sizeof(x) / sizeof(*x) << endl;
//    cout << sizeof(p) / sizeof(*p) << endl;



    //E4.28
//    cout << "size of char = " << sizeof(char) << endl;
//    cout << "size of boolean = " << sizeof(bool) << endl;
//    cout << "size of short int = " << sizeof(short) << endl;
//    cout << "size of int = " << sizeof(int) << endl;
//    cout << "size of long = " << sizeof(long) << endl;
//    cout << "size of long long = " << sizeof(long long int) << endl;
//    cout << "size of float = " << sizeof(float) << endl;
//    cout << "size of double = " << sizeof(double) << endl;
//    cout << "size of long double = " << sizeof(long double) << endl;



    //E4.27
//    unsigned long ul1 = 3, ul2 = 7;
//    cout << (ul1 & ul2) << endl;
//    cout << (ul1 | ul2) << endl;
//    cout << (ul1 && ul2) << endl;
//    cout << (ul1 || ul2) << endl;



    //E4.25
//    cout << (~'q' << 6) << endl;

    //E4.20
//    vector<string> vs = {"hello", "baby"};
//    vector<string>::iterator iter = vs.begin();
//    int i = iter++->empty();
//    cout << *iter << endl;



    //E4.14
//    int i = 0;
//    if (42 = i) {
//        cout << "true";
//    } else {
//        cout << "false";
//    }



    //E4.13
//    int i; double d;
////    d = i = 3.5;
//    i = d = 3.5;
//    cout << "d = " << d << ", i = " << i << endl;



    //E4.12
//    int i = 1, j = 20, k = 0;
//    if (i != j < k) {
//        cout << "i != j < k" << endl;
//    } else {
//        cout << "Unknown" << endl;
//    }


    //E4.10
//    int i = 0;
//    while (cin >> i) {
//        if (i == 42) {
//            return 0;
//        }
//    }
}
int chapter05() {
    //E5.21
    string word, preword;
    while (cin >> word) {
        if (!isupper(word[0])) {
            preword = "";
            continue;
        }

        if (preword == word) {
            cout << "Repeated word occurs: " << word << endl;
            break;
        }
    }

    if (cin.eof())
        cout << "No words repeat." << endl;


    //E5.20
//    string word, preword;
//    while (cin >> word) {
//        if (preword == word) {
//            cout << "Repeated word occurs: " << word << endl;
//            break;
//        }
//        preword = word;
//    }
//    if (cin.eof())
//        cout << "No words repeat." << endl;



    //E5.19
//    string s1, s2;
//    string instruction;
//    do {
//        cout << "Please enter two string: " << endl;
//        cin >> s1 >> s2;
//        if (s1.size() == s2.size()) {
//            cout << "The same length of two string." << endl;
//        } else if (s1.size() > s2.size()) {
//            cout << "The shorter one is " << s2 << endl;
//        } else {
//            cout << "The shorter one is " << s1 << endl;
//        }
//
//        cout << "Continue? Enter y/Y or n/N: " << endl;
//        cin >> instruction;
//    } while (!instruction.empty() && (instruction[0] != 'n' && instruction[0] != 'N'));


    //E5.17
//    vector<int> vi1 = {0, 1, 1, 3};
//    vector<int> vi2 = {0, 1, 1, 3, 5, 9, 10};
//
//    if (isPrefixVector(vi1, vi2)) {
//        cout << "vi1 is prefix of vi2" << endl;
//    } else {
//        cout << "Not prfix!!!!!" << endl;
//    }



    //E5.14
//    string word;
//    int count = 1, maxCnt = 1;
//    string lastStr = "";
//    string maxStr = "";
//    while (cin >> word) {
//        if (lastStr == word) {
//            ++count;
//        } else {
//            if (count > 1 && count > maxCnt) {
//                maxCnt = count;
//                maxStr = lastStr;
//                count = 1;
//            } else {
//                count = 1;
//            }
//        }
//        lastStr = word;
//    }
//    if (maxCnt <= 1) {
//        cout << "No word repeats." << endl;
//    } else {
//        cout << "Max string is " << maxStr << " and appears " << maxCnt << " times." << endl;
//    }



    //E5.5
//    const vector<string> vc = {"F", "D", "C", "B", "A", "A++"};
//
//    int grade = 0;
//    while (cin >> grade) {
//        string lettergrade;
//        if (grade < 60) lettergrade = vc[0];
//        else {
//            lettergrade = vc[(grade - 50) / 10];
//            if (grade != 100) {
//                if (grade % 10 > 7)
//                    lettergrade += "+";
//                else if (grade % 10 < 3)
//                    lettergrade += "-";
//            }
//        }
//        cout << lettergrade << endl;
//    }
}
int chapter06() {
    //E6.54
    int f1(int, int);
    typedef int(*fp1)(int, int);
    using fp2 = int (*) (int, int);
    typedef decltype(f1) *fp3;
    using fp4 = decltype(f1) *;

    vector<decltype(f1) *> vfp = {sum, subtract, multiple, divide};
    int a = 120, b = 6;
    for (auto f : vfp) {
        cout << f(a, b) << endl;
    }



    //E6.51
//    f(42);
//    f(42, 0);
//    f(2.56, 4.11);


    //E6.47
//    vector<int> vi = {2, 4, 5, 10, 11, 23, 88};
//    printVector(vi);


    //E6.46
//    cout << isShorter("fsdhfsauuuuuuuuuuuuuqqqqqa", "fsjaohfwuf") << endl;


    //E6.41
//    cout << make_plural(2, "success", "es") << endl;
//    cout << make_plural(5, "failure") << endl;


    //E6.36
//    string (&func(string (&array)[10]))[10];
//    using sA = string[10];
//    sA &func(sA (&sa));
//
//    auto func(sA &sa) -> string (&) [10];
//    string as[10];
//    decltype(as) &func3(sA &sa);

    //E6.33
//    vector<int> vi = {2, 4, 5, 10, 11, 23, 88};
//    vectorOutput(vi, vi.begin());


    //E6.32
//    int ia[10];
//    for (int i = 0; i < 10; ++i) {
//        get(ia, i) = i;
//    }
//    for (const auto i: ia) {
//        cout << i << " " ;
//    }


    //E6.27
//    cout << "sum of some integers is " << sum({12, 3, 5, 8, 18}) << endl;


    //E6.24
//    int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    print6_24(i);


    //E6.23
//    int i = 1001, j[5] = {0, 1, 3, 5, 8};
//    printf(i);
//    printf(begin(j), end(j));


    //E6.22
//    int a = 20, b = 30;
//    int *pa = &a, *pb = &b;
//    cout << "*pa = " << *pa << ", *pb = " << *pb << endl;
//    swapPointer(pa, pb);
//    cout << "*pa = " << *pa << ", *pb = " << *pb << endl;


    //E6.21
//    int a = 1200, b = 2000;
//    cout << biggerInteger(a, &b) << endl;


    //E6.18
//    bool compare(matrix &, matrix &);
//    vector<int>::iterator change_val(int, vector<int>::iterator);



    //E6.17
//    string s1 = "Hello everyone.";
//    string s2 = "no capital here";
//    if (hasCapital(s2)) {
//        cout << "String has capital." << endl;
//    } else {
//        cout << "No capital" << endl;
//    }
//    string s3 = "ALL LETTERS ARE CAPITAL. HAHA!";
//    stringToLowercase(s3);
//    cout << s3 << endl;


    //E6.12
//    int a = 10, b = 20;
//    cout << "a = " << a << ", b = " << b << endl;
//    swapUsingRef(a, b);
//    cout << "a = " << a << ", b = " << b << endl;

    //E6.10
//    int a = 10, b = 20;
//    cout << "a = " << a << ", b = " << b << endl;
//    swap(&a, &b);
//    cout << "a = " << a << ", b = " << b << endl;

    //E6.5
//    cout << "Absolute value: " << absValue(-55) << endl;

//    E6_04();

    return 0;
}
int chapter07() {
    class C;
    //E7.43
    class NoDefault { ;
        friend C;
        NoDefault(int i) {}
    };

    class C {
    public:
        C() : nd(0) { };
    private:
        NoDefault nd;
    };


    //E7.41
//    ifstream input;
//    Sales_data s1;
//    Sales_data s2 = Sales_data("empty");
//    Sales_data s3 = Sales_data("ha", 2, 5);
//    Sales_data s4 = Sales_data(input);


    //E7.27
//    Screen myScreen(5, 5, 'X');
//    myScreen.move(4, 0).set('#').display(cout);
//    cout << "\n";
//    myScreen.display(cout);
//    cout << "\n";


    //E7.11
//    Sales_data s1("haha");
//    Sales_data s2("good", 12, 2.5);
};
int chapter08() {
    //E8.13
    string line, word;
    vector<PersonInfo> persons;
    vector<string> lines;
    ifstream input("/Users/carl/Desktop/Temp/ForCpp/PersonInfo.txt");
    ofstream os("/Users/carl/Desktop/Temp/ForCpp/ResultForPhoneNumbers.txt");
    if (input) {
        istringstream record;
        while (getline(input, line)) {
            PersonInfo info;
            lines.push_back(line);
            record.clear();     //主要考察clear的使用
            record.str(line);
            record >> info.name;
            while (record >> word) {
                info.phones.push_back(word);
            }
            persons.push_back(info);
        }
    }
    input.close();
    for (const auto &person: persons) {
        cout << person.name << " ";
        for (const auto phone: person.phones) {
            cout << phone << " ";
        }
        cout << endl;
    }
    for (const auto &entry: persons) {
        ostringstream formatted, badNums;
        for (const auto &nums: entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty()) {
            os << entry.name << " " << formatted.str() << endl;
        } else {
            os << "input error: " << entry.name
                << " invalid number(s) " << badNums.str() << endl;
        }
    }
    os.close();



    //E8.11
//    string line, word;
//    vector<PersonInfo> persons;
//    vector<string> lines;
//    ifstream input("/Users/carl/Desktop/Temp/ForCpp/PersonInfo.txt");
//    if (input) {
//        istringstream record;
//        while (getline(input, line)) {
//            PersonInfo info;
//            lines.push_back(line);
//            record.clear();     //主要考察clear的使用
//            record.str(line);
//            record >> info.name;
//            while (record >> word) {
//                info.phones.push_back(word);
//            }
//            persons.push_back(info);
//        }
//    }
//    input.close();
//    for (const auto &person: persons) {
//        cout << person.name << " ";
//        for (const auto phone: person.phones) {
//            cout << phone << " ";
//        }
//        cout << endl;
//    }


    //E8.10
//    ifstream input("/Users/carl/Desktop/Temp/ForCpp/aTextForCpp.txt");
//    if (input) {
//        vector<string> vs;
//        string line, word;
//        while (getline(input, line)) {
//            vs.push_back(line);
//        }
//        for (const auto &l: vs) {
//            istringstream is(l);
//            while (is >> word) {
//                cout << word << endl;
//            }
//        }
//    }


    //E8.9
//    istringstream is("Hello my wife");
//    E8_01(is);


    //E8.5
//    ifstream input("/Users/carl/Desktop/Temp/ForCpp/aTextForCpp.txt");
//    vector<string> vs;
//    string word;
//    if (input) {
//        while (input >> word) {
//            vs.push_back(word);
//        }
//    }
//    int count = 0;
//    for (const auto l: vs) {
//        cout << l << endl;
//        cout << ++count << endl;
//    }


    //E8.4
//    ifstream input("/Users/carl/Desktop/Temp/ForCpp/aTextForCpp.txt");
//    vector<string> vs;
//    string line;
//    if (input) {
//        while (getline(input, line)) {
//            vs.push_back(line);
//        }
//    }
//    for (const auto l: vs) {
//        cout << l << "------" << endl;
//    }


    //E8.1
//    istream &is = E8_01(cin);
//    cout << is.rdstate() << endl;
}
int chapter09() {
    //E9.52
    auto& expr = "This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";
    auto repl = '#';
    auto seen = 0;

    stack<char> stk;

    for (auto c: expr) {

        stk.push(c);

        if (c == '(') ++seen;

        if (seen && c == ')') {
            while (stk.top() != '(') stk.pop();
            stk.pop();
            stk.push(repl);
            --seen;
        }
    }

    string output;
    for (;!stk.empty(); stk.pop()) {
        output.insert(output.begin(), stk.top());
    }
    cout << output << endl;

    //E9.51
//    MyDate date = MyDate();
//    date.Print();
//    cout << endl;
//    MyDate date1 = MyDate("January 1,1900");
//    date1.Print();
//    cout << endl;
//    MyDate date2 = MyDate("Feb 5 2009");
//    date2.Print();
//    cout << endl;


    //E9.50
//    vector<string> vs{"12.47", "15.88", "8.19"};
//    int sum = 0;
//    for (auto &s: vs) {
//        sum += stoi(s);
//    }
//    cout << "sum is " << sum << endl;
//    double sum2 = 0;
//    for (auto &s: vs) {
//        sum2 += stod(s);
//    }
//    cout << "sum of double is " << sum2 << endl;

    //E9.49
//    const string nocender("acemnorsuvwxz");
//
//    ifstream input("/Users/carl/Desktop/Temp/ForCpp/aTextForCpp.txt");
//    string word;
//    string::size_type length = 0;
//    string maxWord;
//    if (input) {
//        while (input >> word) {
//            if (word.find_first_not_of(nocender) == string::npos) {
//                cout << word << endl;
//                if (word.size() > length) {
//                    length = word.size();
//                    maxWord = word;
//                }
//            }
//        }
//    }
//    if (!maxWord.empty()) {
//        cout << "The longest word that requested is " << maxWord << endl;
//    } else {
//        cout << "All words has ascender or descender letter or there's no word in the file." << endl;
//    }
//    input.close();

    //E9.47
//    string s("ab2c3d7R4E6");
////    findString09_47(s);
//    findString09_48(s);

    //E9.45
//    string name = "Elizabeth";
////    name = formatName(name, "Ms.", "III");
//    name = formatName2(name, "Ms.", "III");
//    cout << name << endl;


    //E9.44
//    string str{"To drive straight thru is a foolish, tho courageous act."};
//    replaceString09_44(str, "thru", "through");
//    replaceString09_44(str, "tho", "though");
//    cout << str << endl;


    //E9.43
//    string str{"To drive straight thru is a foolish, tho courageous act."};
//    replaceString09_43(str, "thru", "through");
//    replaceString09_43(str, "tho", "though");
//    cout << str << endl;


    //E9.41
//    vector<char> vc{'H', 'e', 'l', 'l', 'o'};
//    string s(vc.begin(), vc.end());
//    cout << s << endl;


    //E9.39
//    ofstream writeFile("/Users/carl/Desktop/Temp/ForCpp/C09_39.txt");
//    if (writeFile) {
//        int row = 20;
//        int column = 50;
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < column; ++j) {
//                writeFile << "abc" << " ";
//            }
//            writeFile << endl;
//        }
//    }
//    writeFile.close();
//    vector<string> svec;
//    svec.reserve(1024);
//    string word;
//    ifstream input("/Users/carl/Desktop/Temp/ForCpp/C09_39.txt");
//    if (input) {
//        while (input >> word)
//            svec.push_back(word);
//    }
//    svec.resize(svec.size() + svec.size() / 2);
//    cout << "svec capacity: " << svec.capacity() << endl;
//    input.close();


    //E9.38
//    vector<string> vs;
//    string word;
//    while (cin >> word) {
//        vs.push_back(word);
//        cout << "size of vector: " << vs.size()
//            << ", and capacity of vector: " << vs.capacity() << endl;
//    }


    //E9.31
//    list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    auto iter = vi.begin();
//    while (iter != vi.end()) {
//        if (*iter % 2) {
//            iter = vi.insert(iter, *iter);
//            advance(iter, 2);
////            iter += 2;
//        }
//        else
//            iter = vi.erase(iter);
//    }
//
//    for (auto i : vi) cout << i << " ";


    //E9.28
//    forward_list<string> fls{"hello", "my", "a", "good ", "food", "my", "od", "jason", "baby", "fuck"};
//    insertString09_28(fls, "my", "your");
//    for (const auto &s: fls) {
//        cout << s << " ";
//    }
//    cout << endl;
//    insertString09_28(fls, "donald", "endofworld");
//    for (const auto &s: fls) {
//        cout << s << " ";
//    }


    //E9.27
//    forward_list<int> fli {1, 2, 3, 4, 5, 6, 7, 8};
//    auto prev = fli.before_begin();
//    auto curr = fli.begin();
//    while (curr != fli.end()) {
//        if (*curr & 0x1) {
//            curr = fli.erase_after(prev);
//        } else {
//            prev = curr;
//            ++curr;
//        }
//    }
//    for (const auto i: fli) {
//        cout << i << " " ;
//    }


    //E9.26
//    int ia[] = {0, 1, 1, 2, 3, 4, 5, 8, 13, 21, 55, 89};
//    vector<int> vi(begin(ia), end(ia));
//    list<int> li(begin(ia), end(ia));
//    auto viB = vi.begin();
//    while (viB != vi.end()) {
//        if (*viB % 2 == 0) {
//            viB = vi.erase(viB);
//        } else {
//            ++viB;
//        }
//    }
//    auto liB = li.begin();
//    while (liB != li.end()) {
//        if (*liB % 2 != 0) {
//            liB = li.erase(liB);
//        } else
//            ++liB;
//    }
//    for (const auto i: vi) {
//        cout << i << " ";
//    }
//    cout << endl;
//    for (const auto i: li) {
//        cout << i << " ";
//    }


    //E9.22
//    vector<int> vi{1, 1, 1, 3, 4, 1, 5, 8, 12, 3, 1, 9};
//    auto cursor = vi.size() / 2;
//    auto it = vi.begin(), mid = vi.begin() + cursor;
//    while (it != mid) {
//        if (*it == 1) {
//            it = vi.insert(it, 1 * 2);
//            ++it;
//            ++cursor;
//            mid = vi.begin() + cursor;
//        }
//        ++it;
//    }
//    for (const auto i: vi) {
//        cout << i << " ";
//    }


    //E9.20
//    list<int> li{1, 2, 3, 4, 5, 6, 7, 8};
//    deque<int> odd;
//    deque<int> even;
//    for (auto it = li.cbegin(); it != li.cend(); ++it) {
//        if ((*it) % 2 == 0) {
//            even.push_back(*it);
//        } else {
//            odd.push_back(*it);
//        }
//    }
//    for (const auto i: odd) {
//        cout << i << " " ;
//    }
//    cout << endl;
//    for (const auto i: even) {
//        cout << i << " " ;
//    }

    //E9.18
//    string word;
//    list<string> ds;
//    while (cin >> word) {
//        ds.push_back(word);
//    }
//    for (auto it = ds.begin(); it != ds.end(); ++it) {
//        cout << *it << " ";
//    }


    //E9,16
//    vector<int> vi{12, 4, 5, 6, 8};
//    list<int> li{12, 4, 5, 6, 8};
//    vector<int> temp(li.begin(), li.end());
//    if (vi == temp) {
//        cout << "vi == li" << endl;
//    } else {
//        cout << "vi != li" << endl;
//    }
//    cout << boolalpha << (vi == temp) << endl;


    //E9.15
//    vector<int> vi1{12, 4, 5, 6, 8};
//    vector<int> vi2{12, 4, 5, 6, 8};
//    if (vi1 == vi2) {
//        cout << "vi1 == vi2" << endl;
//    } else {
//        cout << "vi1 != vi2" << endl;
//    }


    //E9.14
//    list<const char *> lc {"hello", "my", "baby"};
////    vector<string> vs(lc.cbegin(), lc.cend());
//    vector<string> vs;
//    vs.assign(lc.cbegin(), lc.cend());
//    for (const auto &w: vs) {
//        cout << w << " " ;
//    }



    //E9.13
//    list<int> li = {3, 5, 7, 9, 11};
//    vector<double> vd1(li.begin(), li.end());
//    for(const auto e: vd1) {
//        cout << e << " ";
//    }
//    cout << endl;
//    vector<int> vi = {12, 4, 5, 8, 3, 9};
//    vector<double> vd2(vi.begin(), vi.end());
//    for(const auto e: vd2) {
//        cout << e << " ";
//    }


    //E9.11
//    vector<int> vi1(10);
//    printVector09("vi1", vi1);
//    vector<int> vi2(10, 5);
//    printVector09("vi2", vi2);
//    vector<int> vi3{1, 3, 5, 7, 9};
//    printVector09("vi3", vi3);
//    vector<int> vi4(vi3);
//    printVector09("vi4", vi4);
//    vector<int> vi5 = vi4;
//    printVector09("vi5", vi5);
//    vector<int> vi6 = {1, 2, 4, 8, 10};
//    printVector09("vi6", vi6);
//    vector<int> vi7(vi6.begin(), vi6.end());
//    printVector09("vi7", vi7);


    //E9.4
//    vector<int> vi = {12, 5, 8, 33, 19, 60};
//    if (findInt(vi.begin(), vi.end(), 60))
//        cout << "Element found." << endl;
//    else
//        cout << "Not Found!!!" << endl;


    //E9.2
//    list<deque<int>> lqint;
}

int main()
{
    cout << "ForExercises--\n";
    chapter09();

//    chapter08();

//    chapter07();

//    chapter06();

//    chapter05();

//    chapter04();

//    chapter03();

    /*chapter02();*/
    return 0;
}



