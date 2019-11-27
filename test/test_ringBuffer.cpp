/*
 * testRingBuffer.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/19 15:16:29
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

#include "ringBuffer.hpp"
#include <iostream>
int
main(void)
{
    ringBuffer<int> rb(10);

    for (size_t i = 0; i < rb.size(); i++) {
        std::cout << "push " << i << std::endl;
        rb.push(i);
    }
    // rb.push(-1);
    for (size_t i = 0; i < rb.size(); i++) {
        std::cout << rb.pop() << std::endl;
    }
    std::cout << "size: " << rb.size() << std::endl;

    return 0;
}
