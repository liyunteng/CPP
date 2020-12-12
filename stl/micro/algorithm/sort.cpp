// sort.cpp - sort

// Date   : 2020/12/12
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

bool UDgreater(int v1, int v2)
{
    return v1 > v2;
}

int main(void)
{
    using namespace std;
    vector<int> v1;
    int i;
    for (i = 0; i<= 5; i++)
        v1.push_back(2 * i);

    for (i = 0; i <= 5; i++)
        v1.push_back(2 * i + 1);

    cout << "v1 = (";
    for (auto x : v1)
        cout << x << " ";
    cout << ")" << endl;

    sort(v1.begin(), v1.end());
    cout << "after sort v1 = (";
    for (auto x : v1)
        cout << x << " ";
    cout << ")" << endl;

    sort(v1.begin(), v1.end(), greater<int>());
    cout << "after sort greater<int> v1 = (";
    for (auto x : v1)
        cout << x << " ";
    cout << ")" << endl;

    sort(v1.begin(), v1.end(), UDgreater);
    cout << "after sort UDgreater v1 = (";
    for (auto x : v1)
        cout << x << " ";
    cout << ")" << endl;

    return 0;
}
