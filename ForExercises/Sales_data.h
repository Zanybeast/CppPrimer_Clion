//
// Created by carl on 2020/9/4.
//

#ifndef FOREXERCISES_SALES_DATA_H
#define FOREXERCISES_SALES_DATA_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string testForStatic = "This is a lie!!!!!!!";

class Sales_data;
//与类有关的函数接口的声明，尚未实现
Sales_data add (const Sales_data& lhs, const Sales_data& rhs);
ifstream &read(ifstream &is, Sales_data& item);
ostream &print(ostream &os, const Sales_data& item);


class Sales_data
{
    //友元函数
    friend Sales_data add (const Sales_data& lhs, const Sales_data& rhs);
    friend ifstream &read(ifstream &is, Sales_data& item);
    friend ostream &print(ostream &os, const Sales_data& item);
    //公有成员
public:
    //构造函数
    Sales_data(const string &s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p * n) { cout << "委托构造函数" << endl; }
    Sales_data() : Sales_data("", 0, 0){ cout << "默认构造函数" << endl;}
    Sales_data(const string s):Sales_data(s, 0, 0) { cout << "Sales_data(const string s)" << endl; }
    Sales_data(ifstream &is) : Sales_data() { cout << "Sales_data(ifstream &is)" << endl; read(is, *this); }
//    Sales_data() : units_sold(0), revenue(0.0) { }    //某道练习题
    //成员函数
    string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data&);
    //私有成员
private:
    double avg_price() const;
    //数据成员
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

//外部定义成员函数
inline
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
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
};
ifstream &read(ifstream &is, Sales_data& item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
};

#endif //FOREXERCISES_SALES_DATA_H
