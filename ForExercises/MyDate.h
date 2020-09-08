//
// Created by carl on 2020/9/8.
//

#ifndef FOREXERCISES_MYDATE_H
#define FOREXERCISES_MYDATE_H

#include <string>
#include <array>
#include <iostream>

using namespace std;

class MyDate {
public:
    explicit MyDate(const string &str = "");
    void Print();
    unsigned year = 1970;
    unsigned month = 1;
    unsigned day = 1;
private:
    array<string, 12> month_names{"Jan", "Feb", "Mar",
                                  "Apr", "May", "Jun",
                                  "Jul", "Aug", "Sep",
                                  "Oct", "Nov", "Dec"};
    unsigned MonthFromName(const string &str);
};

void MyDate::Print() {
    cout << year << "-" << month << "-" << day;
}

MyDate::MyDate(const string &str) {
    if (str.empty()) return ;
    string delimiters(" ,/");
    auto month_day_delim_pos = str.find_first_of(delimiters);
    if (month_day_delim_pos == string::npos)
        throw invalid_argument("This format is not supportted yet.");
    month = MonthFromName(str.substr(0, month_day_delim_pos));
    auto day_year_delim_pos = str.find_first_of(delimiters, month_day_delim_pos + 1);
    auto day_length = day_year_delim_pos - month_day_delim_pos - 1;
    day = stoi(str.substr(month_day_delim_pos + 1, day_length));
    year = stoi(str.substr(day_year_delim_pos + 1));
}

unsigned MyDate::MonthFromName(const string &str) {
    if (str.empty()) return 0;
    if (isdigit(str[0])) return stoi(str);      //If month is digital, return it directly.
    for (size_t i = 0; i != 12; ++i) {
        if (str.find(month_names[i]) != string::npos) return i + 1;
    }

    return 0;
}

#endif //FOREXERCISES_MYDATE_H
