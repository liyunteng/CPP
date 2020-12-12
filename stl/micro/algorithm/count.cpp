// count.cpp - count

// Date   : 2020/12/11
#include <vector>
#include <algorithm>
#include <iostream>

int main(void)
{
    using namespace std;

    vector<int>v1{10, 20, 10, 40, 10};
    cout << "v1 = (";
    for (auto x: v1) {
        cout << x << " ";
    }
    cout << ")" << endl;

    // vector<int>::iterator::difference_type;
    auto result = count(v1.begin(), v1.end(), 10);
    cout << "The number of 10s in v2 is: " << result << "." << endl;

    return 0;
}
