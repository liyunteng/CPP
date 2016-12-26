/*
 * testTime2.cpp -- test time2
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 00:06:00
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

#include "mytime2.hpp"
#include <iostream>

int main(void)
{
    using std::cout;
    using std::endl;

    Time weeding(3, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjust;

    cout << "weeding time = " << weeding;
    cout << "waxing time = " << waxing;

    total = weeding + waxing;
    cout << "total work time = " << total;

    diff = weeding - waxing;
    cout << "weeding - waxing time = " << diff;

    // adjust = total * 1.5;       // operator*
    adjust = 1.5 * total;	// friend operator*
    cout << "adjuset work time = " << adjust;

    return 0;
}
