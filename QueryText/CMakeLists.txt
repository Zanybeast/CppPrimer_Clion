cmake_minimum_required(VERSION 3.17)
project(QueryText)

set(CMAKE_CXX_STANDARD 11)

add_executable(QueryText main.cpp TextQuery.cpp TextQuery.h QueryResult.cpp QueryResult.h StrBlob.cpp StrBlob.h Query_base.cpp Query_base.h Query.cpp Query.h WordQuery.cpp WordQuery.h NotQuery.cpp NotQuery.h BinaryQuery.cpp BinaryQuery.h AndQuery.cpp AndQuery.h OrQuery.cpp OrQuery.h)