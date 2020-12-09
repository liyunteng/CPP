// test1.cpp - test1

// Date   : 2020/12/09
#include <iostream>

template<typename T>
class raii
{
public:
    explicit raii(T *p) : _p(p) {}
    ~raii() { delete _p; }

private:
    T *_p;
};

struct A {
    explicit A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int
main(void)
{
    {
        raii<A> a(new A());
    }
    std::cout << "done" << std::endl;
    return 0;
}
