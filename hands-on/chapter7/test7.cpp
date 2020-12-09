// test7.cpp - test7

// Date   : 2020/12/09
#include <iostream>

template<size_t N>
void
f(char (*)[N % 2] = NULL)
{
    std::cout << "N=" << N << " is odd" << std::endl;
}

template<size_t N>
void
f(char (*)[1 - N % 2] = NULL)
{
    std::cout << "N=" << N << " is even" << std::endl;
}

template<typename T, size_t N = T::N>
void
f(T t, char (*)[N % 2] = NULL)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T, size_t N = T::N>
void
f(T t, char (*)[1 - N % 2] = NULL)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

struct A {
    enum {
        N = 5
    };
};

struct B {
    enum {
        N = 8
    };
};

int
main(void)
{
    f<0>();
    f<1>();
    A a;
    B b;
    f(a);
    f(b);
    return 0;
}
