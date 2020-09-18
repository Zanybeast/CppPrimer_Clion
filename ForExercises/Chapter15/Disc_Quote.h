//
// Created by carl on 2020/9/15.
//

#ifndef FOREXERCISES_DISC_QUOTE_H
#define FOREXERCISES_DISC_QUOTE_H

#include "Quote.h"

class Disc_Quote : public Quote {
public:
    Disc_Quote() = default;
    Disc_Quote(const std::string &bookNo, double price, std::size_t qty, double disc)
        : Quote(bookNo, price), quantity(qty), discount(disc) { };
    double net_price(std::size_t soldCnt) const = 0;

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};


#endif //FOREXERCISES_DISC_QUOTE_H
