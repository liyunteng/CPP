/*
 * mytime2.hpp -- my time 2
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 00:04:33
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

#ifndef MYTIME2_HPP
#define MYTIME2_HPP
#include <iostream>

class Time
{
public:
    Time();
    Time(int h, int m = 0);
    // virtual ~Time();
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time &t) const;
    Time operator-(const Time &t) const;
    Time operator*(double n) const;
    friend Time operator*(double n, const Time &t);
    friend std::ostream &operator<<(std::ostream &, const Time &t);

private:
    int m_hours;
    int m_minutes;
};

#endif
