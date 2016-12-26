/*
 * mytime1.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/15 00:27:40
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

#include "mytime1.hpp"
#include <iostream>

Time::Time()
{
    m_hours = m_minutes = 0;
}

Time::Time(int h, int m):
m_hours(h), m_minutes(m)
{

}

Time::~Time()
{

}

void Time::AddMin(int m)
{
    m_minutes += m;
    m_hours += m_minutes / 60;
    m_minutes = m_minutes % 60;
}

void Time::AddHour(int h)
{
    m_hours += h;
}

void Time::Reset(int h, int m)
{
    m_hours = h;
    m_minutes = m;
}

Time Time::operator+(const Time & t) const const
{
    Time sum;
    sum.m_minutes = m_minutes + t.m_minutes;
    sum.m_hours = m_hours + t.m_hours + sum.m_minutes / 60;
    sum.m_minutes = sum.m_minutes % 60;
    return sum;
}

void Time::Show() const const
{
    std::cout << m_hours << " hours, " << m_minutes << " minutes.";
}
