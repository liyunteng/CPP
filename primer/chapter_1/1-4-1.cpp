// 1-4-1.cpp - 1-4-1

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/06/25

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#include <iostream>

int
main(void)
{
    int sum = 0, val = 1;

    while (val <= 10) {
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}
