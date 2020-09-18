//
// Created by carl on 2020/9/17.
//

#include "OrQuery.h"
#include <memory>

QueryResult OrQuery::eval(const TextQuery &t) const {
    auto right = rhs.eval(t), left = lhs.eval(t);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

