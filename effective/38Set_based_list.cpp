// 38Set_based_list.cpp --

// Copyright (C) 2017 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2017/01/03 17:20:55

// This program is free software; you can redistribute it and/or modify
// it under the terms and conditions of the GNU General Public License
// version 2,as published by the Free Software Foundation.

// This program is distributed in the hope it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.

// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation,
// Inc.,51 Franklin St - Fifth Floor, Boston,MA 02110-1301 USA.

#include <algorithm>
#include <list>

template<typename T>
class Set
{
public:
    bool member(const T &item) const;
    void insert(const T &item);
    void remove(const T &item);
    std::size_t size() const;

private:
    std::list<T> rep;
};

template<typename T>
bool
Set<T>::member(const T &item) const
{
    return std::find(rep.begin(), rep.end(), item) != rep.end();
}

template<typename T>
void
Set<T>::insert(const T &item)
{
    if (!member(item))
        rep.push_back(item);
}

template<typename T>
void
Set<T>::remove(const T &item)
{
    typename std::list<T>::iterator it =
        std::find(rep.begin(), rep.end(), item);
    if (it != rep.end())
        rep.erase(it);
}

template<typename T>
std::size_t
Set<T>::size() const
{
    return rep.size();
}

int main(void)
{
    return 0;
}
