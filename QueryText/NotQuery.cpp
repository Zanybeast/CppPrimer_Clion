//
// Created by carl on 2020/9/17.
//

#include "NotQuery.h"
#include <memory>

QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto beg = result.begin(), end = result.end();
    size_t sz = result.get_file().size();
    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }

    return QueryResult(rep(), ret_lines, result.get_file());
}

