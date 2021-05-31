// test5.cpp - test5

// Date   : 2020/12/09
#include <iostream>

// Leaky singleton
class Singleton
{
public:
    static Singleton &instance()
    {
        static Singleton *inst_ = new Singleton;
        return *inst_;
    }
    int &get() { return value_; }

private:
    Singleton() : value_(0) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    ~Singleton() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

private:
    int value_;
};

int
main(void)
{
    std::cout << Singleton::instance().get() << std::endl;
    Singleton::instance().get()++;
    std::cout << Singleton::instance().get() << std::endl;

    return 0;
}
