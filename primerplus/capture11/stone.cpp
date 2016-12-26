/*
 * stone.cpp -- ston
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 11:33:47
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
#include "stonwt.hpp"
using std::cout;
void display(const StonWt & st, int n)
{
    for (int i = 0; i < n; i++) {
	cout << "Wow! ";
	st.showStn();
    }
}

int main(void)
{

    StonWt incognito = 275;
    StonWt wolfe(285.7);
    StonWt taft(21, 8);

    cout << "The celebrity weighed ";
    incognito.showStn();
    cout << "The detective weighed ";
    wolfe.showStn();
    taft.showLbs();
    incognito = 276.8;
    taft = 325;
    cout << "After dinner, the celebrity weighed ";
    incognito.showStn();
    cout << "After dinner, the President weighed ";
    taft.showLbs();
    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    display(422, 2);
    cout << "No stone left unearned\n";
    return 0;
}
