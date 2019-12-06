/*
 * box.h - box
 *
 * Author : liyunteng <liyunteng@streamocean.com>
 * Date   : 2019/09/05
 *
 * Copyright (C) 2019 StreamOcean, Inc.
 * All rights reserved.
 */
#ifndef __BOX_HPP__
#define __BOX_HPP__

#include <iostream>
#include <utility>
using namespace std::rel_ops;

class Box
{
public:
    explicit Box(size_t l = 1, size_t w = 1, size_t h = 1) :
        length{l},
        width{w},
        height{h}
    {
    }

    double volume() const { return length * width * height; }
    bool operator<(const Box &box) const { return volume() < box.volume(); }
    bool operator==(const Box &box) const
    {
        return length == box.length && width == box.width
               && height == box.height;
    }

    friend std::istream &operator>>(std::istream &in, Box &box);
    friend std::ostream &operator<<(std::ostream &out, const Box &box);

private:
    size_t length{};
    size_t width{};
    size_t height{};
};

inline std::istream &
operator>>(std::istream &in, Box &box)
{
    std::cout << "Enter box length, width, height separated by space - Ctrl+Z "
                 "to end: ";
    size_t value;
    in >> value;
    if (in.eof())
        return in;

    box.length = value;
    in >> value;
    box.width = value;
    in >> value;
    box.height = value;
    return in;
}

inline std::ostream &
operator<<(std::ostream &out, const Box &box)
{
    out << "Box(" << box.length << "," << box.width << "," << box.height
        << ") ";
    return out;
}
#endif
