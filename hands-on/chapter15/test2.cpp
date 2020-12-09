// test2.cpp - test2

// Date   : 2020/12/09
#include <iostream>

class Singleton {
public:
    static int& get() {return value_;}
private:
    Singleton() = delete;
    static int value_;
};

int Singleton::value_ = 0;


int main(void)
{
    std::cout << Singleton::get() << std::endl;
    Singleton::get()++;
    std::cout << Singleton::get() << std::endl;

    return 0;
}
