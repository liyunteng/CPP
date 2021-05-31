// test8.cpp - test8

// Date   : 2020/12/09
#include <deque>
#include <iostream>
#include <vector>

template<typename... T>
auto
sum(const T &...x)
{
    return (x + ...);
}

template<typename T1>
auto
sum1(const T1 &x1)
{
    std::cout << "last" << std::endl;
    return x1;
}
template<typename T1, typename... T>
auto
sum1(const T1 &x1, const T &...x)
{
    std::cout << "enter sum" << std::endl;
    return x1 + sum1(x...);
}

template<typename... T>
struct Group;

template<typename T1>
struct Group<T1> {
    T1 t1_;

    Group() = default;
    explicit Group(const T1 &t1) : t1_(t1) {}
    explicit Group(T1 &&t1) : t1_(std::move(t1)) {}
    explicit operator const T1 &() const { return t1_; }
    explicit operator T1 &() const { return t1_; }
};

template<typename T1, typename... T>
struct Group<T1, T...> : Group<T...> {
    T1 t1_;

    Group() = default;
    explicit Group(const T1 &t1, T &&...t) :
        Group<T...>(std::forward<T>(t)...), t1_(t1)
    {
    }
    explicit Group(T1 &&t1, T &&...t) :
        Group<T...>(std::forward<T>(t)...), t1_(std::move(t1))
    {
    }
    explicit operator const T1 &() const { return t1_; }
    explicit operator T1 &() { return t1_; }
};
int
main(void)
{
    std::cout << sum(5, 7, 3) << std::endl;
    std::cout << sum(1.0, 2, 3L, 'a') << std::endl;
    std::cout << sum1(1.0, 2, 3L, 'a') << std::endl;

    Group<int, std::string> g(3, std::string("abc"));
    std::cout << int(g) << std::endl;
    // BUG: why ???
    // std::cout << std::string(g) << std::endl; // should be "abc"

    return 0;
}

// Local Variables:
// compile-command: "clang++ -Wall -o test8 test8.cpp -g "
// End:
