//
// Created by carl on 2020/9/15.
//

#ifndef FOREXERCISES_QUOTE_H
#define FOREXERCISES_QUOTE_H

#include <string>
#include <iostream>

class Quote {
public:
    Quote() {
        std::cout << "Quote()" << std::endl;
    };
    Quote(const std::string &bookStr, double sales_price) : bookNo(bookStr), price(sales_price) {
        std::cout << "Quote Constructor taking two parameters" << std::endl;
    }
    Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) {
        std::cout << "Quote Copy Constructor" << std::endl;
    }
    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(q.price) {
        std::cout << "Quote Move Constructor" << std::endl;
    }
    Quote &operator=(const Quote &quote) {
        std::cout << "Quote copy assignment Constructor" << std::endl;
        bookNo = quote.bookNo;
        price = quote.price;
        return *this;
    }
    Quote &operator=(Quote &&quote) {
        std::cout << "Quote move assignment Constructor" << std::endl;
        bookNo = std::move(quote.bookNo);
        price = std::move(quote.price);
        return *this;
    }

    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && {return new Quote(std::move(*this)); }

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t soldCnt) const { return soldCnt * price; }
    virtual void debug();
    virtual ~Quote() {
        std::cout << "Quote Deconstructor" << std::endl;
    };

protected:
    std::string bookNo;
    double price = 0.0;
};



#endif //FOREXERCISES_QUOTE_H
