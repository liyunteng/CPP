/*
 * makesure_init.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/20 02:01:01
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
#include <list>
#include <iostream>

class ABEntry			// ABEntry = "Address Book Entry"
{
  public:
    ABEntry(const std::string & name, const std::string & address,
	    const std::list < std::string > &phones);
    virtual ~ ABEntry() {
  } private:
     std::string theName;
    std::string theAddress;
    std::list < std::string > thePhones;
    int numTimesConsulted;
};

ABEntry::ABEntry(const std::string & name, const std::string & address,
		 const std::list < std::string > &phones)
:theName(name),			// initialize
theAddress(address), thePhones(phones), numTimesConsulted(0)
{
    // theName = name;             // use assignments not initailize
    // theAddress = address;
    // thePhones = phones;
    // numTimesConsulted = 0;
}

class Singalton {
  public:
    static Singalton & getInstance();
     virtual ~ Singalton() {
    } int data() const {
	return m_data;
  } private:
     Singalton(int data):m_data(data) {
    }
    static Singalton instance;
    int m_data;
};

Singalton Singalton::instance = Singalton(1);
Singalton & Singalton::getInstance()
{
    return instance;
}

int main(void)
{
    std::cout << Singalton::getInstance().data() << std::endl;
    return 0;
}
