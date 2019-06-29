// 1-4-3.cpp - 1-4-3

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/06/25

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#include <iostream>

int main(void)
{
    int sum = 0, value = 0;

    while (std::cin >> value)
        sum += value;

    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}
