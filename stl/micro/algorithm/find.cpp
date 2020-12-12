// find.cpp - find

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
    for (i = 0; i<= 5; i++) {
        v1.push_back(5 * i);
    }
    for (i = 0; i <= 5; i++) {
        v1.push_back(5 * i);
    }

    for (i = 1; i <= 4; i++) {
        l1.push_back(5 * i);
    }
    for (i = 2; i<= 4; i++) {
        v2.push_back(10 * i);
    }

    cout << "vector v1 = (";
    for (auto x: v1)
        cout << x << " ";
    cout << ")" << endl;

    cout << "list l1 = (";
    for (auto x: l1)
        cout << x << " ";
    cout << ")" << endl;

    cout << "vector v2 = (";
    for (auto x: v2)
        cout << x << " ";
    cout << ")" << endl;

    auto result1 = find_end(v1.begin(), v1.end(), l1.begin(), l1.end());
    if (result1 == v1.end())
        cout << "There is no match of l1 in v1." << endl;
    else
        cout << "There is a match of l1 in v1 that begins at "
             << "position " << result1 - v1.begin() << "." << endl;


    auto result2 = find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), twice);
    if (result2 == v1.end())
        cout << "There is no match of l1 in v1." << endl;
    else
        cout << "There is a sequence of element in v1 that "
             << "are equaivalent to those\n in v2 under the binanry "
             << "predicate twice and that begins at postion "
             << result2 - v1.begin() << "." << endl;

    return 0;
}
