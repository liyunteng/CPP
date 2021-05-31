// test6.cpp - test6

// Date   : 2020/12/09
#include <iostream>

template <typename N, typename D>
class Ratio
{
public:
    Ratio() : num_(), denom_() {}

    Ratio(const N &num, const D &denom) : num_(num), denom_(denom) {}

    explicit operator double() const { return double(num_) / double(denom_); }

private:
    N num_;
    D denom_;
};

template <typename N, typename D>
Ratio<N, D>
make_ratio(const N &num, const D &denom)
{
    return {num, denom};
}

// 全特化
template <>
class Ratio<double, double>
{
public:
    Ratio() : value_() {}

    template <typename N, typename D>
    Ratio(const N &num, const D &denom) : value_(double(num) / double(denom))
    {
    }

    explicit operator double() const { return value_; }

private:
    double value_;
};

// 偏特化
template <typename D>
class Ratio<double, D>
{
public:
    Ratio() : value_() {}
    Ratio(const double &num, const D &denom) : value_(num / double(denom)) {}

    explicit operator double() const { return value_; }

private:
    double value_;
};

template <typename N, typename D>
class Ratio<N *, D *>
{
public:
    Ratio(N *num, D *denom) : num_(num), denom_(denom) {}
    explicit operator double() const { return double(*num_) / double(*denom_); }

private:
    N *num_;
    D *denom_;
};

int
main(void)
{
    auto r(make_ratio(1, 2.5));
    std::cout << typeid(r).name() << ": " << double(r) << std::endl;
    auto d(make_ratio(1.0, 2.0));
    std::cout << typeid(d).name() << ": " << double(d) << std::endl;
    int i    = 5;
    double x = 10;
    auto z(make_ratio(&i, &x));
    std::cout << typeid(z).name() << ": " << double(z) << std::endl;
    return 0;
}
