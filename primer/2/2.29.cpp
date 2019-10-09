// 2.29.cpp - 2.29

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/09/04

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#include <cstdio>
#include <iostream>
#include <string>

const int g = 3;
void test1()
{
    int i = 0;
    int *p = &i;
    *p = g;
    // p = &g; error!!!
    p = const_cast<int *>(&g);
}


void test2()
{
    std::string input;
    while (std::getline(std::cin, input)) {
        std::cout << input << std::endl;
    }
}
int main(void)
{
    test1();
    test2();
    return 0;
}
