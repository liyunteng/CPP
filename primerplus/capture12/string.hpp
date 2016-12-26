/*
 * string.hpp -- string
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 13:53:43
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

#ifndef STRING_HPP_
#define STRING_HPP_
#include <iostream>

using std::ostream;
using std::istream;

class String {
  public:
    // constructors
    String();
    String(const char *s);
    String(const String & s);
    virtual ~ String();

  public:
    int length() const {
	return len;
    } String & operator=(const String &);
    String & operator=(const char *);
    char &operator[] (int i);
    const char &operator[] (int i) const;

    friend bool operator<(const String & s1, const String & s2);
    friend bool operator>(const String & s1, const String & s2);
    friend bool operator==(const String & s1, const String & s2);
    friend ostream & operator<<(ostream & os, const String & s);
    friend istream & operator>>(istream & is, String & s);

    static int HowMany();
  private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
};



#endif
