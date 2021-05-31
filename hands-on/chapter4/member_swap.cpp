// member_swap.cpp - member_swap

// Date   : 2020/12/09
#include <iostream>
#include <utility>

class C
{
public:
    explicit C(int i) : i_(i) {}
    void swap(C &rhs) noexcept
    {
        using std::swap;
        swap(i_, rhs.i_);
    }
    int i_;
};

int
main(void)
{
    C c1(1), c2(2);

    std::cout << "Initial: " << std::endl;
    std::cout << "c1: " << c1.i_ << " c2: " << c2.i_ << std::endl;

    c1.swap(c2);
    std::cout << "\nAfter swap: " << std::endl;
    std::cout << "c1: " << c1.i_ << " c2: " << c2.i_ << std::endl;
    return 0;
}
