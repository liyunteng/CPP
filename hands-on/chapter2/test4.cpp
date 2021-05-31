// test4.cpp - test4

// Date   : 2020/12/09
#include <deque>
#include <iostream>
#include <vector>

template <typename T, template <typename...> class Out_container,
          template <typename...> class In_container>
Out_container<T>
transform(const In_container<T> &in)
{
    Out_container<T> out;
    for (auto x : in) {
        out.push_back(x);
    }
    return out;
}

int
main(void)
{
    std::vector<int> v{1, 2, 3};
    std::deque<int> d = transform<int, std::deque, std::vector>(v);
    for (auto x : d) {
        std::cout << x << std::endl;
    }
    return 0;
}

// Local Variables:
// compile-command: "clang++ -Wall -o test4 test4.cpp -g "
// End:
