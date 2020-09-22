//
// Created by carl on 2020/9/11.
//

#include <sstream>
#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream &input) : lines(new vecType) {
    std::string line;

    while (std::getline(input, line)) {
        lines->push_back(line);
        unsigned lineNum = lines->size() - 1;
        std::istringstream stream(line);
        std::string eachWordInLine;
        while (stream >> eachWordInLine) {
            auto &lineNumsSet = wordsMap[eachWordInLine];
            if (!lineNumsSet) {
                lineNumsSet.reset(new std::set<unsigned>, DebugDelete());
            }
            lineNumsSet->insert(lineNum);
        }
    }
}

QueryResult TextQuery::query (const std::string &sought) const {
    static std::shared_ptr<setType> nodata(new setType);
    auto pos = wordsMap.find(sought);
    if (pos == wordsMap.end()) {
        return QueryResult(sought, nodata, lines);
    } else {
        return QueryResult(sought, pos->second, lines);
    }
}