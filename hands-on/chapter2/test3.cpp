// test3.cpp - test3

// Date   : 2020/12/09
#include <iostream>

template <typename T, size_t N>
class Array
{
public:
    T &operator[](size_t i)
    {
        if (i >= N) throw std::out_of_range("Bad index");
        return data_[i];
    }

private:
    T data_[N];
};

int
main(void)
{
    Array<int, 3> a;
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    std::cout << a[0] << " " << a[1] << " " << a[2] << std::endl;

    // BUG:
    // std::cout<< a[3] << std::endl;
    return 0;
}
