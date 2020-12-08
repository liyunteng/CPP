// test5.cpp - test5

// Date   : 2020/12/09
#include <iostream>

template<typename U, typename V>
U half(V x) {
    return static_cast<U>(x) / 2;
}

template<typename T>
T Max(T x, T y) {
    return x > y ? x : y;
}

int main(void)
{
    auto y = half<double>(8);
    std::cout << typeid(y).name() << std::endl;
    std::cout << Max(1, 2) << std::endl;
    return 0;
}

// Local Variables:
// compile-command: "clang++ -Wall -o test5 test5.cpp -g "
// End:
