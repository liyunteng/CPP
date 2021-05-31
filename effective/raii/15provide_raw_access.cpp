// 15provide_raw_access.cpp --

// Copyright (C) 2017 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2017/01/02 20:27:18

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

// 1.APIs往往要求访问原始资源，所以每一个RAII class应该提供一个”取得其所管理之资
// 源“的方法
// 2.对原始资源的访问可能经由显示转换或隐式转换，一般而言显示转换比较安全，但隐
// 式转换对客户比较方便
int main(void)
{
    return 0;
}
