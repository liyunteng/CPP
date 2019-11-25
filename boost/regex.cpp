/*
 * regex.cpp -- regex using boost
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/18 23:35:25
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
#include "regex.hpp"
#include <boost/regex.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
using namespace boost;

regex expression("^select([a-zA-z ]*)from([a-zA-Z ]*)");

int
main(void)
{
    std::string in;
    cmatch      what;

    cout << "Enter testing string: " << endl;
    getline(cin, in);

    if (regex_match(in.c_str(), what, expression)) {
        for (size_t i = 0; i < what.size(); i++) {
            cout << "str: " << what[i] << endl;
        }
    } else {
        cout << "not found" << endl;
    }

    return 0;
}
