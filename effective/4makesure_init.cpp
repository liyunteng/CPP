/*
 * makesure_init.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/12/29 21:48:16
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

// 1.自定义类确保手动初始化
// 2.使用初始化列表,初始化列表顺序应与变量声明顺序一致
// 3.non-local static 变量的初始化顺序不确定，可以变为local static变量

#include <iostream>
#include <list>
#include <string>

class ABEntry  // ABEntry = "Address Book Entry"
{
public:
    ABEntry(const std::string &name, const std::string &address,
            const std::list<std::string> &phones);
    virtual ~ABEntry() {}

private:
    std::string theName;
    std::string theAddress;
    std::list<std::string> thePhones;
    int numTimesConsulted;
};

ABEntry::ABEntry(const std::string &name, const std::string &address,
                 const std::list<std::string> &phones) :
    theName(name),  // initialize
    theAddress(address),
    thePhones(phones),
    numTimesConsulted(0)
{
    // theName = name;             // use assignments not initailize
    // theAddress = address;
    // thePhones = phones;
    // numTimesConsulted = 0;
}
