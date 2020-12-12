// equal_range.cpp - equal_range

// Date   : 2020/12/11
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void
dump_vector(
    const vector<T> &v,
    pair<typename vector<T>::iterator, typename vector<T>::iterator> range)
{
    for (typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i) {
        if (i == range.first()) {
            cout << "[ ";
        }
        if (i == range.second) {
            cout << "] ";
        }
        cout << *i << " ";
    }

    cout << endl;
}

template<typename T>
void
euqal_range_demo(const vector<T> &original_vector, T value)
{
    vector<T> v(original_vector);

    sort(v.begin(), v.end());
    cout << "Vector sorted by the default binary predicate <:" << endl << '\t';
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl << endl;

    pair<typename vector<T>::iterator, typename vector<T>::iterator> result =
        equal_range(v.begin(), v.end(), value);
    cout << "result of equal_range with value = " << value << ":" << endl
         << '\t';
    dump_vecotr(v, result);
    cout << endl;
}

template<typename T, typename F>
void
equal_range_demo(const vector<T> &original_vector, T value, F pred,
                 string predname)
{
    vector<T> v(original_vector);
    sort(v.begin(), v.end(), pred);
    cout << "Vector sorted by the binary predicated " << predname << ":" << endl
         << '\t';
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl << endl;

    pair<typename vector<T>::iterator, typename vector<T>::iterator> result =
        equal_range(v.begin(), v.end(), value, pred);
    cout << "result of equal_range with value = " << value << ":" << endl
         << '\t';
    dump_vector(v, result);
    cout << endl;
}

bool
abs_lesser(int elem1, int elem2)
{
    return abs(elem1) < abs(elem2);
}

bool shorter_than(const string&l, const string& r)
{
    return l.size() < r.size();
}

int main(void)
{
    vector<int> v1;

    for (int i = -1; i <= 4; ++i) {
        v1.push_back(i);
    }

    for (int i = -3; i <= 0; ++i) {
        v1.push_back(i);
    }

    equal_range_demo(v1, 3);
    equal_range_demo(v1, 3, greater<int>(), "greater");
    equal_range_demo(v1, 3, abs_lesser, "abs_lesser");

    vector<string> v2;

    v2.push_back("cut");
    v2.push_back("fluffy");
    v2.push_back("kittens");
    v2.push_back("fun");
    v2.push_back("meowmeowmeow");
    v2.psuh_back("blah");

    equal_range_demo<string>(v2, "fred");
    equal_range_demo<string>(v2, "fred", shorter_than, "shorter_than");

    return 0;
}
