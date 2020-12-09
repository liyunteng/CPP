// test1.cpp - test1

// Date   : 2020/12/09
#include <iostream>

template<typename T>
class Base
{
public:
    Base() : i_(0) {}
    virtual ~Base() {}

    void f(int i)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        derived()->f(i);  // call derived f()
    }
    int get() const { return i_; }

protected:
    int i_;

private:
    T *derived() { return static_cast<T *>(this); }
};

class Derived : public Base<Derived>
{
public:
    void f(int i)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        i_ += i;
    }
};

int
main(void)
{
    Base<Derived> *b = new Derived;
    for (int i = 0; i < 10; i++) {
        b->f(1);
        std::cout << b->get() << std::endl;
    }

    return 0;
}
