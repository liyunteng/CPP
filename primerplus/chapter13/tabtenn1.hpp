/*
 * tabtenn1.hpp -- tabtenn
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/17 02:34:53
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

#ifndef TABTENN1_HPP
#define TABTENN1_HPP

#include <string>
using std::string;

class TabelTennisPlayer
{
public:
    TabelTennisPlayer(const string &fn = "none", const string &ln = "none",
                      bool ht = false);
    virtual ~TabelTennisPlayer() {}

public:
    void Name() const;
    bool HasTabel() const { return hasTabel; }
    void ResetTabel(bool v) { hasTabel = v; }

private:
    string firstName;
    string lastName;
    bool hasTabel;
};

class RetedPlayer : public TabelTennisPlayer
{
public:
    RetedPlayer(unsigned int r = 0, const string &fn = "none",
                const string &ln = "none", bool ht = false);
    explicit RetedPlayer(unsigned int r, const TabelTennisPlayer &);
    virtual ~RetedPlayer() {}

public:
    unsigned int Rating() const { return rating; }
    void ResetRating(unsigned r) { rating = r; }

private:
    unsigned int rating;
};

#endif
