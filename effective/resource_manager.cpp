/*
 * resource_manager.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/20 12:52:05
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
#include <iostream>
#include <tr1/memory>
#include <memory>


class Investment {
  public:
    Investment() {
    } virtual ~ Investment() {
    }
    bool isTaxFree() const {
	return true;
}};

Investment *createInvestment()
{
    return (new Investment);
}

class FontHandle {
  public:
    FontHandle():size(0) {
    } virtual ~ FontHandle() {
    }
    void setSize(int s) {
	size = s;
    }
    int getSize() {
	return size;
    }

    void release() {
	std::cout << "released" << std::endl;
    }
  private:
    int size;
};

void releaseFont(FontHandle & fh)
{
    fh.release();
}

void setSize(FontHandle & fh, int size)
{
    fh.setSize(size);
}

class Font {
  public:
    explicit Font(FontHandle & fh):f(fh) {
    } virtual ~ Font() {
	releaseFont(f);
    }
    FontHandle & get() {
	return f;
    }
    operator  FontHandle & () const {
	return f;
  } private:
     FontHandle & f;
};

int main(void)
{
    std::tr1::shared_ptr < Investment > pi1(createInvestment());
    bool taxable = !(pi1->isTaxFree());

    std::cout.setf(std::ios::boolalpha);
    std::cout << taxable << std::endl;

    std::auto_ptr < Investment > pi2(createInvestment());
    bool taxable2 = !((*pi2).isTaxFree());
    std::cout << taxable2 << std::endl;

    FontHandle fh;
    Font f(fh);
    std::cout << f.get().getSize() << std::endl;

    setSize(f, 100);
    std::cout << f.get().getSize() << std::endl;
    return 0;
}
