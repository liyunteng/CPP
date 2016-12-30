// 7declar_virtual_destructor.cpp --

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/29 23:00:55

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

// 1.base类 析构必须virtual， 否则会造成子类资源泄露
// 2.不是base类的 析构不要加virtual，影响性能
// 3.抽象基类,可通过纯虚析构来定义， 并为纯虚析构实现个定义

class AWOV {
public:
    virtual ~AWOV() = 0;
};

// 不加会引起编译错误,子类不能调用base类的析构
AWOV::~AWOV() {}

class A : public AWOV
{
public:
    A() {}
    ~A(){}
};

int main(void)
{
    A a;
    return 0;
}
