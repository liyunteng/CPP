/*
 * silently_write_and_call.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/20 04:05:18
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

#include <string>
#include <iostream>


class Empty {
};
// 由编译器默认生成
// class Empty
// {
// public:
//     Empty() {...}                  // default ct
//     Empty(const Empty& rhs) {...}  // copy ct
//     ~Empty() {...}                 // dt

//     Empty &operator=(const Empty& rhs){...} // copy assignment
// };


template < typename T > class NamedObject {
  public:
    NamedObject(const char *name, const T & value)
  :	nameValue(name), objectValue(value) {
    }
    NamedObject(const std::string & name, const T & value)
    :nameValue(name), objectValue(value) {
    }
    NamedObject(NamedObject < T > &rhs) {
	std::cout << "in copy ct" << std::endl;
	nameValue = rhs.nameValue;
	objectValue = rhs.objectValue;
    }
    virtual ~ NamedObject() {
    }

  private:
    std::string nameValue;
    T objectValue;
};

template < typename T > class NamedObjectR;
template < typename T > std::ostream & operator<<(std::ostream & os,
						  const NamedObjectR < T >
						  &rhs);
template < typename D > std::ostream & myShow(std::ostream & os,
					      const D & d);

template < typename T > class NamedObjectR {
  public:
    // cant' use const std:string &name
    NamedObjectR(std::string & name, const T & value)
    :nameValue(name), objectValue(value) {
    }
    ~NamedObjectR() {
    }

    std::string & name()const {
	return nameValue;
    } bool operator==(const NamedObjectR < T > &rhs) {
	return nameValue == rhs.nameValue
	    && objectValue == rhs.objectValue;
    }
    NamedObjectR < T > &operator=(const NamedObjectR < T > &rhs) {
	if (*this == rhs)
	    return *this;
	nameValue = rhs.nameValue;
	return *this;
    }

    // friend std::ostream &operator<<(std::ostream &os, const NamedObjectR<int> &rhs); // not template
    friend std::ostream & operator<< < T > (std::ostream & os, const NamedObjectR < T > &rhs);	// template bounded
    template < typename B > friend std::ostream & myShow(std::ostream & os, const B & b);	// tesmplate unbounded
  private:
    std::string & nameValue;
    const T objectValue;
};

// std::ostream &operator<<(std::ostream &os, const NamedObjectR<int> &rhs)
// {
//     os << "not template " << "name: " << rhs.nameValue << " value: " << rhs.objectValue << std::endl;
//     return os;
// }

template < typename T >
    std::ostream & operator<<(std::ostream & os,
			      const NamedObjectR < T > &rhs)
{
    os << "template bounded " << "name: " << rhs.
	nameValue << " value: " << rhs.objectValue << std::endl;
    return os;
}

template < typename B >
    std::ostream & myShow(std::ostream & os, const B & rhs)
{
    os << "template unbunded " << "name: " << rhs.
	nameValue << " value: " << rhs.objectValue << std::endl;
    return os;
}


int main(void)
{

    Empty e1;			// default ct
    Empty e2(e1);		// copy ct
    e2 = e1;			// copy assignment


    NamedObject < int >no1("Smallest Prime Number", 2);
    NamedObject < int >no2(no1);	// copy ct

    std::string name1 = "abc";
    std::string name2 = "xyz";
    NamedObjectR < int >n1(name1, 1);
    NamedObjectR < int >n2(name2, 2);

    myShow(std::cout, n1);
    name1 = "this is a test";
    std::cout << n1;
    myShow(std::cout, n1);
    std::cout << n1;

    // n1 = n2;                    // default operator= cant' change const, and
    // can't used for reference

    n1 = n2;			// use my operator=

    myShow(std::cout, n1);
    std::cout << n1;

    return 0;
}
