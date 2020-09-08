//
// Created by carl on 2020/9/1.
//

#ifndef BASIC_SALES_DATA_H
#define BASIC_SALES_DATA_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Sales_data;
//与类有关的函数接口的声明，尚未实现
Sales_data add (const Sales_data& lhs, const Sales_data& rhs);
ifstream &read(ifstream &is, Sales_data& item);
ostream &print(ostream &os, const Sales_data& item);
ofstream &print(ofstream &os, const Sales_data& item);


struct Sales_data
{
    //构造函数
    Sales_data() = default;
    Sales_data(const string &s):bookNo(s) { cout << "Using Sales_data(const string &s):bookNo(s)" << endl;}
    Sales_data(const string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p * n) {
        cout << "using Sales_data(const string &s, unsigned n, double p):\n"
                "        bookNo(s), units_sold(n), revenue(p * n)"
                << endl;
    }
    Sales_data(ifstream &is) {
        cout << "using Sales_data(ifstream &is)" << endl;
        read(is, *this);
    }
    //成员函数
    string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data&);
    double avg_price() const;
    //数据成员
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

//外部定义成员函数
double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

//与类有关的函数接口
Sales_data add (const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
};
ostream &print(ostream &os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
};
ofstream &print(ofstream &os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price() << endl;
    return os;
};

ifstream &read(ifstream &is, Sales_data& item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
};

#endif //BASIC_SALES_DATA_H
