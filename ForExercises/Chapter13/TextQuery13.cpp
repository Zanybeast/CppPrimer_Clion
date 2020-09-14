//
// Created by carl on 2020/9/11.
//

#include <sstream>
#include "TextQuery13.h"
#include "StrVec.h"

TextQuery13::TextQuery13(std::ifstream &input) : lines(new StrVec) {
    std::string line;

    while (std::getline(input, line)) {
        lines->push_back(line);
        size_t lineNum = lines->size() - 1;
        std::istringstream stream(line);
        std::string eachWordInLine;
        while (stream >> eachWordInLine) {
            auto &lineNumsSet = wordsMap[eachWordInLine];
            if (!lineNumsSet) {
                lineNumsSet.reset(new std::set<size_t>);
            }
            lineNumsSet->insert(lineNum);
        }
    }
}

QueryResult13 TextQuery13::query (const std::string &sought) const {
    static std::shared_ptr<std::set<size_t>> nodata(new std::set<size_t>);
    auto pos = wordsMap.find(sought);
    if (pos == wordsMap.end()) {
        return QueryResult13(sought, nodata, lines);
    } else {
        return QueryResult13(sought, pos->second, lines);
    }
}