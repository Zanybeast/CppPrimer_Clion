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

class TextQuery {
public:
    TextQuery(std::ifstream &input);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<vecType> lines;
    std::map<std::string, std::shared_ptr<setType>> wordsMap;
};


#endif //FOREXERCISES_TEXTQUERY_H
