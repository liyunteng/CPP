/*
 * vegnews.cpp -- veg news
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 11:54:48
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
#include "stringbad.hpp"

using std::cout;

void callme1(StringBad & rsb)
{
    cout << "String passed by referrence:\n";
    cout << "      \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << "      \"" << sb << "\"\n";
}

int main(void)
{
    using std::endl;
    {
	cout << "Strating an inner block.\n";
	StringBad headline1("Celery Stalks at Midnight");
	StringBad headline2("Lettuce Prey");
	StringBad sports("Spinach Leaves Bow1 for Dollars");

	cout << "headline1: " << headline1 << endl;
	cout << "headline2: " << headline2 << endl;
	cout << "sports: " << sports << endl;

	callme1(headline1);
	cout << "headline1: " << headline1 << endl;
	callme2(headline2);
	cout << "headline2: " << headline2 << endl;
	cout << "Initialize on object to another:\n";
	StringBad sailor = sports;
	cout << "sailor: " << sailor << endl;
	cout << "Assign one object to another: \n";
	StringBad knot;
	knot = headline1;
	cout << "knot: " << knot << endl;
	cout << "Exiting the blocks.\n";
    }
    cout << "End of main()\n";

    return 0;
}
