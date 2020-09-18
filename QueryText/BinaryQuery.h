//
// Created by carl on 2020/9/17.
//

#ifndef QUERYTEXT_BINARYQUERY_H
#define QUERYTEXT_BINARYQUERY_H


#include "Query_base.h"
#include "Query.h"

class BinaryQuery : public Query_base {

protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) { }
    std::string rep() const override { return "(" + lhs.rep() + " " + opSym + rhs.rep() + ")"; }
    Query lhs, rhs;
    std::string opSym;
};


#endif //QUERYTEXT_BINARYQUERY_H
