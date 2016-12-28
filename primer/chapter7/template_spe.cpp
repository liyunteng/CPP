// template_spe.cpp -- template sepcilaiztion and partial template sepcialization

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/28 16:13:49

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

template<typename T, typename N>
class Test
{
public:
    Test(T i, N j) : a(i), b(j)
        {
            cout << "普通模板类" << a << ' ' << b << endl;
        }
private:
    T a;
    N b;
};

template<>
class Test<int, char>
{
public:
    Test(int i, char j) : a(i), b(j)
        {
            cout <<"模板类特化" << a << ' ' << b << endl;
        }
private:
    int a;
    char b;
};

template<typename N>
class Test<char, N>
{
public:
    Test(char i, N j): a(i), b(j)
        {
            cout <<"模板类偏特化" << a << ' ' << b << endl;
        }
private:
    char a;
    N b;
};

template<typename T1, typename T2>
void fun(T1 a, T2 b)
{
    cout << "模板函数" << endl;
}

template<>
void fun<int, char> (int a, char b)
{
    cout << "模板函数特化" << endl;
}

// 模板函数不存在偏特化
// template <typename T2>
// void fun<char, T2>(char a, T2 b)
// {
//     cout << "模板函数偏特化" << endl;
// }

int main(void)
{
    Test<double, double> t1(0.1, 0.2); // 普通模板
    Test<int, char> t2(1, 'A');        // 全特化
    Test<char, bool> t3('A', true);     // 偏特化
    return 0;
}
