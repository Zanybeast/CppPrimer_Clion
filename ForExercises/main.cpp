// ForExercises.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

int chapter02();
int chapter03();

int main()
{
    cout << "ForExercises--\n";
    chapter03();

    /*chapter02();*/
    return 0;
}

int chapter03() {

    //E3.7
    string s;
    cout << "Enter a word: " << endl;
    cin >> s;
    for (char c : s) {
        c = 'X';
    }
    cout << s << endl;

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
    /*int i = 0;
    double* dp = &i;
    int* ip = i;
    int* p = &i;
    前面两个非法，第一个指针类型和指针所指向类型要匹配；第二个不能把变量直接赋值给指针*/


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