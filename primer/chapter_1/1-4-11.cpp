// 1-4-11.cpp - 1-4-11

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/09/04

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#include <iostream>

int
main(void)
{
    int small = 0, big = 0;
    std::cout << "please input two interfers: ";
    std::cin >> small >> big;

    if (small > big) {
        int tmp = small;
        small   = std::move(big);
        big     = tmp;
    }

    for (int i = small; i <= big; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
