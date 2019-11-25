/*
 * file_test.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/19 00:02:19
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

#include <fstream>
#include <iostream>
using namespace std;

int
main(void)
{
    ifstream f1;
    ofstream f2;

    char filename1[256];
    char filename2[256];
    char content[256];

    cout << "请输入文件名(源): ";
    cin >> filename1;
    cout << "请输入文件名(目的): ";
    cin >> filename2;

    cout << "outfile: " << filename2 << endl;
    f1.open(filename1, ios_base::in);
    f2.open(filename2, ios_base::out);
    while (!f1.eof()) {
        f1.getline(content, 128);
        f2 << content << endl;
    }
    f1.close();
    f2.close();
    return 0;
}
