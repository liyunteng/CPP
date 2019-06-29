// Sales_data.hpp - Sales_data

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/06/26

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif
