// test6.cpp - test6

// Date   : 2020/12/09
#include <iostream>

template<typename T>
void
f(T *i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
void
f(int T::* p)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

struct A {
    int i;
    int f() {return 0;}
};

int main(void)
{
    A a;
    f(&a.i);  // f(T*)
    f(&A::i); // f(T::*)
    return 0;
}
