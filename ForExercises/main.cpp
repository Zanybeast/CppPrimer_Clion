// ForExercises.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chapter02();
int chapter03();
int chapter04();
int chapter05();

int main()
{
    cout << "ForExercises--\n";
    chapter05();

//    chapter04();

//    chapter03();

    /*chapter02();*/
    return 0;
}

int chapter05() {
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