/*
 * stonwt.cpp -- ston wt
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 11:29:11
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

#include "stonwt.hpp"
#include <iostream>

void
StonWt::showStn() const const
{
    std::cout << pounds << " pounds\n";
}

void
StonWt::showLbs() const const
{
    std::cout << stone << " stone, " << pds_left << " pounds." << std::endl;
}

StonWt::StonWt()
{
    stone = pounds = pds_left = 0;
}

StonWt::StonWt(int stn, double lbs)
{
    stone    = stn;
    pds_left = lbs;
    pounds   = stn * Lbs_per_stn + pds_left;
}

StonWt::StonWt(double lbs)
{
    stone    = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn;
    pounds   = lbs;
}

StonWt::~StonWt() {}
