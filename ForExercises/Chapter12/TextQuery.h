//
// Created by carl on 2020/9/11.
//

#ifndef FOREXERCISES_TEXTQUERY_H
#define FOREXERCISES_TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>

#include "QueryResult.h"

class QueryResult;

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) { }
    template <typename T> void operator()(T *p) const {
        std::cout << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

class TextQuery {
public:
    TextQuery(std::ifstream &input);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<vecType> lines;
    std::map<std::string, std::shared_ptr<setType>> wordsMap;
};


#endif //FOREXERCISES_TEXTQUERY_H
