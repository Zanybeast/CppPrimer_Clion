//
// Created by carl on 2020/9/17.
//

#ifndef QUERYTEXT_WORDQUERY_H
#define QUERYTEXT_WORDQUERY_H

#include "Query_base.h"


class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const std::string &s): query_word(s) { };
    QueryResult eval(const TextQuery &t) const override { return t.query(query_word); }
    std::string rep() const override { return query_word; }

    std::string query_word;
};


#endif //QUERYTEXT_WORDQUERY_H
