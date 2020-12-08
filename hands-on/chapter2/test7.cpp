// test7.cpp - test7

// Date   : 2020/12/09
#include <iostream>

// 这不是特化,特化必须要有模板原型
template<typename T>
void whatami(T *x) {
    std::cout << x << " is " << typeid(x).name() << std::endl;
}

template<typename T>
void whatami(T &&x) {
    std::cout << "is " << typeid(x).name() << std::endl;
}

void whatami(int x) {
    std::cout << x << " is " << typeid(x).name() << std::endl;
}

void whatami(long x) {
    std::cout << x << " is " << typeid(x).name() << std::endl;
}

void whatami(...) {
    std::cout << "It's something or somethings" << std::endl;
}

class A {};
int main(void)
{
    whatami(5);
    whatami(5L);
    int i = 3;
    whatami(&i);
    A a;
    whatami(a);
    whatami(3.0);
    whatami();
    return 0;
}
