/*
 * vector.hpp -- vector
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 00:40:56
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

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

namespace VECTOR {
    class Vector {
      public:
	enum Mode { RECT, POL };

	 Vector();
	 Vector(double n1, double n2, Mode form = RECT);
	void reset(double n1, double n2, Mode form = RECT);
	~Vector();

      public:
	void polarMode();
	void rectMode();

	double xVal() const {
	    return m_x;
	} double yVal() const {
	    return m_y;
	} double magVal() const {
	    return m_mag;
	} double angVal() const {
	    return m_ang;
	}
	// operator Vector operator+(const Vector & v) const;
	Vector operator-(const Vector & v) const;
	Vector operator-() const;
	Vector operator*(double n) const;

	// friend
	friend Vector operator*(double n, const Vector & v);
	friend std::ostream & operator<<(std::ostream &, const Vector & v);

      private:
	void setMag();
	void setAng();
	void setX();
	void setY();

      private:
	double m_x;
	double m_y;
	double m_mag;
	double m_ang;
	Mode m_mode;

    };

}				// VECTOR
#endif
