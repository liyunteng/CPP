// sales_data.cpp - sales_data

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/06/27

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.

#include "sales_data.hpp"
using namespace lyt;

// compile failed without lyt::
std::istream &
lyt::read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &
lyt::print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data
add(const Sales_data &lhs, Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data &
Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int
main(void)
{
    Sales_data s;
    print(std::cout, s);
    return 0;
}
