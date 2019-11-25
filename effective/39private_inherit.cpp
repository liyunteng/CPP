// 39private_inherit.cpp --

// Copyright (C) 2017 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2017/01/03 17:28:02

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

#include <iostream>
using namespace std;
class Base
{
public:
    Base() {}
    ~Base() {}
    void show()
    {
        cout << __func__ << endl;
    }

private:
};

class Derived : private Base
{
public:
    Derived() {}
    ~Derived() {}
    void a()
    {
        this->show();
    }
};

class Timer
{
public:
    explicit Timer(int tickFrequency);
    virtual void onTick() const;
};

class Widget
{
public:
    Widget();
    ~Widget();

private:
    class WidgetTimer : public Timer
    {
    public:
        virtual void onTick() const;
    };
    WidgetTimer timer;
};

int
main(void)
{
    // 不能多态
    // Base *pd = new Derived();
    Derived *p = new Derived();
    // p没有show接口， 继承来的show 为private
    p->a();
    return 0;
}
