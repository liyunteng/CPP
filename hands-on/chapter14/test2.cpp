// test2.cpp - test2

// Date   : 2020/12/09
#include <iostream>

class Base
{
public:
    bool TheAlgorithm()
    {
        if (!Step1())
            return false;
        Step2();
        return true;
    }

private:
    virtual bool Step1() { return true; }
    virtual void Step2() = 0;
};

class Derived : public Base
{
private:
    virtual void Step2()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

class Derived2 : public Base
{
private:
    virtual void Step2()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int
main(void)
{
    Derived2 d;
    d.TheAlgorithm();
    Derived d1;
    d1.TheAlgorithm();
    return 0;
}
