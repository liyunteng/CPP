/*
 * stringbad.cpp -- string bad
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 12:40:42
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

#include "stringbad.hpp"
#include <cstring>

using std::cout;

int StringBad::num_strings = 0;

StringBad::StringBad(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << " : \"" << str << "\" object created\n";
}

StringBad::StringBad(StringBad &s)
{
    len = std::strlen(s.str);
    str = new char[len + 1];
    std::strcpy(str, s.str);
    num_strings++;
    cout << num_strings << " :\"" << str << "\" copyed\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << " : \"" << str << "\" default object created\n";
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete[] str;
}

StringBad &
StringBad::operator=(const StringBad &rhs)
{
    // Check for self-assignment!
    if (this == &rhs)
        return *this;
    delete str;
    len = std::strlen(rhs.str);
    str = new char[len + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

std::ostream &
operator<<(std::ostream &os, const StringBad &c)
{
    os << c.str;
    return os;
}
