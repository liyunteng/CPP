// test4.cpp - test4

// Date   : 2020/12/09

#include <iostream>

class FlyingBird {
public:
    virtual void fly(double speed, double direction) = 0;
};

class Eagle : public FlyingBird {
public:
    virtual void fly(double speed, double direction) override {
        std::cout << "Eagle fly: " << speed << ", " << direction << std::endl;
    }
    // BUG:
    // virtual void fly(int speed, double direction) {
    //     std::cout << "Eagle fly: " << speed << ", " << direction << std::endl;
    // }
};

int main(void)
{
    FlyingBird *pb = new Eagle();

    pb->fly(1.0, 2.0);
    return 0;
}
