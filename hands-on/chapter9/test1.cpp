// test1.cpp - test1

// Date   : 2020/12/09
#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class Collection
{
public:
    Collection() {}
    T filter()
    {
        cout << "Collection::filter" << endl;
        return *static_cast<T *>(this);
    }
    T sort() {
        cout << "Collection::sort" << endl;
        return T(*this);
    }
};

class SortedCollection: public Collection<SortedCollection> {
public:
    SortedCollection() {}
    SortedCollection(const Collection&) {}
    SortedCollection search() {
        cout << "SortedCollection::search" << endl;
        return *this;
    }
    SortedCollection median() {
        cout << "SortedCollection::median" << endl;
        return *this;
    }
};

int main(void)
{
    Collection<SortedCollection> c;
    c.sort().search().filter().median();
    return 0;
}
