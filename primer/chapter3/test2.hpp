/*
 * test2.hpp -- test virtual
 *
 * Copyright (C) 2015 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2015/06/11 19:32:19
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

#ifndef TEST2_HPP
#define TEST2_HPP

#include <iostream>

class Test {
  public:
    Test() {
    } virtual ~ Test() {
    }
    virtual void test() {
	std::cout << "Test" << std::endl;
    }
};

class Test1:public Test {
    public: Test1() {
    } ~Test1() {
    }
};
#endif
