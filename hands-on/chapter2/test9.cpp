// test9.cpp - test9

// Date   : 2020/12/09
#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int i, int j) {
    return i < j;
}


class compare1 {
public:
    bool operator()(int i, int j) const {
        return i < j;
    }
};

void do_work1() {
    std::vector<int>v{3, 2, 5, 1, 4};
    sort(v.begin(), v.end(), compare);
    for (auto x : v) {
        std::cout << x << std::endl;
    }
}

void do_work2() {
    std::vector<int>v{3, 2, 5, 1, 4};
    sort(v.begin(), v.end(), compare1());
    for (auto x : v) {
        std::cout << x << std::endl;
    }
}

void do_work3() {
    std::vector<int>v{3, 2, 5, 1, 4};
    auto compare = [](int i, int j) {
        return i < j;
    };
    sort(v.begin(), v.end(), compare);
    for (auto x : v) {
        std::cout << x << std::endl;
    }
}
int main(void)
{
    do_work1();
    do_work2();
    do_work3();

    return 0;
}
