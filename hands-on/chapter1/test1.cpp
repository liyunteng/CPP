// test1.cpp - test1

// Date   : 2020/12/09
#include <iostream>
#include <ostream>

class Rational {
    friend std::ostream& operator<<(std::ostream&, const Rational&);
public:
    explicit Rational(long n, long d):n_(n),d_(d){}
    Rational& operator+=(const Rational& rhs);

private:
    long n_;                    // numerator
    long d_;                    // denominator
};

Rational &
Rational::operator+=(const Rational &rhs)
{
    n_ = n_ * rhs.d_ + rhs.n_ * d_;
    d_ = d_ * rhs.d_;
    return *this;
}

std::ostream& operator<<(std::ostream&os, const Rational& r)
{
    os << r.n_ << "/" << r.d_;
    return os;
}

int main(void)
{
    Rational a(3, 4);
    Rational b(2, 5);
    std::cout << a << " + " << b << " = " << (a += b) << std::endl;

    return 0;
}
