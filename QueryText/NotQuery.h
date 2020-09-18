//
// Created by carl on 2020/9/17.
//

#ifndef QUERYTEXT_NOTQUERY_H
#define QUERYTEXT_NOTQUERY_H


#include "Query_base.h"
#include "Query.h"

class NotQuery : public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q) { };

    std::string rep() const override { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery &) const override;

    Query query;

};

inline
Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

#endif //QUERYTEXT_NOTQUERY_H
