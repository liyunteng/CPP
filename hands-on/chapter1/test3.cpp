// test3.cpp - test3

// Date   : 2020/12/09

#include <iostream>

class Empty {
public:
    void usefule_function();
}; // sizeof(Empty) = 1

class Derived: private Empty {
    int i;
}; // sizeof(Derived) == 4

class Composed {
    int i;
    Empty e;
}; // sizeof(Composed) == 8

int main(void)
{
    std::cout << "Empty: " <<  sizeof(Empty) << std::endl;
    std::cout << "Derived: " << sizeof(Derived) << std::endl;
    std::cout << "Compose: " << sizeof(Composed) << std::endl;
    return 0;
}
