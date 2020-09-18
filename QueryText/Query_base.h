//
// Created by carl on 2020/9/17.
//

#ifndef QUERYTEXT_QUERY_BASE_H
#define QUERYTEXT_QUERY_BASE_H

#include "TextQuery.h"
#include "QueryResult.h"

class Query_base {
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};


#endif //QUERYTEXT_QUERY_BASE_H
