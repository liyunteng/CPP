/*
 * override.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/20 16:49:51
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
#include <string>

using std::cout;
using std::endl;

class Base
{
public:
    Base() {}
    virtual ~Base() {}

    virtual void mf1()
    {
        cout << "base mf1" << endl;
    }
    void mf1(int i)
    {
        cout << "base mf1(int): " << i << endl;
    }
    virtual void mf2()
    {
        cout << "base mf2" << endl;
    }
    void mf2(int i)
    {
        cout << "base mf2(int): " << i << endl;
    }
};

class Derived : public Base
{
public:
    Derived() {}
    virtual ~Derived() {}
    using Base::mf1;
    using Base::mf2;
    virtual void mf1()
    {
        cout << "derived mf1" << endl;
    }
    // void mf1(int i) { cout << "derived mf1(int): " << i << endl;}
    virtual void mf2()
    {
        cout << "derived mf2" << endl;
    }
};

int
main(void)
{
    Derived d;
    d.mf1();
    d.mf1(1);
    d.mf2();
    d.mf2(1);
    return 0;
}
