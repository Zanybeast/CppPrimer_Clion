// ForTestAndTemp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>

using namespace std;

size_t count_calls() {
    static size_t ctr = 0;
    ctr += 1;
    return ++ctr;
}
struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    //P360
//    vector<int> vi{1, 3, 5, 5, 12, 9, 44, 19, 23, 5, 988, 56, 56, 5, 44};
//    ostream_iterator<int> out_iter(cout, " ");
//    copy(vi.begin(), vi.end(), out_iter);


    //P359
//    vector<int> vi;
//    istream_iterator<int> in_iter(cin);
//    istream_iterator<int> eof;
//    while (in_iter != eof) {
//        vi.push_back(*in_iter++);
//    }
//    for (const auto i: vi) cout << i << " ";

    //P359
//    list<int> lst = {1, 2, 3, 4};
//    list<int> lst2, lst3;
//    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
//    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
//    for_each(lst2.begin(), lst2.end(), [](int i){cout << i << " ";});
//    cout << endl;
//    for_each(lst3.begin(), lst3.end(), [](int i){cout << i << " ";});


    //P336
//    int ia[] = {32, 210, 12, 34, 47, 109, 83};
//    int val = 109;
//    int *result = find(begin(ia), end(ia), val);
//    cout << *result << endl;


    //P328
//    int i = 42;
//    string s = to_string(i);
//    cout << s << endl;
//    double d = stod(s);
//    double d1 = 13.44;
//    string sd = to_string(d1);
//    cout << sd << endl;
//    cout << d << endl;
//    string s = "pi = 3.1415E7, haha";
//    double d = stod(s.substr(s.find_first_of("+-.0123456789")));
//    cout << d << endl;


    //P288
//    string line, word;
//    vector<PersonInfo> people;
//    ifstream input("/Users/carl/Desktop/Temp/ForCpp/PersonInfo.txt");
//    if (input) {
//        while (getline(input, line)) {
//            PersonInfo info;
//            istringstream record(line);
//            record >> info.name;
//            while (record >> word) {
//                info.phones.push_back(word);
//            }
//            people.push_back(info);
//        }
//        for (const auto &person: people) {
//            cout << person.name << " ";
//            for (const auto phone: person.phones) {
//                cout << phone << " ";
//            }
//            cout << endl;
//        }
//    }




//    cout << "Hello" << endl;
//    cout << "Hello" << flush << endl;
//    cout << "Hello" << ends << "Ha" << endl;


//    for (size_t i = 0; i != 10; ++i) {
//        cout << count_calls() << endl;
//    }


//    int i = 10, j = 101;
//    try {
//        if (i != j) {
//            throw runtime_error("Two numbers must be equal.");
//        } else {
//            cout << i * j << endl;
//        }
//    } catch (runtime_error error) {
//        cout << error.what() << endl;
//    }




//    ifstream input;
//    input.open("/Users/carl/Desktop/Temp/ForCpp/aTextForCpp.txt");
//
//    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
//    char ch;
//    while (input >> ch) {
//        switch (ch) {
//            case 'a':
//                ++aCnt;
//                break;
//            case 'e':
//                ++eCnt;
//                break;
//            case 'i':
//                ++iCnt;
//                break;
//            case 'o':
//                ++oCnt;
//                break;
//            case 'u':
//                ++uCnt;
//                break;
//
//        }
//    }
//    cout << "aCount = " << aCnt
//    << ", eCount = " << eCnt
//    << ", iCount = " << iCnt
//    << ", oCount = " << oCnt
//    << ", uCount = " << uCnt << endl;


//    int i = 4294967297;
//    unsigned ui = i;
//    cout << ui << endl;


//    int i = 0;
//    int *p = &i;
//    double d = 0.0;
//    double *pd = &d;
//    cout << "size of *p = " << sizeof(p) << endl;
//    cout << "size of i = " << sizeof(i) << endl;
//    cout << "size of double *p = " << sizeof(pd) << endl;
//    char *c;
//    cout << "size of char * = " << sizeof(c) << endl;
//    vector<int> vi = {2, 3, 4, 5, 10, 44, 123};
//    cout << "size of vector = " << sizeof(vi) << endl;


