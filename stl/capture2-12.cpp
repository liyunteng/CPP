/*
 * capture2-12.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/19 10:42:43
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

#include <cstdlib>
#include <fstream>
#include <iostream>

int
main(void)
{
    int   i = 30;
    float f = 12.34;
    char  c;

    std::fstream fl("sf", std::ios::out | std::ios::in);
    if (!fl) {
        std::cerr << "The File Open Error." << std::endl;
        std::exit(255);
    }
    fl << "I=" << i << " ; F=" << f << std::endl;
    fl.seekp(std::ios::beg);
    fl >> c >> c;
    fl >> ++i;
    std::cout << i << std::endl;

    return 0;
}
