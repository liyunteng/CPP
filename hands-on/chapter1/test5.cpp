// test5.cpp - test5

// Date   : 2020/12/09
#include <cstdlib>
#include <iostream>

class Base {
public:
    virtual void f() {
        std::cout << "Base::f()" << std::endl;
    }
    void g() {
        f();
    }
};

class Derived: private Base {
public:
    virtual void f() {
        std::cout << "Derived::f()" << std::endl;
    }
    void h() {
        g();
    }
};


int main(void)
{
    Derived *d1 = new Derived();
    d1->f();
    d1->h();

    return 0;
}
