// test2.cpp - test2

// Date   : 2020/12/09
#include <iostream>

template <typename T>
constexpr T pi = T(3.14159265358L);

int
main(void)
{
    std::cout << pi<int> << " " << pi<float> << " " << pi<double> << std::endl;
    return 0;
}
