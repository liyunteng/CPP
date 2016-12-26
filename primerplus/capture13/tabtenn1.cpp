/*
 * tabtenn1.cpp -- tabtenn
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/17 02:39:49
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

#include "tabtenn1.hpp"
#include <iostream>

TabelTennisPlayer::TabelTennisPlayer(const string & fn, const string & ln, bool ht):firstName(fn), lastName(ln),
hasTabel
(ht)
{

}

void TabelTennisPlayer::Name() const const
{
    std::cout << lastName << " ," << firstName << "\n";
}


RetedPlayer::RetedPlayer(unsigned int r, const string & fn,
			 const string & ln, bool ht):TabelTennisPlayer(fn,
								       ln,
								       ht),
rating(r)
{

}

RetedPlayer::RetedPlayer(unsigned int r,
			 const TabelTennisPlayer & t):TabelTennisPlayer(t),
rating(r)
{

}
