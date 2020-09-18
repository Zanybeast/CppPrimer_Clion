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
    friend istream &operator>>(istream &, Sales_data &);
    friend ostream &operator<<(ostream &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    //公有成员
public:
    //构造函数
    Sales_data(const string &s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p * n) { cout << "委托构造函数" << endl; }
    Sales_data() : Sales_data("", 0, 0){ cout << "默认构造函数" << endl;}
    Sales_data(const string s):Sales_data(s, 0, 0) { cout << "Sales_data(const string s)" << endl; }
    Sales_data(ifstream &is) : Sales_data() { cout << "Sales_data(ifstream &is)" << endl; read(is, *this); }

    explicit operator string() const { return bookNo; }
    explicit operator double() const { return avg_price(); }
//    Sales_data() : units_sold(0), revenue(0.0) { }    //某道练习题
    //Operand members
    Sales_data& operator+=(const Sales_data& rhs);
    Sales_data& operator=(const string &s);
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



#endif //FOREXERCISES_SALES_DATA_H
