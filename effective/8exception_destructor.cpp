// 8exception_destructor.cpp --

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/29 23:27:00

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

// 1.析构绝对不要吐出异常， 如果析构被调用时抛出异常，a.结束程序 b.吞下异常
// 2.如果客户需要对某个操作运行期间抛出的异常做出反应，class应该对该操
// 作提供一个普通函数
int main(void)
{
    return 0;
}
