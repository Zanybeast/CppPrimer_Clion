//
// Created by carl on 2020/9/17.
//

#include "Query.h"
//there's a "inline" here so the program can not run, after deleted, run successful.
//"inline" function could only be seen on the file, so there should not be an "inline" here or it would cover
//the original function
Query::Query(const std::string &s) : q(new WordQuery(s)) {

}

inline std::ostream & operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}