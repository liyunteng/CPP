// any_of.cpp - any_of

// Date   : 2020/12/11
#include <list>
#include <algorithm>
#include <iostream>

int main(void)
{
    using namespace std;

    list<int> L { 51, 41, 11, 21, 20 };

    cout << "L = (";
    for (auto const& x: L) {
        cout << x << " ";
    }
    cout << ")" << endl;


    auto is_even = [](int const elem) { return !(elem % 2); };
    if (any_of(L.begin(), L.end(), is_even)) {
        cout << "There's an even element in L" << endl;
    } else {
        cout << "There's are no even element in L" << endl;
    }
    return 0;
}
