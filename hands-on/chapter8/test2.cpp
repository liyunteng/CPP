// test2.cpp - test2

// Date   : 2020/12/09
#include <iostream>

template<typename T>
class Registry
{
public:
    static size_t count;
    static T *head;
    T *prev;
    T *next;

protected:
    Registry()
    {
        ++count;
        prev = nullptr;
        next = head;
        head = static_cast<T *>(this);
        if (next) {
            next->prev = head;
        }
    }

    Registry(const Registry &)
    {
        ++count;
        prev = nullptr;
        next = head;
        head = static_cast<T *>(this);
        if (next) {
            next->prev = head;
        }
    }
    ~Registry()
    {
        --count;
        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;
        if (head == this)
            head = next;
    }
};

template<typename T>
size_t Registry<T>::count(0);
template<typename T>
T *Registry<T>::head(nullptr);

class C : public Registry<C>
{
    int i_;

public:
    C(int i) : i_(i) {}
    friend std::ostream &operator<<(std::ostream &out, const C &c)
    {
        out << c.i_;
        return out;
    }
};

class D : public Registry<D>
{
    int i_;

public:
    D(int i) : i_(i) {}
    friend std::ostream &operator<<(std::ostream &out, const D &c)
    {
        out << c.i_;
        return out;
    }
};

template<typename T>
void
report()
{
    std::cout << "Count: " << T::count;
    for (const T *p = T::head; p; p = p->next) {
        std::cout << " " << *p;
    }
    std::cout << std::endl;
}

int main(void)
{
    report<C>();
    C* c4 = nullptr;
    {
        C c1(1);
        report<C>();
        c4 = new C(4);
        C c2(2);
        D d1(10);
        report<C>();
        report<D>();
    }

    report<C>();
    C c3(3);
    report<C>();
    delete c4;
    report<C>();
    report<D>();
    return 0;
}
