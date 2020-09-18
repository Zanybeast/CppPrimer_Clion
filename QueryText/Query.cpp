//
// Created by carl on 2020/9/17.
//

#include "Query.h"
#include "WordQuery.h"

inline
Query::Query(const std::string &s) : q(new WordQuery(s)) {
    std::cout << "Query::Query(const std::string& s) where s="+s+"\n";
}

std::ostream & operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}