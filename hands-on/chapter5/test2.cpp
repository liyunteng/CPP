// test2.cpp - test2

// Date   : 2020/12/09

#include <iostream>

template<typename T>
class scoped_ptr
{
public:
    explicit scoped_ptr(T *p) : p_(p) {}
    ~scoped_ptr() { delete p_; }

    T *operator->() { return p_; }
    const T *operator->() const { return p_; }
    T &operator*() { return *p_; }
    const T &operator*() const { return *p_; }

    void reset(T* p = nullptr)
    {
        delete p_;
        p_ = p;
    }

private:
    T *p_;
    // copy
    scoped_ptr(const scoped_ptr &) = delete;
    // copy assign
    scoped_ptr &operator=(const scoped_ptr &) = delete;
};

struct object_counter {
    static int count;
    static int all_count;
    object_counter()
    {
        ++count;
        ++all_count;
    }
    ~object_counter() { --count; }
};

int object_counter::count = 0;
int object_counter::all_count = 0;

class A
{
public:
    A(object_counter *p) : p_(p) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

private:
    scoped_ptr<object_counter> p_;
};

int
main(void)
{
    {
        A a(new object_counter);
        std::cout << object_counter::count << " " << object_counter::all_count << std::endl;
    }
    std::cout << object_counter::count << " " << object_counter::all_count << std::endl;

    {
        scoped_ptr<object_counter> a(new object_counter);
        std::cout << object_counter::count << " " << object_counter::all_count << std::endl;
        a.reset(new object_counter);
        std::cout << object_counter::count << " " << object_counter::all_count << std::endl;
    }
    std::cout << object_counter::count << " " << object_counter::all_count << std::endl;


    return 0;
}
