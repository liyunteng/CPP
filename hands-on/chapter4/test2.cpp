// test2.cpp - test2

// Date   : 2020/12/09
#include <iostream>

using namespace std;
class Fun {

public:
    Fun() {}
    ~Fun() {}

    Fun(const Fun &rhs) {
        cout << "copy constructor" << endl;
    }

    Fun &operator=(const Fun&fun) {
        cout << "copy assign" << endl;
        return *this;
    }

    Fun(const Fun &&rhs) {
        cout << "move constructor" << endl;
    }

    Fun &operator=(Fun &&fun) {
        cout << "move assign" << endl;
        return *this;
    }
};

int main(void)
{
    Fun f, f2;
    swap(f, f2);
    return 0;
}
