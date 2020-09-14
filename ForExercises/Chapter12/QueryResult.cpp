//
// Created by carl on 2020/9/11.
//

#include "QueryResult.h"

std::ostream &print(std::ostream& os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lineNums->size() << " "
        << "time(s)" << std::endl;
    for (auto num : *qr.lineNums) {
        os << "\t(line " << num + 1 << ") "
            << *(qr.lines->begin() + num) << std::endl;
    }
    return os;
}