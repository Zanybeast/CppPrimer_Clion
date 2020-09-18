//
// Created by carl on 2020/9/15.
//

#ifndef FOREXERCISES_LIMIT_QUOTE_H
#define FOREXERCISES_LIMIT_QUOTE_H

#include "Bulk_Quote.h"

class Limit_Quote : public Bulk_Quote {
public:
    Limit_Quote() = default;
    Limit_Quote(std::string &bookStr, double price, std::size_t minCnt, std::size_t maxCnt, double dis);
    double net_price(std::size_t n) const override;
    void debug() override {
        Bulk_Quote::debug();
        std::cout << "maximum quantity: " << max_qty << std::endl;
    }
private:
    std::size_t max_qty;
};


#endif //FOREXERCISES_LIMIT_QUOTE_H
