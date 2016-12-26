/*
 * string.cpp -- string
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 13:45:39
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

#include "string.hpp"
#include <cstring>
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & s)
{
    num_strings++;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
}

String::~String()
{
    --num_strings;
    delete[]str;
}

String & String::operator=(const String & s)
{
    if (this == &s)
	return *this;

    delete[]str;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    return *this;
}

String & String::operator=(const char *s)
{
    delete[]str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char &String::operator[] (int i) {
    return str[i];
}

const char &String::operator[] (int i)
const {
    return str[i];
} bool operator<(const String & s1, const String & s2)
{
    return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String & s1, const String & s2)
{
    return s2 < s1;
}

bool operator==(const String & s1, const String & s2)
{
    return (std::strcmp(s1.str, s2.str) == 0);
}

ostream & operator<<(ostream & os, const String & s)
{
    os << s.str;
    return os;
}

istream & operator>>(istream & is, String & s)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
	s = temp;
    while (is && is.get() != '\n')
	continue;
    return is;
}
