// fill_n.cpp - fill_n

// Date   : 2020/12/12
#include <vector>
#include <algorithm>
#include <iostream>

int main(void)
{
    using namespace std;
    vector<int> v;

    for (auto i = 0; i < 9; i++) {
        v.push_back(0);
    }

    cout << "vector v = (";
    for (const auto &x: v)
        cout << x << " ";
    cout << ")" << endl;

    auto pos = fill_n(v.begin(), 3, 1);

    cout << "modified v = (";
    for (const auto &x: v)
        cout << x << " ";
    cout << ")" << endl;

    fill_n(pos, 3, 2);
    cout << "modified v = (";
    for (const auto &x: v)
        cout << x << " ";
    cout << ")" << endl;

    fill_n(v.end()-3, 3, 3);
    cout << "modified v = (";
    for (const auto &x: v)
        cout << x << " ";
    cout << ")" << endl;

    return 0;
}
