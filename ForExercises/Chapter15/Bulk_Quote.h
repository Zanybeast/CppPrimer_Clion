//
// Created by carl on 2020/9/15.
//

#ifndef FOREXERCISES_BULK_QUOTE_H
#define FOREXERCISES_BULK_QUOTE_H

#include "Quote.h"
#include "Disc_Quote.h"

class Bulk_Quote : public Disc_Quote {
public:
    Bulk_Quote() = default;
    Bulk_Quote(const std::string &bookStr, double price, std::size_t mq, double disc);

    Bulk_Quote * clone() const & { return new Bulk_Quote(*this); }
    Bulk_Quote * clone() && { return new Bulk_Quote(std::move(*this)); }

    virtual double net_price(std::size_t soldCnt) const override;
    void debug() override {
        Quote::debug();
        std::cout << "\tminimum quantity: " << quantity << "\tdiscount: " << discount << std::endl;
    }

protected:
    std::size_t min_qyt = 0;
};


#endif //FOREXERCISES_BULK_QUOTE_H
