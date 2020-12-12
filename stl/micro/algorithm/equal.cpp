// equal.cpp - equal

// Date   : 2020/12/11
#include <algorithm>
#include <iostream>
#include <vector>

int
main(void)
{
    using namespace std;
    vector<int> v1{0, 5, 10, 15, 20, 25};
    vector<int> v2{0, 5, 10, 15, 20, 25};
    vector<int> v3{0, 5, 10, 15, 20, 30, 35, 40, 45, 50};

    bool b = equal(v1.begin(), v1.end(), v2.begin());
    cout << "v1 and v2 are equal: " << b << endl;

    // WARN:
    b = equal(v1.begin(), v1.end(), v3.begin());
    cout << "v1 and v3 are queal: " << b << endl;

    b = equal(v1.begin(), v1.end(), v3.begin(), v3.end());
    cout << "v1 and v3 are queal with dual-range overlaod: " << b << endl;

    return 0;
}
