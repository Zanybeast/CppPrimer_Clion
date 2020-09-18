//
// Created by carl on 2020/9/16.
//

#ifndef QUERYTEXT_TEXTQUERY_H
#define QUERYTEXT_TEXTQUERY_H

#include "StrBlob.h"
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>

class QueryResult;



class TextQuery {
public:
    typedef StrBlob::size_type line_no;

    TextQuery(std::ifstream & input);
    QueryResult query(const std::string &word) const;
private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wordsMap;
};


#endif //QUERYTEXT_TEXTQUERY_H
