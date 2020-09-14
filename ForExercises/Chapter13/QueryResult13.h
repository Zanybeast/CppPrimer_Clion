//
// Created by carl on 2020/9/11.
//

#ifndef FOREXERCISES_QUERYRESULT13_H
#define FOREXERCISES_QUERYRESULT13_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <set>

class StrVec;

class QueryResult13 {
    friend std::ostream& print(std::ostream &, const QueryResult13&);
public:
    QueryResult13(std::string s, std::shared_ptr<std::set<size_t>> p, std::shared_ptr<StrVec> f) :
        sought(s), lineNums(p), lines(f) {};

//    std::shared_ptr<std::set<size_t>>::iterator begin() const { return lineNums->begin(); }
//    std::shared_ptr<std::set<size_t>>::iterator end() const { return lineNums->end(); }
private:
    std::string sought;
    std::shared_ptr<std::set<size_t>> lineNums;
    std::shared_ptr<StrVec> lines;
};


#endif //FOREXERCISES_QUERYRESULT13_H
