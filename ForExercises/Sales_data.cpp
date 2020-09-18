//
// Created by carl on 2020/9/14.
//

#include "Sales_data.h"

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

Sales_data & Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream& operator>>(istream &input, Sales_data &s) {
    double price = 0.0;
    input >> s.bookNo >> s.units_sold >> price;
    if (input)
        s.revenue = price * s.units_sold;
    else
        s = Sales_data();

    return input;
}

ostream& operator<<(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();

    return os;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data & Sales_data::operator=(const string &isbn) {
    *this = Sales_data(isbn);
    return *this;
}