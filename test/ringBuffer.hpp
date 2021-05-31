/*
 * ringBuffer.hpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/19 15:17:38
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP
#include <cstdlib>
#include <exception>
// #define NDEBUG
#include <iostream>

template<typename T>
class ringBuffer
{
private:
    size_t m_size;
    T *m_data;
    size_t m_front;
    size_t m_rear;

public:
    explicit ringBuffer(size_t n);
    virtual ~ringBuffer();

    bool isEmpty();
    bool isFull();
    size_t size();
    void push(const T &t);
    T pop();
};

template<typename T>
ringBuffer<T>::ringBuffer(size_t n) : m_size(n + 1), m_front(0), m_rear(0)
{
    m_data = new T[m_size];
}

template<typename T>
ringBuffer<T>::~ringBuffer()
{
    if (m_data) {
#ifndef NDEBUG
        std::cout << "delete..." << std::endl;
#endif
        delete[] m_data;
    }
}

template<typename T>
bool
ringBuffer<T>::isEmpty()
{
    return m_front == m_rear % m_size;
}

template<typename T>
bool
ringBuffer<T>::isFull()
{
    return m_front == (m_rear + 1) % m_size;
}

template<typename T>
void
ringBuffer<T>::push(const T &t) 
{
    if (isFull()) {
#ifndef NDEBUG
        std::cout << "ringBuffer is full" << std::endl;
        throw std::logic_error("is Full");
#endif
        return;
    }

    m_data[m_rear] = t;
    m_rear         = (m_rear + 1) % m_size;
}

template<typename T>
T
ringBuffer<T>::pop() 
{
    if (isEmpty()) {
#ifndef NDEBUG
        std::cout << "ringBuffer is Empty" << std::endl;
        throw std::logic_error("is Empty");
#endif
        T t;
        return t;
    }
    T tmp   = m_data[m_front];
    m_front = (m_front + 1) % m_size;
    return tmp;
}

template<typename T>
size_t
ringBuffer<T>::size()
{
    return m_size - 1;
}

#endif
