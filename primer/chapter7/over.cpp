// over.cpp -- overload override overwrite

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/29 16:46:53

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

// 调用成员函数的步骤：
// 1.确定函数调用的对象，引用或者指针的静态类型
// 2.在该类中查找函数，如果找不到就在基类中查找，如此循环直到最上层
// 3.一旦找到名字，就进行常规的参数类型检查
// 4.如果函数调用合法，编译器生成代码。如果函数是虚函数且通过引用
// 或者指针调用，编译器生成代码以确定对象的动态类型运行哪个版本
// 注意： 名字查找发生在编译阶段(即使是虚函数调用)，而且与参数检查是不
// 同阶段

#include <iostream>
using namespace std;

class B1 final {};
class Base
{
public:
    Base() { std::cout << "Base Ctor" << std::endl;}
    virtual ~Base() { std::cout << "Base Dtor" << std::endl;}

    void fun1() {
        std::cout << "Base:fun1()" << std::endl;
    }
    virtual void fun1(int a) {
        std::cout << "Base::fun1(int " << a << ")" << std::endl;
    }
    void fun1(std::string s) {
        std::cout << "Base::fun1(string " << s << ")"  << std::endl;
    }
};

class Sub : public Base
{
public:
    Sub() { std::cout << "Sub Ctor" << std::endl; }
    virtual ~Sub() { std::cout << "Sub Dtor" << std::endl; }

    virtual void fun1(double f) {       // redefine, can't use Sub.fun1()
                                // Sub.fun1(int) Sub.fun(string)
        std::cout << "Sub::fun1(double " << f << ")" << std::endl;
    }

    void fun2(int a) {
        std::cout << "Sub::fun2(int " << a << std::endl;
    }
};

class SubSub : public Sub
{
public:
    SubSub() { std::cout << "SubSub Ctor" << std::endl; }
    ~SubSub() { std::cout << "SubSub Dtor" << std::endl; }

    void fun1(int a) {
        std::cout << "SubSub:fun1(int " << a << ")" << std::endl;
    }
};

// class B
// {
// public:
//      virtual void f() const
//           {
//                std::cout << __FUNCTION__ << std::endl;
//           }
//      virtual void fun()
//           {
//                std::cout << __FUNCTION__ << std::endl;
//           }
// };

// class D : public B
// {
// public:
//      virtual void f(int)        // overwrite
//           {
//                std::cout << "hiding: " << __FUNCTION__ << std::endl;
//                B::f();          //
//           }
//      // virtual void f() const        // override
//      //      {
//      //           std::cout << "override: " << __FUNCTION__ << std::endl;
//      //      }
//      virtual void fun() override final
//           {
//                std::cout << "override: " << __FUNCTION__ << std::endl;
//           }
// };

// class D2 : public D
// {
// public:
//      virtual void f() const
//           {
//                std::cout << __FUNCTION__ << std::endl;
//           }
// };

int main(void)
{
     // D2 d2;
     // D d1;
     // B *b = &d1;
     // b->f();
     // b->fun();

     // d1.f(10);

     // d2.f();
     // d2.fun();

    Sub *s = new Sub();
    Base *b = s;
    b->fun1();
    b->fun1(1);
    b->fun1("abc");

    // s->fun1();   //参数类型检查失败
    s->fun1(1);
    // s->fun1("abc"); //参数类型检查失败
    delete s;
    SubSub *ss = new SubSub();
    b = ss;

    b->fun1();
    b->fun1(0);
    b->fun1("abc");

    // s->fun1();
    s->fun1(0);
    // s->fun1("abc");

    delete ss;
    return 0;
}
