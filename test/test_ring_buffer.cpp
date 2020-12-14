// test_ring_buffer.cpp - test_ring_buffer

// Date   : 2020/12/14
#include "ring_buffer.hpp"
#include <iostream>

using namespace std;
int main(void)
{
    RingBuffer<int, 100> *r = new RingBuffer<int, 100>();

    cout << r->BufferSize() << endl;

    for (int i = 0; i < 10; i++) {
        r->SaveToBuffer(i);
    }
    cout << r->CurrentIndex() << endl;
    cout << boolalpha << r->IsFilledIndex(100) <<  endl;

    cout << "[";
    for (auto x = r->Begin(); x; ++x) {
        cout << **x << " ";
    }
    cout << "]" << endl;

    // for (auto i = 0; i < r->BufferSize(); i++) {
    //     *(r->MutableReadBuffer(i)) += 1000;
    // }

    cout << "[";
    for (int i = r->BufferSize()-1; i >= 0; i--) {
        if (r->IsFilledIndex(i)) {
            cout  << r->ReadBuffer(i) << " ";
        }
    }
    cout << "]" << endl;;
    r->Clear();
    return 0;
}
