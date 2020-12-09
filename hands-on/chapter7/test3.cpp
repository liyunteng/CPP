// test3.cpp - test3

// Date   : 2020/12/09
#include <iostream>

template<typename T>
void f(T i, T *p)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main(void)
{
    int i;
    f(5, &i);

    f<int>(5l, &i);
    // BUG:
    // f(5l, &i);
    return 0;
}
