//
// Created by carl on 2020/9/11.
//

#ifndef FOREXERCISES_QUERYRESULT_H
#define FOREXERCISES_QUERYRESULT_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <set>

typedef std::vector<std::string> vecType;
typedef std::set<unsigned> setType;

class QueryResult {
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<setType> p, std::shared_ptr<vecType> f) :
        sought(s), lineNums(p), lines(f) {};

    setType::iterator begin() const { return lineNums->begin(); }
    setType::iterator end() const { return lineNums->end(); }
private:
    std::string sought;
    std::shared_ptr<setType> lineNums;
    std::shared_ptr<vecType> lines;
};


#endif //FOREXERCISES_QUERYRESULT_H
