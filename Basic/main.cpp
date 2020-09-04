// MainProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

#include "Sales_data.h"

using namespace std;

int test();

int main()
{
    cout << "Main Project--\n";

    ifstream input;
    input.open("/Users/carl/Desktop/Temp/ForCpp/SalesRecord.txt");

    Sales_data total;
    double price = 0.0;

    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
        print(cout, total);
    } else {
        cerr << "No data?!" << endl;
        input.close();
        return -1;
    }

    input.close();

    return 0;

}

int test() {
    ifstream input;
    input.open("/Users/carl/Desktop/Temp/ForCpp/SalesRecord.txt");

    Sales_data total(input);
    double price = 0.0;

    if (!total.isbn().empty())
    {
        while (input)
        {
            Sales_data trans(input);
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
        print(cout, total);
    } else {
        cerr << "No data?!" << endl;
        input.close();
        return -1;
    }

    input.close();

    return 0;
}




//    Sales_data data1;
//    double price = 0.0;
//
//    if (input >> data1.bookNo >> data1.units_sold >> price)
//    {
//        Sales_data data2;
//        unsigned totalCnt = data1.units_sold;
//        while (input >> data2.bookNo >> data2.units_sold >> price)
//        {
//            if (data1.bookNo == data2.bookNo) {
//                totalCnt += data2.units_sold;
//            }
//            else {
//                cout << data1.bookNo << " total sold: " << totalCnt << endl;
//                totalCnt = data2.units_sold;
//            }
//
//            data1 = data2;
//
//        }
//        /*cout << data1.bookNo << " " << data1.units_sold << " " << price << endl;*/
//        cout << data1.bookNo << " total sold: " << totalCnt << endl;
//    }



/*double price = 0;
cin >> data1.bookNo >> data1.units_sold >> price;
data1.revenue = data1.units_sold * price;

cin >> data2.bookNo >> data2.units_sold >> price;
data2.revenue = data2.units_sold * price;

if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;
    cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
    if (totalCnt != 0)
    {
        cout << totalRevenue / totalCnt << endl;
    }
    else {
        cout << "(no slaes)" << endl;
    }
}
else {
    cerr << "Data must refer to the same ISBN" << endl;
    return -1;
}

if (data1.bookNo == data2.bookNo) {

}
else {
    cerr << "Data must refer to the same ISBN" << endl;
    return -1;
}*/


