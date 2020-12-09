// test1.cpp - test1

// Date   : 2020/12/09
#include <iostream>
using namespace std;

class CB;
class CA {
public:
    CA() {cout << __PRETTY_FUNCTION__ << endl;}
    ~CA() { cout << __PRETTY_FUNCTION__ << endl;}

    void set_ptr(shared_ptr<CB>& ptr) {m_ptr_b  = ptr;}
    void b_use_count() { cout << "b use count: " << m_ptr_b.use_count() << endl;}
    void show() { cout << "this is class CA!" << endl;}

private:
    shared_ptr<CB> m_ptr_b;
};

class CB {
public:
    CB() {cout << __PRETTY_FUNCTION__ << endl;}
    ~CB() {cout << __PRETTY_FUNCTION__ << endl;}
    void set_ptr(shared_ptr<CA>& ptr) {m_ptr_a = ptr;}
    void a_use_count() {cout << "a use count: " << m_ptr_a.use_count() << endl;}
    void show() { cout << "this is class CB!" << endl;}
private:
    // shared_ptr<CA> m_ptr_a;
    weak_ptr<CA> m_ptr_a;
};

int main(void)
{
    shared_ptr<CA> ptr_a(new CA());
    shared_ptr<CB> ptr_b(new CB());

    cout << "a use count: " << ptr_a.use_count() << endl;
    cout << "b use count: " << ptr_b.use_count() << endl;

    ptr_a->set_ptr(ptr_b);
    ptr_b->set_ptr(ptr_a);

    cout << "a use count: " << ptr_a.use_count() << endl;
    cout << "b use count: " << ptr_b.use_count() << endl;

    return 0;
}
