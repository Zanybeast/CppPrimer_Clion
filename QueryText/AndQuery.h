//
// Created by carl on 2020/9/17.
//

#ifndef QUERYTEXT_ANDQUERY_H
#define QUERYTEXT_ANDQUERY_H

#include "BinaryQuery.h"

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &, const Query &) ;
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") { }

    QueryResult eval(const TextQuery &t) const override;
};

inline
Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}


#endif //QUERYTEXT_ANDQUERY_H
