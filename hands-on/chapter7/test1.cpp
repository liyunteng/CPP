// test1.cpp - test1

// Date   : 2020/12/09
#include <iostream>

void f(int i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void f(long i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void f(double i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void f(int i, int j)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void f(long i, long j)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
void f(T i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
void f(T* i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
int main(void)
{
    f(5);
    f(5l);
    f(5.0);
    f(5.0f);
    f(static_cast<int>(5u));
    f(5u);
    int i = 0;
    f(&i);


    f(5, 5);
    f(5l, 5l);
    f(5, 5.0);
    f(5.0, 5);
    // BUG:
    // f(5, 5l);
    return 0;
}
