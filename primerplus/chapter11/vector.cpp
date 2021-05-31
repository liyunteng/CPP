/*
 * vector.cpp -- vector
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 00:48:59
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

#include "vector.hpp"
#include <cmath>

using namespace VECTOR;

const double Rad_to_deb = 45.0 / atan(1.0);

void
Vector::setMag()
{
    m_mag = sqrt(m_x * m_x + m_y * m_y);
}
void
Vector::setAng()
{
    if (m_x == 0.0 && m_y == 0.0)
        m_ang = 0.0;
    else
        m_ang = atan2(m_y, m_x);
}

void
Vector::setX()
{
    m_x = m_mag * cos(m_ang);
}

void
Vector::setY()
{
    m_y = m_mag * sin(m_ang);
}

Vector::Vector()
{
    m_x = m_y = m_ang = m_mag = 0.0;
    m_mode                    = RECT;
}

Vector::Vector(double n1, double n2, Mode form)
{
    m_mode = form;
    if (form == RECT) {
        m_x = n1;
        m_y = n2;
        setMag();
        setAng();
    } else if (form == POL) {
        m_mag = n1;
        m_ang = n2 / Rad_to_deb;
        setX();
        setY();
    } else {
        std::cout << "Incorrect 3rd argument to Vector() -- ";
        std::cout << "vector set to 0\n";
        m_x = m_y = m_mag = m_ang = 0.0;
        m_mode                    = RECT;
    }
}

void
Vector::reset(double n1, double n2, Mode form)
{
    m_mode = form;
    if (form == RECT) {
        m_x = n1;
        m_y = n2;
        setMag();
        setAng();
    } else if (form == POL) {
        m_mag = n1;
        m_ang = n2 / Rad_to_deb;
        setX();
        setY();
    } else {
        std::cout << "Incorrect 3rd argument to Vector() -- ";
        std::cout << "vector set to 0\n";
        m_x = m_y = m_mag = m_ang = 0.0;
        m_mode                    = RECT;
    }
}

Vector::~Vector() {}

void
Vector::polarMode()
{
    m_mode = POL;
}

void
Vector::rectMode()
{
    m_mode = RECT;
}

Vector
Vector::operator+(const Vector &v) const
{
    return Vector(m_x + v.m_x, m_y + v.m_y);
}
Vector
Vector::operator-(const Vector &v) const
{
    return Vector(m_x - v.m_x, m_y - v.m_y);
}
Vector
Vector::operator-() const
{
    return Vector(-m_x, -m_y);
}
Vector Vector::operator*(double n) const
{
    return Vector(m_x * n, m_y * n);
}

Vector operator*(double n, const Vector & v) {
    return v * n;
}  

std::ostream &
operator<<(std::ostream &os, const Vector &v)
{
    if (v.m_mode == Vector::RECT) {
        os << "(x,y) = (" << v.m_x << "," << v.m_y << ")";
    } else if (v.m_mode == Vector::POL) {
        os << "(m,a) = (" << v.m_mag << "," << v.m_ang << ")";
    } else {
        os << "Vector object mode is invalid";
    }
    return os;
}
