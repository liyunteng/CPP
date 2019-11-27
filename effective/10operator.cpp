// -*- compile-command: "clang++ -Wall -o 10operator 10operator.cpp -g
// -std=c++11" -*- 10operator.cpp --

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/30 13:22:03

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

// assignment操作符返回一个reference to *this
// 使用copy-and-swap or move

#include <algorithm>
#include <iostream>
using namespace std;
class Widget
{
public:
    explicit Widget(int data) : m_data(data) {}
    ~Widget() {}

    Widget(const Widget &rhs) : m_data(rhs.m_data) {}
    Widget(const Widget &&rhs) : m_data(rhs.m_data) {}
    void swap(Widget &rhs) { std::cout << "refer" << std::endl; }
    Widget &operator=(const Widget &rhs)
    {
        std::cout << "aaa" << std::endl;
        Widget tmp(std::move(rhs));
        swap(tmp);
        return *this;
    }
    Widget &operator=(Widget &&rhs)
    {
        std::cout << "bbb" << std::endl;
        swap(rhs);
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Widget &w);

private:
    int m_data;
};

ostream &
operator<<(ostream &os, const Widget &w)
{
    return os << "data:" << w.m_data << std::endl;
}

struct Person {
    Person(const char *p) { cout << "constructor" << endl; }
    Person(const Person &p) { cout << "copy constructror" << endl; }
    Person(Person &&p) { cout << "move copy constructor" << endl; }
    const Person &operator=(const Person &p)
    {
        cout << "operator=" << endl;
        return *this;
    }
    const Person &operator=(Person &&rhs)
    {
        cout << "move operator=" << endl;
        return *this;
    }
    ~Person() { cout << "destructor" << endl; }
};
Person
getAlice()
{
    Person p("alice");
    return p;
}
int
main(void)
{
    // Widget w(0);
    // Widget w1(1);
    // cout << w;
    // cout << w1;
    // w1 = std::move(w);
    // cout << w1;
    // w1 = Widget(2);
    // cout << w1;
    // w1 = w1;
    // cout << w1;
    // return 0;

    cout << "__________" << endl;
    Person a = Person("");
    a        = getAlice();
    cout << "__________" << endl;
    a = getAlice();
    cout << "__________" << endl;
}
