// sales_data.hpp - sales_data

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/06/27

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP
#include <iostream>
#include <string>

namespace lyt {
    class Sales_data {
    public:
        Sales_data(const std::string &s, unsigned n, double p) :    // inline
            bookNo(s), units_sold(n), revenue(p * n) {}
        Sales_data(): Sales_data("", 0, 0) {}                    // dalegating constructor
        Sales_data(const std::string &s) : Sales_data(s, 0, 0) {}             // inline
        explicit Sales_data(std::istream&is): Sales_data() { read(is, *this);}

        std::string isbn() const { return bookNo; }                 // inline const this
        Sales_data &combine(const Sales_data&);
    private:
        double avg_price() const                                    // inline const this
            { return units_sold ? revenue / units_sold : 0; }
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

        friend std::istream &read(std::istream &, Sales_data &);              // friend
        friend std::ostream &print(std::ostream &, const Sales_data&);        // friend
        friend Sales_data add(const Sales_data&, const Sales_data&);          // friend
    };
    std::istream &read(std::istream &is,Sales_data &item);
    std::ostream &print(std::ostream &os, const Sales_data &item);
    Sales_data add(const lyt::Sales_data&lhs, const Sales_data&);
}

#endif
