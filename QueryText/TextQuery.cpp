//
// Created by carl on 2020/9/16.
//

#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <sstream>
#include <iterator>

TextQuery::TextQuery(std::ifstream &input)
    : file(StrBlob()), wordsMap(std::map<std::string, std::shared_ptr<std::set<line_no>>>()) {
    std::string line;

    while (getline(input, line)) {
        file.push_back(line);
        int lineNum = file.size() - 1;

        std::stringstream lineStream(line);
        std::string word;
        while (lineStream >> word) {
            std::shared_ptr<std::set<line_no>> &strPtr_lines = wordsMap[word];

            if (!strPtr_lines) {
                strPtr_lines.reset(new std::set<line_no>);
            }
            strPtr_lines->insert(lineNum);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> noData(new std::set<line_no>);

    //! fetch the iterator to the matching element in the map<word, lines>.
    //std::map<std::string, std::shared_ptr<std::set<index_Tp>>>::const_iterator
    auto iter = wordsMap.find(sought);
    if(iter == wordsMap.end())
        return QueryResult(sought, noData, file);
    else
        return QueryResult(sought, iter->second, file);
}