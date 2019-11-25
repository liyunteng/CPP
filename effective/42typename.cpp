// 42typename.cpp --

// Copyright (C) 2017 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2017/01/04 10:46:54

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

// 1.声明template参数时， class和typename可互换
// 2.请使用关键字typename标识嵌套从属类型名称； 但不得在base class lists(基类列
// 表)或member initialization list(成员初值列表)内以它作为base class修饰符

#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T>
void
print2nd(const T &container)
{
    // traits
    typedef typename std::iterator_traits<typename T::const_iterator>::value_type value_type;
    if (container.size() >= 2) {
        typename T::const_iterator iter(container.begin());
        ++iter;
        // int value = *iter;
        value_type value(*iter);
        std::cout << value << std::endl;
        ;
    }
}

int
main(void)
{
    std::vector<std::string> v;
    std::list<std::string>   l;
    for (int i = 0; i < 3; i++) {
        v.push_back(std::to_string(i));
        l.push_back(std::to_string(i));
    }

    print2nd(v);
    print2nd(l);
    return 0;
}
