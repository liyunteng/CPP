// test10.cpp - test10

// Date   : 2020/12/09
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename... F>
struct overload_set;

template<typename F1>
struct overload_set<F1> : public F1 {
    overload_set(F1 &&f1) : F1(std::move(f1)) {}
    overload_set(const F1 &&f1) : F1(f1) {}

    using F1::operator();
};

template<typename F1, typename... F>
struct overload_set<F1, F...> : public F1, public overload_set<F...> {
    overload_set(F1 &&f1, F &&...f) :
        F1(std::move(f1)), overload_set<F...>(std::forward<F>(f)...)
    {
    }
    overload_set(const F1 &f1, F &&...f) :
        F1(f1), overload_set<F...>(std::forward<F>(f)...)
    {
    }

    using F1::operator();
};

template<typename... F>
auto
overload(F &&...f)
{
    return overload_set<F...>(std::forward<F>(f)...);
}

int
main(void)
{
    int i    = 5;
    double d = 7.3;
    auto l =
        overload([](int *i) { std::cout << "i = " << *i << std::endl; },
                 [](double *d) { std::cout << "d = " << *d << std::endl; });

    l(&i);
    l(&d);

    return 0;
}
