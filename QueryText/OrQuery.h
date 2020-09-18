//
// Created by carl on 2020/9/17.
//

#ifndef QUERYTEXT_ORQUERY_H
#define QUERYTEXT_ORQUERY_H


#include "Query.h"
#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right ,"|") {};
    QueryResult eval(const TextQuery& t) const;
};


#endif //QUERYTEXT_ORQUERY_H
