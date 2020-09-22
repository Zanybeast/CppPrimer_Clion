
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
#include <tuple>
#include <bitset>
#include <random>
#include <ctime>

using namespace std;

class A {

};

class B: public A {

};

class C: public B {

};

class D: public B, public A {

};

void exercises() {
    //E19.3
    /*A *pa = new C;
    B *pb = dynamic_cast<B *>(pa);*/

    //E17.9
    /*bitset<64> bitvec(32);
    bitset<32> bv(1010101);
    cout << bitvec << endl;
    cout << bv << endl;
    string bstr;
    cin >> bstr;
    bitset<8> bv2(bstr);
    cout << bv2 << endl;*/
}

void testAndVerify() {
    //P736
    int arr[10];
    cout << typeid(42).name() << " "
        << typeid(arr).name() << endl;

    //P665
    /*default_random_engine e;
    normal_distribution<> n(5, 1.5);
    vector<unsigned> vals(9);
    for(size_t i = 0; i != 200; ++i) {
        unsigned v = lround(n(e));
        if (v < vals.size())
            ++vals[v];
    }
    for (int i = 0; i < vals.size(); ++i) {
        cout << i << ": " << string(vals[i], '*') << endl;
    }*/


    //P660
    /*default_random_engine e(time(0));
    for (int i = 0; i < 10; ++i) {
        cout << e() << " ";
    }
    cout << endl;
    cout << time(0) << endl;*/

    /*uniform_int_distribution<unsigned> u(0, 9);
    vector<int> vi(10, 0);
    default_random_engine e1;
    long long int count = 100000000;
    for (int i = 0; i < count; ++i) {
        ++vi[u(e1)];
    }
    for (auto &e: vi) {
        double percent = static_cast<double>(e) / count;
        cout << percent << "____";
    }*/

    /*default_random_engine e;
    cout << "min: " << e.min() << " max: " << e.max() << endl;*/

    //P643
    /*bitset<32> b(8);
    cout << b << endl;
    cout << boolalpha << b.all() << endl;*/

    //P642
    /*string s("hello");
    cout << s[0] << endl;
    string sn("11000110101001110");
    bitset<32> bitvec(sn, 6, 4);
    bitset<32> bitvec2(sn, sn.size() - 4);
    cout << bitvec << endl;
    cout << bitvec2 << endl;*/

    //P639
    /*tuple<int, int, int> threeInt(10, 20, 30);
    cout << get<0>(threeInt) << endl;
    cout << get<1>(threeInt) << endl;
    cout << get<2>(threeInt) << endl;
    typedef decltype(threeInt) thIType;
    cout << "size of threeInt: " << tuple_size<thIType>::value;*/
}

int main() {
    exercises();
    testAndVerify();

    return 0;
}
