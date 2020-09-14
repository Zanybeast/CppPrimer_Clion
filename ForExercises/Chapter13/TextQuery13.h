//
// Created by carl on 2020/9/11.
//

#ifndef FOREXERCISES_TEXTQUERY13_H
#define FOREXERCISES_TEXTQUERY13_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>

#include "QueryResult13.h"

class QueryResult13;
class StrVec;

class TextQuery13 {
public:
    TextQuery13(std::ifstream &input);
    QueryResult13 query(const std::string &) const;
private:
    std::shared_ptr<StrVec> lines;
    std::map<std::string, std::shared_ptr<std::set<size_t>>> wordsMap;
};


#endif //FOREXERCISES_TEXTQUERY13_H
