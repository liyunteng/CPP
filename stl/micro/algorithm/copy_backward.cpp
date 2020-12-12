// copy_backward.cpp - copy_backward

// Date   : 2020/12/11
#include <vector>
#include <algorithm>
#include <iostream>

int main(void)
{
    using namespace std;

    vector<int> v1, v2;

    int i;
    for (i = 0; i <= 5; i++)
        v1.push_back(10 * i);

    for (i = 0; i <= 10; i++)
        v2.push_back(3 * i);

    cout << "v1 = (";
    for (auto const&x: v1) {
        cout << x << " ";
    }
    cout << ")" << endl;

    cout << "v2 = (";
    for (auto const&x: v2) {
        cout << x << " ";
    }
    cout << ")" << endl;

    copy_backward(v1.begin(), v1.begin()+3, v2.begin() + 7);
    cout << "v2 with v1 insert = (";
    for (auto const&x: v2) {
        cout << x << " ";
    }
    cout << ")" << endl;

    copy_backward(v2.begin()+4, v2.begin()+7, v2.begin()+9);
    cout << "v2 with shifted insert = (";
    for (auto const&x: v2) {
        cout << x << " ";
    }
    cout << ")" << endl;

    return 0;
}
