// test1.cpp - test1

// Date   : 2020/12/09

#include <iostream>

class Singleton
{
public:
    Singleton() {}
    int &get() { return value_; }

private:
    static int value_;
};

int Singleton::value_ = 0;

int
main(void)
{
    std::cout << Singleton().get() << std::endl;
    Singleton().get()++;
    std::cout << Singleton().get() << std::endl;

    return 0;
}
