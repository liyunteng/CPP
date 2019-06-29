// 1-4-4.cpp - 1-4-4

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/06/25

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#include <iostream>

int main(void)
{
    int currVal = 0, val = 0;

    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
                  << cnt << " times" << std::endl;
    }
    return 0;
}
