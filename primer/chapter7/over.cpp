// over.cpp -- overload override overwrite

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/28 18:08:24

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

class B1 final {};

class B
{
public:
     virtual void f() const
          {
               std::cout << __FUNCTION__ << std::endl;
          }
     virtual void fun()
          {
               std::cout << __FUNCTION__ << std::endl;
          }
};

class D : public B
{
public:
     virtual void f(int)        // overwrite
          {
               std::cout << "hiding: " << __FUNCTION__ << std::endl;
               B::f();          //
          }
     // virtual void f() const        // override
     //      {
     //           std::cout << "override: " << __FUNCTION__ << std::endl;
     //      }
     virtual void fun() override final
          {
               std::cout << "override: " << __FUNCTION__ << std::endl;
          }
};

class D2 : public D
{
public:
     virtual void f() const
          {
               std::cout << __FUNCTION__ << std::endl;
          }
};

int main(void)
{
     D2 d2;
     D d1;
     B *b = &d1;
     b->f();
     b->fun();

     d1.f(10);

     d2.f();
     d2.fun();
     return 0;
}
