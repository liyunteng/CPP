// matrix.hpp - matrix

#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <array>
#include <iostream>
#include <vector>

template<class T, int N>
class base
{
    friend std::ostream &operator<<(std::ostream &o, const base<T, N> &a)
    {
        o << "(";
        for (auto i : a.m_v) {
            o << i << ",";
        }
        o << '\b' << ")";
        return o;
    }

public:
    base()  = default;
    ~base() = default;
    base(std::array<T, N> v) : m_v(v) {}
    base<T, N> operator+(const base<T, N> &a) const
    {
        base<T, N> r;
        for (int i = 0; i < N; i++) {
            r.m_v[i] = this->m_v[i] + a.m_v[i];
        }
        return r;
    }

    base<T, N> operator*(const base<T, N> &a) const
    {
        base<T, N> r;
        for (int i = 0; i < N; i++) {
            r.m_v[i] = this->m_v[i] * a.m_v[i];
        }
        return r;
    }

public:
    std::array<T, N> m_v;
};

class complex : public base<float, 2>
{
    friend std::ostream &operator<<(std::ostream &o, const complex &a)
    {
        o << "(" << a.m_v[0] << (a.m_v[1] > 0 ? "+" : "-")
          << (a.m_v[1] > 0 ? a.m_v[1] : -a.m_v[1]) << "i"
          << ")";
        return o;
    }

public:
    ~complex() = default;
    complex(float r, float v)
    {
        m_v[0] = r;
        m_v[1] = v;
    }
    complex(const base<float, 2> &a)
    {
        m_v[0] = a.m_v[0];
        m_v[1] = a.m_v[1];
    }

    complex operator*(const complex &a) const
    {
        complex r{0, 0};
        r.m_v[0] = this->m_v[0] * a.m_v[0] - this->m_v[1] * a.m_v[1];
        r.m_v[1] = this->m_v[1] * a.m_v[0] + this->m_v[0] * a.m_v[1];
        return r;
    }
};

class triple : public base<float, 3>
{
public:
    ~triple() = default;
    triple(float v0, float v1, float v2)
    {
        m_v[0] = v0;
        m_v[1] = v1;
        m_v[2] = v2;
    }
    triple(const base<float, 3> &a)
    {
        m_v[0] = a.m_v[0];
        m_v[1] = a.m_v[1];
        m_v[2] = a.m_v[2];
    }
};

template<class T>
class matrix
{
    friend std::ostream &operator<<(std::ostream &o, const matrix<T> &a)
    {
        for (auto iter : a.m_vec) {
            o << iter;
        }
        return o;
    }

public:
    matrix()  = default;
    ~matrix() = default;
    matrix(std::vector<T> v) : m_vec(v) {}

    matrix<T> operator+(const matrix<T> &a) const
    {
        matrix<T> r;
        auto iter1 = this->m_vec.begin();
        auto iter2 = a.m_vec.begin();
        for (; iter1 != this->m_vec.end() && iter2 != a.m_vec.end();
             iter1++, iter2++) {
            r.m_vec.push_back(*iter1 + *iter2);
        }
        if (this->m_vec.size() >= a.m_vec.size()) {
            for (; iter1 != this->m_vec.end(); ++iter1) {
                r.m_vec.push_back(*iter1);
            }
        } else {
            for (; iter2 != a.m_vec.end(); iter2++) {
                r.m_vec.push_back(*iter2);
            }
        }
        return r;
    }
    matrix<T> operator*(const matrix<T> &a) const
    {
        matrix<T> r;
        auto iter1 = this->m_vec.begin();
        auto iter2 = a.m_vec.begin();
        for (; iter1 != this->m_vec.end() && iter2 != a.m_vec.end();
             iter1++, iter2++) {
            r.m_vec.push_back(*iter1 * *iter2);
        }
        if (this->m_vec.size() >= a.m_vec.size()) {
            for (; iter1 != this->m_vec.end(); ++iter1) {
                r.m_vec.push_back(*iter1);
            }
        } else {
            for (; iter2 != a.m_vec.end(); iter2++) {
                r.m_vec.push_back(*iter2);
            }
        }
        return r;
    }

private:
    std::vector<T> m_vec;
};

#endif
