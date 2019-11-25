// test_construct.cpp - test_construct

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/07/15

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#include <iostream>
#include <string>

class Test
{
public:
    Test()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    // const
    Test(const std::string &v) : m_val(v)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    Test(const Test &t) : m_val(t.m_val)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    Test &operator=(const Test &t)
    {
        m_val = t.m_val;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }

    // non-const
    Test(std::string &v) : m_val(v)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    Test(Test &t) : m_val(t.m_val)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    Test &operator=(Test &t)
    {
        m_val = t.m_val;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }

    ~Test()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

private:
    std::string m_val;
};

void
test1(Test a)
{
    (void)a;
}
void
test2(const Test a)
{
    (void)a;
}
void
testx(Test &a)
{
    (void)a;
}

void
testx(const Test &a)
{
    (void)a;
}
int
main(void)
{
    Test        a;
    Test        b("abc");
    std::string s = "xxx";
    Test        c(s);
    Test        d(c);
    const Test  e(d);
    Test        f(e);

    std::cout << "===========" << std::endl;

    a = b;
    f = e;

    std::cout << "===========" << std::endl;

    test1(e);
    test2(f);
    testx(f);
    testx(e);

    std::cout << "===========" << std::endl;
    return 0;
}
