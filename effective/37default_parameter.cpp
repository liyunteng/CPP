// 37default_parameter.cpp --

// Copyright (C) 2017 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2017/01/03 11:32:05

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

// 绝对不要重新定义一个继承而来的缺省参数值，因为缺省参数值是静态绑定，而virtaul
// 函数是动态绑定
#include <iostream>
using namespace std;

class Shape
{
public:
    enum ShapeColor {Red, Green, Blue};
    virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle: public Shape
{
public:
    virtual void draw(ShapeColor color = Green) const {
        cout << "color: " << color << endl;
    }
};

class Cricle: public Shape
{
public:
    virtual void draw(ShapeColor color) const {
        cout << "color: " << color << endl;
    }
};

int main(void)
{
    Shape *pc = new Cricle;
    Shape *pr = new Rectangle;
    pc->draw();
    pr->draw();

    Rectangle *r = new Rectangle;
    r->draw();
    return 0;
}
