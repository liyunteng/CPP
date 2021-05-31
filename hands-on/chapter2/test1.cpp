// test1.cpp - test1

// Date   : 2020/12/09
#include <iostream>

template <typename T>
T
increment(T x)
{
    return x + 1;
}

template <typename T>
T
sum(T from, T to, T step)
{
    T res = from;
    while ((from += step) < to) {
        res += from;
    }
    return res;
}

template <typename T>
class ArrayOf2
{
public:
    T &operator[](size_t i) { return a_[i]; }
    const T &operator[](size_t i) const { return a_[i]; }
    T sum() const { return a_[0] + a_[1]; }

private:
    T a_[2];
};

int
main(void)
{
    std::cout << increment(5) << std::endl;
    std::cout << increment(5.1) << std::endl;
    char c[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << increment(c) << std::endl;

    std::cout << sum(1, 10, 2) << std::endl;

    ArrayOf2<int> i;
    i[0] = 1;
    i[1] = 2;
    std::cout << i.sum() << std::endl;

    ArrayOf2<double> x;
    x[0] = 1.2;
    x[1] = 2.3;
    std::cout << x.sum() << std::endl;

    return 0;
}
