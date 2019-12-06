/*
 * stringbad.hpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 13:31:36
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

#ifndef STRINGBAD_HPP_
#define STRINGBAD_HPP_
#include <iostream>

class StringBad
{
public:
    StringBad();
    StringBad(const char *s);
    StringBad(StringBad &);
    virtual ~StringBad();

    // friend
    friend std::ostream &operator<<(std::ostream &, const StringBad &);
    StringBad &operator=(const StringBad &);

private:
    char *str;
    int len;
    static int num_strings;
};

#endif
