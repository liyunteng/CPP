 // choices.cpp --

 // Copyright (C) 2016 liyunteng
 // Auther: liyunteng <li_yunteng@163.com>
 // License: GPL
 // Update time:  2016/11/14 08:50:22

 // This program is free software; you can redistribute it and/or modify it
 // under the terms and conditions of the GNU General Public License,
 // version 2, as published by the Free Software Foundation.

 // This program is distributed in the hope it will be useful, but WITHOUT
 // ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 // FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 // more details.

 // You should have received a copy of the GNU General Public License along with
 // this program; if not, write to the Free Software Foundation, Inc.,
 // 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.

#include <iostream>
#include <vector>
#include <array>

int main(int argc, char *argv[])
{
    using namespace std;

    double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
    vector < double >a2(4);
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;

    array < double, 4 > a3 = { 3.14, 2.72, 1.62, 1.41 };
    array < double, 4 > a4;
    a4 = a3;


    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;


    a1[-2] = 20.2;

    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a2[-2]: " << a2[-2] << " at " << &a2[-2] << endl;
    cout << "a3[-2]: " << a3[-2] << " at " << &a3[-2] << endl;
    cout << "a4[-2]: " << a4[-2] << " at " << &a4[-2] << endl;

    cout << "a2.at(-2): " << a2.at(-2) << " at " << &a2.at(-2) << endl;
    return 0;
}
