/*
 * bank.cpp -- bank
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 17:50:56
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
#include "queue.hpp"

const int MIN_PER_HR = 60;

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));

    std::cout << "Case Study: Bank of Heather Automatic Teller\n";
    std::cout << "Enter maximu size of queue: ";

    int qs;
    cin >> qs;
    Queue line(qs);

    std::cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    std::cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++) {
	if (newcustomer(min_per_cust)) {
	    if (line.isfull())
		turnaways++;
	    else {
		customers++;
		temp.set(cycle);
		line.enqueue(temp);
	    }
	}
	if (wait_time <= 0 && !line.isempty()) {
	    line.dequeue(temp);
	    wait_time = temp.ptime();
	    line_wait += cycle - temp.when();
	    served++;
	}

	if (wait_time > 0)
	    wait_time--;
	sum_line += line.queuecount();
    }

    if (customers > 0) {
	cout << "customers accepted: " << customers << endl;
	cout << "  customers served: " << served << endl;
	cout << "         turnaways: " << turnaways << endl;
	cout << "average queue size: ";
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << (double) sum_line / cyclelimit << endl;
	cout << " average wait time: "
	    << (double) line_wait / served << " minutes\n";
    } else
	cout << "No customers!\n";

    cout << "Done!\n";

    return 0;
}
