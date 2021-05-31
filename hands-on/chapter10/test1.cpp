// test1.cpp - test1

// Date   : 2020/12/09

#include <iostream>
#include <cstring>

class small_string
{
public:
    small_string() { memset(&b_, 0, sizeof(b_)); }

    explicit small_string(const char *s)
    {
        if (strlen(s) + 1 < sizeof(b_.buf)) {
            strncpy(b_.buf, s, sizeof(b_.buf));
            b_.tag = 0;
            ;
        } else {
            s_     = strdup(s);
            b_.tag = 1;
        }
    }
    small_string(const small_string &s)
    {
        if (s.b_.tag == 0) {
            b_ = s.b_;
        } else {
            s_     = strdup(s.s_);
            b_.tag = 1;
        }
    }

    small_string &operator=(const char *s)
    {
        if (b_.tag == 1) {
            free(s_);
        }
        if (strlen(s) + 1 < sizeof(b_.buf)) {
            strncpy(b_.buf, s, sizeof(b_.buf));
            b_.tag = 0;
        } else {
            s_     = strdup(s);
            b_.tag = 1;
        }
        return *this;
    }
    small_string &operator=(const small_string &s)
    {
        if (b_.tag == 1)
            free(s_);
        if (s.b_.tag == 0) {
            b_ = s.b_;
        } else {
            s_     = strdup(s.s_);
            b_.tag = 1;
        }
        return *this;
    }

    bool operator==(const small_string &rhs) const
    {
        const char *s1 = (b_.tag == 0) ? b_.buf : s_;
        const char *s2 = (rhs.b_.tag == 0) ? rhs.b_.buf : rhs.s_;
        return strcmp(s1, s2) == 0;
    }

    ~small_string()
    {
        if (b_.tag == 1)
            free(s_);
    }

private:
    union {
        char *s_;
        struct {
            char buf[15];
            char tag;
        } b_;
    };
};


int main(void)
{
    const char *s = "simple string";
    for (int i = 0; i < 100000000; i++) {
        small_string v(s);
    }
    return 0;
}
