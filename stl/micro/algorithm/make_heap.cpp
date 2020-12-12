// make_heap.cpp - make_heap

// Date   : 2020/12/12
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

int main(void)
{
    using namespace std;
    vector<int>v1, v2;
    int i;
    for (i = 0; i <= 9; i++)
        v1.push_back(i);

    random_shuffle(v1.begin(), v1.end());

    cout << "v1 = (";
    for (auto x : v1)
        cout << x << " ";
    cout << ")" << endl;

    make_heap(v1.begin(), v1.end());
    cout << "after make_heap v1 = (";
    for (auto x : v1)
        cout << x << " ";
    cout << ")" << endl;

    make_heap(v1.begin(), v1.end(), greater<int>());
    cout << "after make_heap greater<int> v1 = (";
    for (auto x : v1)
        cout << x << " ";
    cout << ")" << endl;

    return 0;
}
