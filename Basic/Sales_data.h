//
// Created by carl on 2020/9/1.
//

#ifndef BASIC_SALES_DATA_H
#define BASIC_SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif //BASIC_SALES_DATA_H
