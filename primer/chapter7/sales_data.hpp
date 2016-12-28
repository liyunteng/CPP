// sales_data.hpp --

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/27 15:47:27

// This program is free software; you can redistribute it and/or modify
// it under the terms and conditions of the GNU General Public License
// version 2,as published by the Free Software Foundation.

// This program is distributed in the hope it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.

// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation,
// Inc.,51 Franklin St - Fifth Floor, Boston,MA 02110-1301 USA.

#ifndef SALES_DATA_HPP_
#define SALES_DATA_HPP_
#include <iostream>
#include <string>

class Sales_data
{
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(std::istream&);
    virtual ~Sales_data();

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);

    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
private:
    double avg_pirce() const
        { return units_sold ? revenue/units_sold : 0; }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

class Screen {
public:
    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(ht * wd, c) { }
    ~Screen() {}

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}
#endif
