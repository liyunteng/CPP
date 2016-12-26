/*
 * replace_define.cpp -- 使用const或者enums代替#define
 *                       使用inline函数代替macros
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/20 01:06:28
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include <iostream>

// #define Max(a, b) ((a) > (b) ? (a) : (b))
template < typename T > inline T Max(const T & a, const T & b)
{
    return a > b ? a : b;
}

// #define FudgeFactor  1.35
// #define NumTurn 5
class CostEstimate {
  public:
    CostEstimate();
    virtual ~ CostEstimate();
  public:
    static const double FudgeFactor;
    enum { NumTurns = 5 };
};

const double CostEstimate::FudgeFactor = 1.35;
int main(void)
{
    std::cout << CostEstimate::FudgeFactor << std::endl;
    std::cout << CostEstimate::NumTurns << std::endl;
    std::cout << Max(10, 11) << std::endl;
    return 0;
}
