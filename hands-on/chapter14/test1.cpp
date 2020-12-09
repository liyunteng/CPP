// test1.cpp - test1

// Date   : 2020/12/09
// NVI
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    void method1() { method2(); }

private:
    virtual void method2() { cout << "Base Method2" << endl; }
};

class Derived : public Base
{
private:
    virtual void method2() { cout << "Derived Method2" << endl; }
};

int
main(int argc, char *argv[])
{
    Base *b = new Base;
    b->method1();

    Base *d = new Derived;
    d->method1();
    return 0;
}
