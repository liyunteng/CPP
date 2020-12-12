// binary_search.cpp - binary_search

// Date   : 2020/12/11
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

bool mod_lesser(int elem1, int elem2)
{
    if (elem1 < 0) {
        elem1 = -elem1;
    }
    if (elem2 < 0) {
        elem2 = -elem2;
    }
    return elem1 < elem2;
}

int main(void)
{
    using namespace std;

    list<int> L{50, 10, 30, 20, 25, 5};
    L.sort();

    cout << "L = (";
    for (auto const&x : L) {
        cout << x << " ";
    }
    cout << ")" << endl;

    if (binary_search(L.begin(), L.end(), 10)) {
        cout << "There is a element in L with value 10." << endl;
    } else {
        cout << "There is no element in L with value 10." << endl;
    }

    L.sort(greater<int>());
    if (binary_search(L.begin(), L.end(), 10, greater<int>())) {
        cout << "There is an element in L with value greater than 10 "
             << "under greater<int>" << endl;
    } else {
        cout << "There is no element in L with value greater than 10 "
             << "under greater<int>" << endl;
    }


    vector<int> v1;

    for (auto i = -2; i <= 4; ++i) {
        v1.push_back(i);
    }

    sort(v1.begin(), v1.end(), mod_lesser);

    cout << "Ordered using mod_lesser, vector v1 = (";
    for (auto const &x: v1) {
        cout << x << " ";
    }
    cout << ")" << endl;


    if (binary_search(v1.begin(), v1.end(), -3, mod_lesser)) {
        cout << "There is an element with a value equaivalent to -3 "
             << "unser mode_lesser. " << endl;
    } else {
        cout << "There is no element with a value equaivalent to -3 "
             << "unser mode_lesser. " << endl;
    }
    return 0;
}
