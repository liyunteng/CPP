// matrix.cpp - matrix
// Build: g++ -o matrix matrix.cpp -g -Wall
// Author: liyunteng<li_yunteng@163.com> 18510547821

#include "matrix.hpp"
#include <iostream>
using namespace std;
template<class T>
void
test_multi(const T &a, const T &b)
{
    T r = a * b;
    cout << a << "*" << b << "=" << r << endl;
}

template<class T>
void
test_add(const T &a, const T &b)
{
    T r = a + b;
    cout << a << "+" << b << "=" << r << endl;
}

int
main(void)
{
    test_add(complex(1.1, -2.1), complex(1.2, -2.1));
    test_multi(complex(1.1, -2.1), complex(1.1, -2.1));
    test_add(triple(1.1, 2.1, 3.1), triple(1.2, 2.2, 3.2));
    test_multi(triple(1.1, 2.1, 3.1), triple(1.2, 2.2, 3.2));

    vector<triple> t1;
    t1.push_back(triple(1.1, 2.1, 3.1));
    t1.push_back(triple(1.2, 2.2, 3.2));
    matrix<triple> mt1(t1);

    vector<triple> t2;
    t2.push_back(triple(1.3, 2.3, 3.3));
    t2.push_back(triple(1.4, 2.4, 3.4));
    matrix<triple> mt2(t2);

    vector<complex> t3;
    t3.push_back(complex(1.1, 2.1));
    t3.push_back(complex(1.2, 2.2));
    matrix<complex> mc1(t3);

    vector<complex> t4;
    t4.push_back(complex(1.3, 2.3));
    t4.push_back(complex(1.4, 2.4));
    matrix<complex> mc2(t4);

    test_add(mc1, mc2);
    test_multi(mc1, mc2);

    test_add(mt1, mt2);
    test_multi(mt1, mt2);
    return 0;
}
