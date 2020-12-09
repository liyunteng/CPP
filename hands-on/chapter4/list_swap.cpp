// list_swap.cpp - list_swap

// Date   : 2020/12/09
#include <list>
#include <utility>
#include <iostream>

using T = std::list<int>;
using namespace std;

int main(void)
{
    T t1{1, 2, 3, 4};
    T t2{5, 6, 7, 8};
    cout << "Inital: " << endl;
    cout << "t1: "; for (auto x : t1) cout << " " << x; cout << endl;
    cout << "t2: "; for (auto x : t2) cout << " " << x; cout << endl;

    t1.swap(t2);
    cout << "\nAfter member swap:" << endl;
    cout << "t1: "; for (auto x : t1) cout << " " << x; cout << endl;
    cout << "t2: "; for (auto x : t2) cout << " " << x; cout << endl;

    swap(t1, t2);
    cout << "\nAfter non-member swap:" << endl;
    cout << "t1: "; for (auto x : t1) cout << " " << x; cout << endl;
    cout << "t2: "; for (auto x : t2) cout << " " << x; cout << endl;

    std::swap(t1, t2);
    cout << "\nAfter std::swap:" << endl;
    cout << "t1: "; for (auto x : t1) cout << " " << x; cout << endl;
    cout << "t2: "; for (auto x : t2) cout << " " << x; cout << endl;

    return 0;
}
