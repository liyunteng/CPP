/*
 * mytime2.cpp -- my time2
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 00:04:39
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

#include "mytime2.hpp"

Time::Time()
{
    m_hours = m_minutes = 0;
}

Time::Time(int h, int m)
{
    m_hours = h;
    m_minutes = m;
}

void Time::AddMin(int m)
{
    m_minutes += m;
    m_hours += m_minutes / 60;
    m_minutes = m_minutes % 60;
}

void Time::AddHr(int h)
{
    m_hours += h;
}

void Time::Reset(int h, int m)
{
    m_minutes = m;
    m_hours = h;
}

Time Time::operator+(const Time & t) const const
{
    Time sum;
    sum.m_minutes = m_minutes + t.m_minutes;
    sum.m_hours = m_hours + t.m_hours + sum.m_minutes / 60;
    sum.m_minutes = m_minutes % 60;
    return sum;
}

Time Time::operator-(const Time & t) const const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.m_minutes + 60 * t.m_hours;
    tot2 = m_minutes + 60 * m_hours;
    diff.m_minutes = (tot2 - tot1) % 60;
    diff.m_hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double n) const const
{
    Time result;
    long total = (m_hours * 60 + m_minutes) * n;
    result.m_minutes = total % 60;
    result.m_hours = total / 60;
    return result;
}

Time operator*(double n, const Time & t)
{
    Time result;
    long total = (t.m_hours * 60 + t.m_minutes) * n;
    result.m_minutes = total % 60;
    result.m_hours = total / 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.m_hours << " hours, " << t.
	m_minutes << " minutes." << std::endl;
    return os;
}
