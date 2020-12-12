// generate.cpp - generate

// Date   : 2020/12/12
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ostream>

int main(void)
{
    using namespace std;

    vector<int> v1(5);
    deque<int> d1(5);

    generate(v1.begin(), v1.end(), rand);

    cout << "v1 = (";
    for (auto x: v1)
        cout << x << " ";
    cout << ")" << endl;

    generate(d1.begin(), d1.end(), rand);
    cout << "d1 = (";
    for (auto x: v1)
        cout << x << " ";
    cout << ")" << endl;

    return 0;
}
