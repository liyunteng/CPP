// copy_if.cpp - copy_if

// Date   : 2020/12/11
#include <list>
#include <algorithm>
#include <iostream>

void listlist(std::list<int> l)
{
    std::cout << "( ";
    for (auto const&x : l)
        std::cout << x << " ";

    std::cout << ")" << std::endl;
}

int main(void)
{
    using namespace std;
    list<int> L{46, 59, 88, 72, 79, 71, 60, 5, 40, 84};
    list<int> LE(L.size());
    list<int> LO(L.size());

    cout << " L =";
    listlist(L);

    auto is_even = [](int const elem) { return !(elem % 2);};
    auto ec = copy_if(L.begin(), L.end(), LE.begin(), is_even);
    LE.resize(std::distance(LE.begin(), ec));

    cout << "Even numbers are LE = ";
    listlist(LE);


    auto is_odd = [](int const elem) {return (elem % 2);};
    auto oc = copy_if(L.begin(), L.end(), LO.begin(), is_odd);
    LO.resize(std::distance(LO.begin(), oc));

    cout << "Odd numbers are LO = ";
    listlist(LO);

    return 0;
}
