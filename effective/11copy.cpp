// 11copy.cpp --

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/30 13:19:21

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

// 1.确保复制了所有的local成员
// 2.调用base clasess的copy函数，如果使用copy constructor base 的构造函数
// 3.不要以某个copying函数实现另一个copying函数，如果需要将共同部分放到第三个函
// 数中，供两个copying函数调用

#include <iostream>
#include <string>

void
logCall(const std::string &funcName)
{
    std::cout << funcName << std::endl;
}
class Customer
{
public:
    Customer(std::string n) : name(n) {}
    ~Customer() {}

    Customer(const Customer &rhs);
    Customer &operator=(const Customer &rhs);

private:
    std::string name;
};

Customer::Customer(const Customer &rhs) : name(rhs.name)
{
    logCall("Customer copy constructor");
}

Customer &
Customer::operator=(const Customer &rhs)
{
    // Check for self-assignment!
    if (this == &rhs)
        return *this;
    logCall("Customer copy assignment operator");
    name = rhs.name;
    return *this;
}

class PriorityCustomer : public Customer
{
public:
    PriorityCustomer(std::string n, int p) : Customer(n), priority(p) {}
    ~PriorityCustomer() {}

    PriorityCustomer(const PriorityCustomer &rhs);
    PriorityCustomer &operator=(const PriorityCustomer &rhs);

private:
    int priority;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer &rhs)
    : Customer(rhs),  // 一定要显示初始化base
      priority(rhs.priority)
{
    logCall("PriorityCustomer copy constructor");
}
PriorityCustomer &
PriorityCustomer::operator=(const PriorityCustomer &rhs)
{
    // Check for self-assignment!
    if (this == &rhs)
        return *this;
    logCall("PriorityCustomer copy assigment operator");
    Customer::operator=(rhs);  // 一定要显示复制
    priority          = rhs.priority;
    return *this;
}
int
main(void)
{
    Customer         c1("c1");
    PriorityCustomer p1("ddd", 1);
    p1 = PriorityCustomer("abc", 2);
    return 0;
}
