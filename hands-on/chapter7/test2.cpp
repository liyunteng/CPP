// test2.cpp - test2

// Date   : 2020/12/09
#include <iostream>

void
f(int i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void f(...)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}


struct A {
};
struct B {
    operator int() const {return 0;}
};

int main(void)
{
    f(5);
    f(5l);
    f(5.0);

    A a;
    f(a); // f(...)
    B b;
    f(b);
    return 0;
}
