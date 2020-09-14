//
// Created by carl on 2020/9/11.
//

#include "QueryResult13.h"
#include "StrVec.h"

std::ostream &print(std::ostream& os, const const QueryResult13 &qr) {
    os << qr.sought << " occurs " << qr.lineNums->size() << " "
        << "time(s)" << std::endl;
    for (auto num : *qr.lineNums) {
        os << "\t(line " << num + 1 << ") "
            << qr.lines->at(num) << std::endl;
    }
    return os;
}