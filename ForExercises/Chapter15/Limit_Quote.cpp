//
// Created by carl on 2020/9/15.
//

#include "Limit_Quote.h"

Limit_Quote::Limit_Quote(std::string &bookStr, double price, std::size_t minCnt, std::size_t maxCnt, double dis)
    : Bulk_Quote(bookStr, price, minCnt, dis), max_qty(maxCnt) {};

double Limit_Quote::net_price(std::size_t soldCnt) const {
    if (soldCnt > max_qty)
        return max_qty * (1 - discount) * price + (soldCnt - max_qty) * price;
    else if (soldCnt >= min_qyt)
        return soldCnt * (1 - discount) * price;
    else
        return soldCnt * price;
}