//    cout << 21 % 8 << endl;
//    cout << -21 % 8 << endl;
//    cout << 21 % -8 << endl;
//    cout << -21 % -8 << endl;

//    short v = 32767;
//    v += 1;
//    cout << v << endl;

//    int array[] = {1, 2, 3, 4, 5};
//    int (*Parray)[5] = &array;
//    int (&Refarray)[5] = array;
//    cout << *Parray[0] << endl;
//    cout << Refarray[1] << endl;
//    int a = 10;
//    int b = 20;
//    int *pa = &a, *pb = &b;
//    int *pArr[] = {pa, pb};
//    int *(*Pparray)[2] = &pArr;
//    cout << *((*Pparray)[1]) << endl;

//    const string hexdigits = "0123456789ABCDEF";
//    cout << "Enter a series of numbers between 0 and 15 seperated by spaces. Hit enter when finished: " << endl;
//    string result;
//    string::size_type n;
//    while (cin >> n)
//    {
//        if (n < hexdigits.size())
//        {
//            result += hexdigits[n];
//        }
//    }
//
//    cout << "Your hex number is: " << result << endl;



    /*string s("Hello World!!!It's me again!!!");
    decltype(s.size()) punct_cnt = 0;

    for (auto c : s) {
        if (ispunct(c))
            ++punct_cnt;
    }
    cout << punct_cnt << " punctuation characters in " << s << endl;

    for (auto& c : s) {
        c = toupper(c);
    }
    cout << s << endl;*/


    /*string line;
    while (getline(cin, line))
    {
        cout << line << endl;
    }*/



    /*string s;
    cin >> s;
    cout << s << endl;*/



    /*const int i = 42;
    auto j = i;
    const auto& k = i; auto* p = &i;
    const auto j2 = i, & k2 = i;
    cout << "k2 = " << k2 << endl;*/


    //int i = 0;
    //int* const p1 = &i;     //pi是顶层const
    //const int ci = 42;      //ci是顶层const
    //const int* p2 = &ci;    //可以改变p2的值, p2是底层const
    //cout << "*p2 = " << *p2 << endl;
    ///*const int ci2 = 55;
    //p2 = &ci2;
    //cout << "*p2 = " << *p2 << endl;*/
    //const int* const p3 = p2;
    //const int& r = ci;

    //int* p = p3;        //错误, 常量不可以转换为非常量
    //p2 = p3;            //p2有底层const属性, p3也有
    //p2 = &i;            //都是底层const
    //int& r = ci;        //ci是顶层const, 而引用是底层const
    //const int& r2 = i;  //都是底层const


    //int i = 42;
    //const int& r1 = i;
    //const int& r2 = 42;
    //const int& r3 = r1 * 2;
    ////int& r4 = r1 * 2;
    //cout << "&r1 = " << r1 << ", &r2 = " << r2 << ", &r3 = " << r3 << endl;
    //double dval = 42.323;
    //const int& ri = dval;
    //cout << "ri = " << ri << endl;


    /*int i = 40;
    int* p;
    int*& r = p;
    r = &i;
    cout << "i(r) = " << *r << ", i = " << i << endl;*/



    /*int ival = 1024;
    int* pi = 0;
    int* pi2 = &ival;
    if (pi)
    {
        cout << "Pi is true" << endl;
    }
    else
    {
        cout << "pi is false" << endl;
    }

    if (pi2)
    {
        cout << "pi2 is true" << endl;
    }
    else
    {
        cout << "pi2 is false" << endl;
    }*/

    /*int i = 42;
    int* pi;
    int* pi2 = &i;
    int* pi3;

    pi3 = pi2;
    *pi2 = 0;
    pi = pi2;
    cout << "*pi = " << *pi << ", *pi2 = " << *pi2 << ", *pi3 = " << *pi3;*/


    /*cout << "ForTestAndTemp--\n";

    int ival = 42;
    int* p = &ival;
    cout << *p << endl;
    *p = 0;
    cout << *p;*/

//    int* nPT = nullptr;

}

