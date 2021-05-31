// nonmember_swap_friend.cpp - nonmember_swap_friend

// Date   : 2020/12/09
#include <iostream>
#include <utility>

using std::swap;

namespace N {

class C
{
public:
    explicit C(int i) : i_(i) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    C(const C &rhs) : i_(rhs.i_)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~C() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    C &operator=(const C &rhs)
    {
        i_ = rhs.i_;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }
    void swap(C &rhs) noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::swap(i_, rhs.i_);
    }
    friend void swap(C &lhs, C &rhs) noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        lhs.swap(rhs);
    }
    int i_;
};

}  // namespace N

int
main(void)
{
    N::C c1(1), c2(2);
    std::cout << "Initail: " << std::endl;
    std::cout << "c1: " << c1.i_ << " c2: " << c2.i_ << std::endl;

    std::cout << "\nstd::swap: " << std::endl;
    std::swap(c1, c2);
    std::cout << "c1: " << c1.i_ << " c2: " << c2.i_ << std::endl;

    std::cout << "\nswap: " << std::endl;
    swap(c1, c2);
    std::cout << "c1: " << c1.i_ << " c2: " << c2.i_ << std::endl;

    return 0;
}
