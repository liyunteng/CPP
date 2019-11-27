/*
 * correctly_interface.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/20 13:25:51
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

class Year
{
public:
    explicit Year(int y) : year(y) {}
    virtual ~Year() {}
    int get() const { return year; }

private:
    int year;
};

class Month
{
public:
    enum MOUNTHS {
        Jan   = 1,
        Feb   = 2,
        March = 3,
        Apr   = 4,
        May   = 5,
        June  = 6,
        July  = 7,
        Aug   = 8,
        Sep   = 9,
        Oct   = 10,
        Nov   = 11,
        Dec   = 12,
    };
    explicit Month(MOUNTHS m) : month(m) {}
    virtual ~Month() {}
    int get() const { return month; }

private:
    int month;
};

class Day
{
public:
    explicit Day(int d) : day(d) {}
    virtual ~Day() {}

    int get() const { return day; }

private:
    int day;
};

class Date
{
public:
    Date(const Month &m, const Day &d, const Year &y) :
        month(m),
        day(d),
        year(y)
    {
    }
    virtual ~Date() {}

    void show()
    {
        std::cout << year.get() << "/" << month.get() << "/" << day.get()
                  << std::endl;
    }

private:
    const Month &month;
    const Day &day;
    const Year &year;
};

int
main(void)
{
    Date d(Month(Month::Apr), Day(20), Year(1920));
    d.show();
    return 0;
}
