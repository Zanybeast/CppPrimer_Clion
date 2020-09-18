//
// Created by carl on 2020/9/17.
//

#ifndef QUERYTEXT_QUERY_H
#define QUERYTEXT_QUERY_H

#include <iostream>
#include <string>
#include <memory>
#include "Query_base.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "WordQuery.h"

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    Query(const std::string &s);
    QueryResult eval(const TextQuery&t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query): q(query) { }
    std::shared_ptr<Query_base> q;
};


#endif //QUERYTEXT_QUERY_H
