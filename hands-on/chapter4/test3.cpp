// test3.cpp - test3

// Date   : 2020/12/09
#include <iostream>
#include <utility>
#include <vector>

int bad_i = -1;

class C
{
public:
    explicit C() : m_i() {}
    explicit C(int i) : m_i(i) {}
    C(const C &rhs) : m_i(rhs.m_i)
    {
        if (m_i == bad_i)
            throw m_i;
    }
    int m_i;
};

using vec = std::vector<C>;

C
transmogrify(C x)
{
    return C(2 * x.m_i);
}

void
transmogrify_not_safe(const vec &in, vec &out)
{
    out.resize(0);
    out.reserve(in.size());
    for (const auto &x : in) {
        out.push_back(transmogrify(x));
    }
}

void
transmogrify_safe(const vec &in, vec &out)
{
    vec tmp;
    tmp.reserve(in.size());
    for (const auto &x : in) {
        tmp.push_back(transmogrify(x));
    }
    out.swap(tmp);
}

int
main(void)
{
    vec v1{C(1), C(2), C(3), C(4)};
    {
        // No exceptions - OK
        bad_i = -1;
        vec v2;
        transmogrify_not_safe(v1, v2);
        std::cout << "v2(" << v2.size() << "/" << v2.capacity() << "):";
        for (auto x : v2) {
            std::cout << " " << x.m_i;
        }
        std::cout << std::endl;
    }
    {
        // exception - partially constructed result
        bad_i = 6;
        vec v2;
        try {
            transmogrify_not_safe(v1, v2);
        } catch (...) {
        }
        std::cout << "v2(" << v2.size() << "/" << v2.capacity() << "):";
        for (auto x : v2) {
            std::cout << " " << x.m_i;
        }
        std::cout << std::endl;
    }
    {
        // exception - initial content lost
        bad_i = 1;
        vec v2{C(5)};
        try {
            transmogrify_not_safe(v1, v2);
        } catch (...) {
        }
        std::cout << "v2(" << v2.size() << "/" << v2.capacity() << "):";
        for (auto x : v2) {
            std::cout << " " << x.m_i;
        }
        std::cout << std::endl;
    }
    {
        // No exceptions - OK
        // No exceptions - OK
        bad_i = -1;
        vec v2;
        transmogrify_safe(v1, v2);
        std::cout << "v2(" << v2.size() << "/" << v2.capacity() << "):";
        for (auto x : v2) {
            std::cout << " " << x.m_i;
        }
        std::cout << std::endl;
    }
    {
        // exception - rollback
        bad_i = 6;
        vec v2;
        try {
            transmogrify_safe(v1, v2);
        } catch (...) {
        }
        std::cout << "v2(" << v2.size() << "/" << v2.capacity() << "):";
        for (auto x : v2) {
            std::cout << " " << x.m_i;
        }
        std::cout << std::endl;
    }
    {
        // exception - initial content remains
        bad_i = 1;
        vec v2{C(5)};
        try {
            transmogrify_safe(v1, v2);
        } catch (...) {
        }
        std::cout << "v2(" << v2.size() << "/" << v2.capacity() << "):";
        for (auto x : v2) {
            std::cout << " " << x.m_i;
        }
        std::cout << std::endl;
    }
    return 0;
}
