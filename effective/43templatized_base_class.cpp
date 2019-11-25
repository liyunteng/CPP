// 43templatized_base_class.cpp --

// Copyright (C) 2017 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2017/01/04 11:17:04

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
#include <string>
using namespace std;
class CompanyA
{
public:
    void sendCleartext(const string &msg)
    {
        cout << __func__ << msg << endl;
    }
    void sendEncrypted(const string &msg)
    {
        cout << __func__ << msg << endl;
    }
};

class CompanyB
{
public:
    void sendCleartext(const string &msg)
    {
        cout << __FUNCTION__ << msg << endl;
    }
    void sendEncrypted(const string &msg)
    {
        cout << __FUNCTION__ << msg << endl;
    }
};
class CompanyZ
{
public:
    void sendEncrypted(const string &msg)
    {
        cout << __FUNCTION__ << msg << endl;
    }
};

template <typename Company>
class MsgSender
{
public:
    void sendClear(const string &msg)
    {
        Company c;
        c.sendCleartext(msg);
    }
    void sendSecret(const string &msg)
    {
        Company c;
        c.sendEncrypted(msg);
    }
};
// 特化
template <>
class MsgSender<CompanyZ>
{
public:
    void sendSecret(const string &msg)
    {
        CompanyZ c;
        c.sendEncrypted(msg);
    }
};

template <typename Company>
class LogingMsgSender : public MsgSender<Company>
{
public:
    // 告诉编译器，请它假设sendClear位于base class中
    using MsgSender<Company>::sendClear;
    void sendClearMsg(const string &msg)
    {
        cout << "do loging" << endl;
        sendClear(msg);
    }
    void sendSecretMsg(const string &msg)
    {
        cout << "do loging" << endl;
        // 假设sendEncrypted将被继承
        // this->sendEncrypted(msg);
        MsgSender<Company>::sendSecret(msg);
    }
};

template <>
class LogingMsgSender<CompanyZ> : public MsgSender<CompanyZ>
{
public:
    void sendSecretMsg(const string &msg)
    {
        cout << "do loging" << endl;
        this->sendSecret(msg);
    }
};

int
main(void)
{
    LogingMsgSender<CompanyA> senderA;
    senderA.sendClearMsg("abc");
    LogingMsgSender<CompanyZ> senderZ;
    // senderZ.sendClearMsg("aaa");
    senderZ.sendSecretMsg("aaa");
    return 0;
}
