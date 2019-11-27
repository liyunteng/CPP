/*
 * sqrt.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/13 18:52:35
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

#include <cmath>
#include <iostream>

int
main(int argc, char *argv[])
{

    using namespace std;

    double area;
    cout << "Enter the floor area, in square feet, of your home: ";
    cin >> area;
    double side;
    side = sqrt(area);

    cout << "That's the equivalent of a square " << side << " feet to the side."
         << endl;
    cout << "How fascinating!" << endl;
    return 0;
}
