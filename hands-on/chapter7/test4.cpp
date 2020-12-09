// test4.cpp - test4

// Date   : 2020/12/09
#include <iostream>

void
f(int i, int j = 0)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
void
f(T i, T *p = nullptr)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void
f(...)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main(void)
{
    int i;
    f(5);
    f(5l);
    f(5, &i);
    f(5l, &i);
    return 0;
}
