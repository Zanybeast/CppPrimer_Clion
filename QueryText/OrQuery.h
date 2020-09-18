//
// Created by carl on 2020/9/17.
//

#ifndef QUERYTEXT_ORQUERY_H
#define QUERYTEXT_ORQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right ,"|") {};
    QueryResult eval(const TextQuery& t) const override;
};

inline
Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif //QUERYTEXT_ORQUERY_H
