/*
 * stonwt.hpp -- ston wt
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 11:26:43
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

#ifndef STONWT_HPP_
#define STONWT_HPP_

class StonWt {
  public:
    StonWt();
    StonWt(int stn, double lbs = 0);
    StonWt(double lbs);
    ~StonWt();

  public:
    void showLbs() const;
    void showStn() const;

  private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;
};


#endif
