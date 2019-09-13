// matrix.cpp - matrix

#include "matrix.hpp"
#include <iostream>
using namespace std;
template<class T>
void test_multi(const T &a, const T&b)
{
    cout << a << "*" << b << "=" << (a * b) << endl;
}

template<class T>
void test_add(const T &a, const T &b)
{
    cout << a << "+" << b << "=" << (a + b) << endl;
}

int main(void)
{
    test_add(complex(1.1, 2.1), complex(1.2, 2.2));
    test_multi(complex(1.1, 2.1), complex(1.2, 2.2));
    test_add(triple(1.1, 2.1, 3.1), triple(1.2, 2.2, 3.2));
    test_multi(triple(1.1, 2.1, 3.1), triple(1.2, 2.2, 3.2));

    vector<triple> t1;
    t1.push_back(triple(1.1, 2.1, 3.1));
    t1.push_back(triple(1.2, 2.2, 3.2));
    matrix<triple> a(t1);

    vector<triple> t2;
    t2.push_back(triple(1.3, 2.3, 3.3));
    t2.push_back(triple(1.4, 2.4, 3.4));
    t2.push_back(triple(1.5, 2.5, 3.5));
    matrix<triple> b(t2);

    vector<complex> t3;
    t3.push_back(complex(1.1, 2.1));
    t3.push_back(complex(1.2, 2.2));
    matrix<complex>c(t3);

    vector<complex> t4;
    t4.push_back(complex(1.3, 2.3));
    t4.push_back(complex(1.4, 2.4));
    t4.push_back(complex(1.5, 2.5));
    matrix<complex>d(t4);

    test_add(a, b);
    test_multi(a,b);

    test_add(c, d);
    test_multi(c,d);
    return 0;
}
