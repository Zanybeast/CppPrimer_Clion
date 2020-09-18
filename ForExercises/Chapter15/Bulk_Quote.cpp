//
// Created by carl on 2020/9/15.
//

#include "Bulk_Quote.h"

Bulk_Quote::Bulk_Quote(const std::string &bookStr, double price, std::size_t mq, double disc)
    : Disc_Quote(bookStr, price, mq, disc), min_qyt(mq) { };

double Bulk_Quote::net_price(std::size_t soldCnt) const {
    if (soldCnt > min_qyt)
        return soldCnt * (1 - discount) * price;
    else
        return soldCnt * price;
}
