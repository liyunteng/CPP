// count_if.cpp - count_if

// Date   : 2020/12/11
#include <vector>
#include <algorithm>
#include <iostream>

bool greater10(int value)
{
    return value > 10;
}

int main(void)
{
    using namespace std;

    vector<int> v1 { 10, 20, 10, 40, 10};
    cout << "v1 = (";
    for (auto x: v1) {
        cout << x << " ";
    }
    cout << ")" << endl;

    // vector<int>::iterator::difference_type;
    auto result = count_if(v1.begin(), v1.end(), greater10);
    cout << "The number of greater than 10 in v2 is: " << result << "." << endl;

    return 0;
}
