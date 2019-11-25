// test.cpp - test

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/09/14

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.

#include <iostream>
#include <string>
using namespace std;

const string str = "(1 + 2) * 3 + 4";

#define _SYMBOL(s) #s
#define SYMBOL(s) _SYMBOL(s)

int
main(void)
{
    cout << SYMBOL(str);
    return 0;
}
