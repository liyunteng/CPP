// test4.cpp - test4

// Date   : 2020/12/09
#include <iostream>

struct SingletonImpl;
class Singleton
{
public:
    int &get();

private:
    static SingletonImpl &impl();
};

struct SingletonImpl {
    SingletonImpl() : value_(0) {}
    int value_;
};

int &
Singleton::get()
{
    return impl().value_;
}

SingletonImpl &
Singleton::impl()
{
    static SingletonImpl inst;
    return inst;
};

int
main(void)
{
    std::cout << Singleton().get() << std::endl;
    Singleton().get()++;
    std::cout << Singleton().get() << std::endl;

    return 0;
}
