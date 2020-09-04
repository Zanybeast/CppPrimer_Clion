// ForExercises.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"
#include "Window_mgr.h"

#define NDEBUG

using namespace std;

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
bool isPrefixVector(vector<int>, vector<int>);
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

int chapter02();
int chapter03();
int chapter04();
int chapter05();
int chapter06();
int chapter07() {
    //E7.27
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";


    //E7.11
//    Sales_data s1("haha");
//    Sales_data s2("good", 12, 2.5);
};

int main()
{
    cout << "ForExercises--\n";
    chapter07();

//    chapter06();

//    chapter05();

//    chapter04();

//    chapter03();

    /*chapter02();*/
    return 0;
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