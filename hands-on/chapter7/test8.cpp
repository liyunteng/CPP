// test8.cpp - test8

// Date   : 2020/12/09
#include <iostream>

template<typename T>
void
f(int T::*)
{
    std::cout << "T is a class" << std::endl;
}

template<typename T>
void
f(...)
{
    std::cout << "T is not a class" << std::endl;
}


template<typename T>
class is_class {
    template<typename C>
    static char test(int C::*);

    template<typename C>
    static int test(...);

public:
    static constexpr bool value = sizeof(test<T>(NULL)) == 1;
};

struct A {
};

int main(void)
{
    f<int>(0);
    f<A>(0);

    std::cout << is_class<int>::value << std::endl;
    std::cout << is_class<A>::value << std::endl;
    return 0;
}
