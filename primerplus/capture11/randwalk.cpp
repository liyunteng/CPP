/*
 * randwalk.cpp -- rand walk using VECTOR
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 10:04:09
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
#include <cstdlib>
#include <ctime>
#include "vector.hpp"

int main(void)
{
    using namespace std;
    using VECTOR::Vector;

    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    std::cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
	std::cout << "Enter step length: ";
	if (!(cin >> dstep))
	    break;

	while (result.magVal() < target) {
	    direction = rand() % 360;
	    step.reset(dstep, direction, Vector::POL);
	    result = result + step;
	    steps++;
	}
	std::cout << "After " << steps << " steps, the subject "
	    "has the following location:\n";
	cout << result << endl;

	result.polarMode();
	cout << " or\n" << result << endl;
	cout << "Average outward distance per step = "
	    << result.magVal() / steps << endl;
	steps = 0;
	result.reset(0.0, 0.0);
	cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    cin.clear();

    while (cin.get() != '\n')
	continue;

    return 0;
}
