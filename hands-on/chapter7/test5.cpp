// test5.cpp - test5

// Date   : 2020/12/09
#include <iostream>

template<typename T>
void
f(T i, typename T::t &j)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
void
f(T i, T j)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

struct A {
    struct t {
        int i;
    };
    t i;
};

int main(void)
{
    A a{5};
    f(a, a.i);
    f(5, 7);
    return 0;
}
