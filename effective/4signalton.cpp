// signalton.cpp -- signalton

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/29 21:46:51

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
using std::cout;
using std::endl;
class Signalton1
{
public:
    virtual ~Signalton1() {
        cout << __func__ << " Dtor" << endl;
    }
    int data() {
        return m_data;
    }
    static Signalton1 &getInstance() {
        return instance;
    }

private:
    Signalton1(int data): m_data(data) {
        cout << __func__ << " Ctor" << endl;
    }
    Signalton1(const Signalton1 &rhs);
    Signalton1& operator= (const Signalton1 &rhs);
    static Signalton1 instance;
    int m_data;
};
Signalton1 Signalton1::instance = Signalton1(1);


class Signalton2
{
public:
    virtual ~Signalton2() {
        cout << __func__ << " Dtor" << endl;
    }
    static Signalton2 &getInstance() {
        static Signalton2 instance(2);
        return instance;
    }

    int data() {
        return m_data;
    }
private:
    Signalton2(int data): m_data(data) {
        cout << __func__ << " Ctor" << endl;
    }
    Signalton2(const Signalton2 &rhs);
    Signalton2& operator= (const Signalton2 &rhs);
    int m_data;
};

// same as Signalton2
class Signalton3
{
public:
    virtual ~Signalton3() {
        cout << __func__ << " Dtor" << endl;
    }
    static Signalton3 &getInstance() {
        static Signalton3 instance(2);
        return instance;
    }

    int data() {
        return m_data;
    }
private:
    Signalton3(int data): m_data(data) {
        cout << __func__ << " Ctor" << endl;
    }
    Signalton3(const Signalton3 &rhs);
    Signalton3& operator= (const Signalton3 &rhs);
    int m_data;
};


int main(void)
{
    cout << "begin Signalton1" << endl;
    Signalton1 &s1 = Signalton1::getInstance();
    cout << s1.data() << endl;

    // local static 变量的初始化顺序可预测
    cout << "begin Signalton2" << endl;
    Signalton2 &s2 = Signalton2::getInstance();
    cout << s2.data() << endl;

    cout << "begin Signalton3" << endl;
    Signalton3 &s3 = Signalton3::getInstance();
    cout << s3.data() << endl;

    return 0;
}
