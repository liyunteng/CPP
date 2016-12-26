/*
 * non_member.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/20 14:45:25
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

class Rational {
  public:
    Rational(int numerator = 0, int denominator = 1)
  :	num(numerator), den(denominator) {
    } int numberator() const {
	return num;
    } int denominator() const {
	return den;
    } virtual ~ Rational() {
    }

  private:
    int num;
    int den;
};

const Rational operator*(const Rational & lhs, const Rational & rhs)
{
    return Rational(lhs.numberator() * rhs.numberator(),
		    lhs.denominator() * rhs.denominator());
}

int main(void)
{
    Rational a(1, 8);
    Rational b(1, 2);
    Rational result = a * b;
    result = result * b;
    result = a * 2;
    result = 2 * a;
    return 0;
}
