// all_of.cpp - all_of

// Date   : 2020/12/11
#include <algorithm>
#include <iostream>
#include <list>

int
main(void)
{
    using namespace std;

    list<int> L{50, 40, 10, 20, 20};

    cout << "L = (";
    for (auto x : L) {
        cout << x << " ";
    }
    cout << ")" << endl;


    auto is_even = [](int elem){return !(elem % 2);};
    if (all_of(L.begin(), L.end(), is_even)) {
        cout << "All the elments are even numbers." << endl;
    } else {
        cout << "Not all the elments are even numbers." << endl;
    }
    return 0;
}
