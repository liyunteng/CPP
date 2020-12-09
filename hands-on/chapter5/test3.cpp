// test3.cpp - test3

// Date   : 2020/12/09

#include <cstdlib>
#include <mutex>

class mutex_guard {
public:
    explicit mutex_guard(std::mutex &m) : _m(m), _must_unlock(true) {m.lock();}
    ~mutex_guard() {
        if (_must_unlock) {
            _m.unlock();
        }
    }
    void reset() {
        _m.unlock();
        _must_unlock = false;
    }
private:
    std::mutex& _m;
    bool _must_unlock;
};

std::mutex m;
int main(void)
{
    {
        mutex_guard lg(m);
    }
    {
        mutex_guard lg(m);
    }
    return 0;
}
