// fill.cpp - fill

// Date   : 2020/12/12
#include <vector>
#include <algorithm>
#include <iostream>

int main(void)
{
    using namespace std;
    vector<int> v1;

    int i;
    for (i = 0; i <= 9; i++) {
        v1.push_back(5 * i);
    }

    cout << "Vector v1 = (";
    for (auto x: v1) {
        cout << x << " ";
    }
    cout << ")" << endl;

    fill(v1.begin() + 5, v1.end(),2 );

    cout << "Vector v1 = (";
    for (auto x: v1) {
        cout << x << " ";
    }
    cout << ")" << endl;

    return 0;
}
