/*
 * capture2-16.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/19 11:55:56
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

#include <string>
#include <iostream>
using namespace std;

int main(void)
{

    string Mystring1(10, ' ');
    string Mystring2 = " This is the example string!";
    string Mystring3(Mystring2);
    cout << "string1 is: " << Mystring1 << endl;
    cout << "string2 is: " << Mystring2 << endl;
    cout << "string3 is: " << Mystring3 << endl;
    Mystring3 = Mystring1;
    cout << "string3 is: " << Mystring3 << endl;
    return 0;
}
