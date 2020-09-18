cmake_minimum_required(VERSION 3.17)
project(ForExercises)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

add_executable(ForExercises main.cpp
        Sales_data.h
        Person.h
        Screen.h
        Window_mgr.h
        DEBUG.h MyDate.h
        StrBlob.h
        Chapter12/TextQuery.cpp Chapter12/TextQuery.h
        Chapter12/QueryResult.cpp Chapter12/QueryResult.h
        Employee.cpp Employee.h
        Chapter13/HasPtrLikeValue.cpp Chapter13/HasPtrLikeValue.h
        Chapter13/HasPtrLikeClass.cpp Chapter13/HasPtrLikeClass.h
        Chapter13/TreeNode.cpp Chapter13/TreeNode.h
        Chapter13/BinStrTree.cpp Chapter13/BinStrTree.h
        Chapter13/Message.cpp Chapter13/Message.h
        Chapter13/Folder.cpp Chapter13/Folder.h
        Chapter13/StrVec.cpp Chapter13/StrVec.h
        Chapter13/TextQuery13.cpp Chapter13/TextQuery13.h
        Chapter13/QueryResult13.cpp Chapter13/QueryResult13.h
        Chapter13/ZString.cpp Chapter13/ZString.h
        Chapter13/Foo.cpp Chapter13/Foo.h Sales_data.cpp StrBlob.cpp Chapter14/BoundStrCheck.cpp Chapter14/BoundStrCheck.h Chapter14/CompareTwoStrLength.cpp Chapter14/CompareTwoStrLength.h Chapter14/CompareStringLengthWithSize.cpp Chapter14/CompareStringLengthWithSize.h Chapter15/Quote.cpp Chapter15/Quote.h Chapter15/Bulk_Quote.cpp Chapter15/Bulk_Quote.h Chapter15/Limit_Quote.cpp Chapter15/Limit_Quote.h Chapter15/Disc_Quote.cpp Chapter15/Disc_Quote.h Chapter15/Bulk_QuoteE15_26.cpp Chapter15/Bulk_QuoteE15_26.h Chapter15/Bulk_QuoteE15_27.cpp Chapter15/Bulk_QuoteE15_27.h Chapter15/Section9/Basket.cpp Chapter15/Section9/Basket.h)