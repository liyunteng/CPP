// test1.cpp - test1

// Date   : 2020/12/09
#include <map>
#include <iostream>

using namespace std;

int main(void)
{
    map<int, string> m;
    m.insert(pair<int, string>(2, "fuck2"));
    m.insert(pair<int, string>(1, "fuck1"));
    m.insert(pair<int, string>(3, "fuck3"));
    for (auto x: m) {
        cout << x.first << ' ' << x.second << endl;
    }

    map<int, string, greater<>> m2;
    m2.insert(pair<int, string>(5, "fuck5"));
    m2.insert(pair<int, string>(6, "fuck6"));
    m2.insert(pair<int, string>(7, "fuck7"));
    for (auto x: m2) {
        cout << x.first << ' ' << x.second << endl;
    }

    // BUG: diffrent type
    // m.swap(m2);

    return 0;
}
