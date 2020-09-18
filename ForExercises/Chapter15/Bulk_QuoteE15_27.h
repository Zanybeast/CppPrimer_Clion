//
// Created by carl on 2020/9/15.
//

#ifndef FOREXERCISES_BULK_QUOTEE15_27_H
#define FOREXERCISES_BULK_QUOTEE15_27_H

#include "Disc_Quote.h"

class Bulk_QuoteE15_27 : public Disc_Quote {
public:
    using Disc_Quote::Disc_Quote;
    virtual double net_price(std::size_t soldCnt) const override {
        if (soldCnt > quantity)
            return soldCnt * (1 - discount) * price;
        else
            return soldCnt * price;
    }
};


#endif //FOREXERCISES_BULK_QUOTEE15_27_H
