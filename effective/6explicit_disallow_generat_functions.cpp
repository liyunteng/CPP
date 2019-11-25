/*
 * explicit_disallow_generat_functions.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/12/29 22:45:56
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

class HomeForSale
{
public:
    HomeForSale() {}
    virtual ~HomeForSale() {}

private:
    HomeForSale(const HomeForSale &);
    HomeForSale &operator=(const HomeForSale &);
};

class Uncopyable
{
public:
    Uncopyable() {}
    ~Uncopyable() {}

private:
    Uncopyable(const Uncopyable &);
    Uncopyable &operator=(const Uncopyable &);
};

class Test : public Uncopyable
{
public:
    Test() {}
    virtual ~Test() {}
};

int
main(void)
{
    HomeForSale h1;
    // HomeForSale h2(h1);         // disable copy ct
    // h2 = h1;                    // disable copy assignment

    Test t1;
    // Test t2(t1);
    // t2 = t1;
    return 0;
}
