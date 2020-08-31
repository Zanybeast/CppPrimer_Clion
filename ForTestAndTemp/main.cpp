// ForTestAndTemp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15 seperated by spaces. Hit enter when finished: " << endl;
    string result;
    string::size_type n;
    while (cin >> n)
    {
        if (n < hexdigits.size())
        {
            result += hexdigits[n];
        }
    }

    cout << "Your hex number is: " << result << endl;



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

