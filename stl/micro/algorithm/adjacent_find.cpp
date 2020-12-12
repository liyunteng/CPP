// adjacent_find.cpp - adjacent_find

// Date   : 2020/12/11

#include <list>
#include <algorithm>
#include <iostream>

bool twice(int elem1, int elem2)
{
    return elem1 * 2 == elem2;
}

int main(void)
{
    using namespace std;

    list<int> L{50, 40, 10, 20, 20};
    list<int>::iterator Iter;
    list<int>::iterator result1, result2;

    cout << "L = (";
    for (auto x : L) {
        cout << x << " ";
    }
    cout << ")" << endl;

    result1 = adjacent_find(L.begin(), L.end());
    if (result1 == L.end()) {
        cout << "There are not two adjacent elements that are equal" << endl;
    } else {
        cout << "There are two adjacent elements that are equal" << endl
             << "The have a value of "
             << *(result1)
             << "." << endl;
    }

    result2 = adjacent_find(L.begin(), L.end(), twice);
    if (result2 == L.end()) {
        cout << "There are not two adjacent elements where the "
             << "second is twice the first." << endl;
    } else {
        cout << "There are two adjacent elements where "
             << "the second is twice the first." << endl
             << "They have value of " << *(result2++)
             << " & " << *(result2) << "." << endl;
    }
    return 0;
}
