//
// Created by carl on 2020/9/15.
//

#ifndef FOREXERCISES_BULK_QUOTEE15_26_H
#define FOREXERCISES_BULK_QUOTEE15_26_H

#include "Quote.h"


class Bulk_QuoteE15_26 : public Quote {
public:
    Bulk_QuoteE15_26() {
        std::cout << "Bulk_QuoteE15_26()" << std::endl;
    }
    Bulk_QuoteE15_26(const std::string &bookNo, double p, std::size_t min, double disc) :
        Quote(bookNo, p), min_qty(min), discount(disc) {
        std::cout << "Bulk_QuoteE15_26(const std::string &bookNo, double p, std::size_t min, double disc)" << std::endl;
    }
    Bulk_QuoteE15_26(const Bulk_QuoteE15_26& b) :
        Quote(b), min_qty(b.min_qty), discount(b.discount) {
        std::cout << "Bulk_QuoteE15_26(const Bulk_QuoteE15_26& b)" << std::endl;
    }
    Bulk_QuoteE15_26(Bulk_QuoteE15_26 && b) noexcept :
        Quote(b), min_qty(std::move(b.min_qty)), discount(std::move(b.discount)) {
        std::cout << "Bulk_QuoteE15_26(Bulk_QuoteE15_26 && b) noexcept" << std::endl;
    }
    Bulk_QuoteE15_26 &operator=(const Bulk_QuoteE15_26 &b) {
        std::cout << "Bulk_QuoteE15_26 &operator=(const Bulk_QuoteE15_26 &b)" << std::endl;
        Quote::operator=(b);
        min_qty = b.min_qty;
        discount = b.discount;
        return *this;
    }
    Bulk_QuoteE15_26 &operator=(Bulk_QuoteE15_26 &&b) {
        std::cout << "Bulk_QuoteE15_26 &operator=(Bulk_QuoteE15_26 &&b)" << std::endl;
        Quote::operator=(b);
        min_qty = std::move(b.min_qty);
        discount = std::move(b.discount);
        return *this;
    }

    virtual ~Bulk_QuoteE15_26() {
        std::cout << "virtual ~Bulk_QuoteE15_26()" << std::endl;
    };
    virtual double net_price(std::size_t soldCnt) const override {
        if (soldCnt >= min_qty)
            return soldCnt * (1 - discount) * price;
        else
            return soldCnt * price;
    }

protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};


#endif //FOREXERCISES_BULK_QUOTEE15_26_H
