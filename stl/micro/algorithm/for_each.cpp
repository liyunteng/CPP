// for_each.cpp - for_each

// Date   : 2020/12/12
#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
class MultValue
{
private:
    T Factor;
public:
    MultValue (const T&value) : Factor(value) {}

    void operator() (T& elem) const {
        elem *= Factor;
    }
};

class Average
{
private:
    long num;
    long sum;

public:
    Average() : num(0), sum(0) {}

    void operator() (int elem) {
        num++;
        sum += elem;
    }

    operator double(){
        return static_cast<double>(sum) /
            static_cast<double>(num);
    }
};

int main(void)
{
    using namespace std;
    vector<int> v1;

    int i;
    for (i = -4; i <= 2; i++) {
        v1.push_back(i);
    }

    cout << "Original vector v1 = (";
    for (auto x: v1)
        cout << x << " ";
    cout << ")" << endl;


    for_each(v1.begin(), v1.end(), MultValue<int>(-2));

    cout << "Multiplying the elements of the vector v1\n"
         << "by the factor -2 gives:\n v1mod1 = (";
    for(auto x : v1)
        cout << x << " ";
    cout << ")" << endl;


    for_each(v1.begin(), v1.end(), MultValue<int>(5));
    cout << "Multiplying the elements of the vector v1mod\n"
         << "by the factor 5 gives:\n v1mod2 = (";
    for (auto x : v1)
        cout << x <<  " ";
    cout << ")" << endl;

    double av = for_each(v1.begin(), v1.end(), Average());
    cout << "The average of the elements of v1 is:\n"
         << "Average(v1mod2) = " << av << endl;
    return 0;
}
