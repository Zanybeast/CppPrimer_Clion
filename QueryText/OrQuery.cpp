//
// Created by carl on 2020/9/17.
//

#include "OrQuery.h"

QueryResult OrQuery::eval(const TextQuery &t) const {
    auto right = rhs.eval(t), left = lhs.eval(t);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

inline
Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}