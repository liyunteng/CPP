/*
 * use_const.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/12/29 18:09:23
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
#include <string>
#include <vector>

class TextBlock
{
public:
    TextBlock(const std::string &t) : text(t) {}
    virtual ~TextBlock() {}

    const char &operator[](std::size_t position) const
    {
        return text[position];
    }
    // char &operator[](std::size_t position) {return text[position];}
    char &operator[](std::size_t position)
    {
        return const_cast<char &>(
            static_cast<const TextBlock>(*this)[position]);
    }

    std::string Text(std::string ns) const
    {
        text = ns;  // have const, but change text!!
        return text;
    }

private:
    mutable std::string text;  // mutable for Text(string)
};

void
print(const TextBlock &ctb)
{
    std::cout << ctb[0] << "\n";  // const TextBlock::operator[]
}

int
main(void)
{
    char greeting[]      = "Hello";
    char *p1             = greeting;  // non-const pointer, non-const data
    const char *p2       = greeting;  // non-const pointer, const data
    char *const p3       = greeting;  // const pointer, non-const data
    const char *const p4 = greeting;  // const pointer, const data

    char newstr[] = "World";

    p1[0] = 'H';
    p1    = newstr;

    // p2[0] = 'H';                // invalid
    p2 = newstr;

    p3[0] = 'H';
    // p3 = newstr;                // invalid

    // p4[0] = 'H';                // invalid
    // p4 = newstr;                // invalid
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "p3: " << p3 << std::endl;
    std::cout << "p4: " << p4 << std::endl;

    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    std::vector<int>::const_iterator cit;
    for (cit = vec.begin(); cit != vec.end(); ++cit) {
        std::cout << *cit << std::endl;
        // *cit = 8;               // invalid, cit lick const T*
    }
    const std::vector<int>::iterator it = vec.begin();
    *it                                 = 10;
    // ++it;                       // invalid, it lick T * const

    TextBlock tb("Hello");
    std::cout << tb[0] << std::endl;  // non-const
    // TextBlock::operator[]
    const TextBlock ctb("World");
    std::cout << ctb[0] << "\n";  // const TextBlock::opertor[]

    print(tb);
    print(ctb);

    tb[0] = 'x';
    // ctb[0] = 'x';               // invalid, const TextBlock

    tb.Text("abc");
    print(tb);
    return 0;
}
