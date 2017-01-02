// 13manage_resource_use_objects.cpp --

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2017/01/02 20:20:57

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


// 1.防止资源泄露，使用RAII对象，他们在构造函数中获得资源，在析构函数中释放资源
// 2.常用的RAII std::shared_ptr std::unique_ptr
#include <string>
#include <memory>
#include <iostream>
#include <cstdlib>

using namespace std;
class Base
{
public:
    explicit Base(size_t data): m_data(data) {
        m_ptr = (char *)malloc(m_data);
        cout << __func__ << " constructor"
             << " data: " << m_data
             << " ptr: " << sizeof(m_ptr)
             << endl;
    }
    ~Base() {
        if (m_ptr) {
            free(m_ptr);
        }
        cout << __func__ << " destructor" << endl;
    }

    Base(const Base& rhs): m_data(rhs.m_data) {
        m_ptr = (char *)malloc(m_data);
        cout << __func__ << " copy constructor" << endl;
    }
    Base (Base&& rhs): m_data(rhs.m_data) {
        m_ptr = rhs.m_ptr;
        m_data = rhs.m_data;
        rhs.m_ptr = nullptr;
        rhs.m_data = 0;
        cout << __func__ << " move constructor" << endl;
    }
    Base& operator=(const Base& rhs) {
        if (this == &rhs)
            return *this;

        m_data = rhs.m_data;
        if (m_ptr){
            free(m_ptr);
        }
        m_ptr = (char *)malloc(m_data);
        cout << __func__ << " assignment operator=" << endl;
        return *this;
    }
    Base& operator=(Base&& rhs) {
        m_data = rhs.m_data;
        m_ptr = rhs.m_ptr;
        rhs.m_data = 0;
        rhs.m_ptr = nullptr;
        cout << __func__ << " move operator=" << endl;
        return *this;
    }

    void show() {
        cout << __func__ << " show:" << m_data
             << " ptr size: " << sizeof(m_ptr)
             << endl;
    }
private:
    size_t m_data;
    char *m_ptr;
};

void testShared()
{
    shared_ptr<Base>pb(make_shared<Base>(1));
    shared_ptr<Base>pb2(pb);
    pb->show();
    pb2->show();
    cout << "count: " << pb.use_count()
         << "unique: " << pb.unique()
         << endl;
    // pb.reset();
    cout << "end" << endl;
}

void testUnique()
{
    unique_ptr<Base>pb(new Base(2));
    unique_ptr<Base>pb2;
    pb2 = move(pb);
    pb2->show();
    // pb2.reset();

    // Base *b = pb2.release();
    // b->show();

    pb.reset(pb2.release());
    pb->show();

    cout << "end" << endl;
}

int main(void)
{
    // testShared();
    testUnique();
    cout << "done" << endl;
    return 0;
}
