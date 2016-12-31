// 13manage_resource_use_objects.cpp --

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/31 04:31:51

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


// 1.防止资源泄露，使用RAII对象，他们在构造函数中获得资源，在析构函数中释放资源
// 2.常用的RAII std::shared_ptr std::unique_ptr
#include <string>
#include <memory>
using namespace std;

void testString()
{
    shared_ptr<string>ps("abdefg");
}

int main(void)
{
    return 0;
}
