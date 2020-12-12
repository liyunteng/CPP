// search.cpp - search

// Date   : 2020/12/12
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

bool twice(int elem1, int elem2)
{
    return 2 * elem1 == elem2;
}

int main(void)
{
    using namespace std;
    vector<int> v1, v2;
    list<int> l1;

    int i;
    for (i = 0; i <= 5; i++)
        v1.push_back(5 * i);
    for (i = 0; i <= 5; i++)
        v1.push_back(5 * i);

    for (i = 4; i<= 5; i++)
        l1.push_back(5 * i);

    for (i = 2; i <= 4; i++)
        v2.push_back(10 * i);


    cout << "v1 = (";
    for (auto x : v1)
        cout << x << " ";
    cout << ")" <<endl;

    cout << "l1 = (";
    for (auto x : l1)
        cout << x << " ";
    cout << ")" <<endl;

    cout << "v2 = (";
    for (auto x : v2)
        cout << x << " ";
    cout << ")" <<endl;

    auto result = search(v1.begin(), v1.end(), l1.begin(), l1.end());
    if (result == v1.end()) {
        cout << "There is no match of l1 in v1" << endl;
    } else {
        cout << "There is at least one match of l1 in v1\n"
             << "and the first one begins at position "
             << result - v1.begin() << endl;
    }

    result = search(v1.begin(), v1.end(), v2.begin(), v2.end(), twice);
    if (result == v1.end()) {
        cout << "There is no match v2 in v1" << endl;
    } else {
        cout << "There is a sequence of elements in v1 that "
             << "are equivalent\n to those in v2 under the binary "
             << "predicate twice\n and the first on begins at postions "
             << result - v1.begin()<< endl;
    }

    return 0;
}
