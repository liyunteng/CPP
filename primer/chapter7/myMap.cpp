// myMap.cpp -- test map

// Copyright (C) 2016 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2016/12/28 18:27:09

// This program is free software; you can redistribute it and/or modify
// it under the terms and conditions of the GNU General Public License
// version 2,as published by the Free Software Foundation.

// This program is distributed in the hope it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.

// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation,
// Inc.,51 Franklin St - Fifth Floor, Boston,MA 02110-1301 USA.

#include <iostream>
#include <string>
#include <typeinfo>
#include <map>
#include <unordered_map>
#include <functional>

using namespace std;

struct person
{
    string name;
    int age;

    person(string name, int age) {
        this->name = name;
        this->age = age;
    }
    // needed by map
    bool operator <(const person&p) const {
        return this->age < p.age;
    }
};

struct student
{
    string name;
    int age;
    student(string name, int age)
        {
            this->name = name;
            this->age = age;
        }
    // needed by unordered_map
    bool operator== (const student&p) const
        {
            return name==p.name && age == p.age;
        }
};

// needed by unordered_map
// template special
template<>
struct hash<student>
{
    size_t operator() (const student &p) const {
        std::hash<string> hname;
        std::hash<int> hage;
        return hname(p.name) + hage(p.age);
    }
};


int main(void)
{
    map<person, int> m;
    person p1("Tom1", 20);
    person p2("Tom2", 22);
    person p3("Tom3", 23);
    person p4("Tom4", 24);
    person p5("Tom5", 25);

    m.insert(make_pair(p3, 100));
    m.insert(make_pair(p4, 100));
    m.insert(make_pair(p5, 100));
    m.insert(make_pair(p1, 100));
    m.insert(make_pair(p2, 100));
    for (auto it : m) {
        cout << it.first.name << "\t" << it.first.age << endl;
    }

    cout << "unordered_map:" << endl;
    student s1("Joe1", 20);
    student s2("Joe2", 22);
    student s3("Joe3", 23);
    student s4("Joe4", 24);
    student s5("Joe1", 20);
    unordered_multimap<student, int> um;
    um.insert(make_pair(s3, 100));
    um.insert(make_pair(s4, 100));
    um.insert(make_pair(s5, 100));
    um.insert(make_pair(s1, 100));
    um.insert(make_pair(s2, 100));
    for (auto it : um) {
        cout << it.first.name << "\t" << it.first.age  << " bucket:"
             << um.bucket(it.first) << " bucket_size: "
             << um.bucket_size(um.bucket(it.first))<< endl;
    }
    cout << "bucket_count: " << um.bucket_count()
         << " max_bucekt_count: " << um.max_bucket_count() << endl;
    cout << "load_factor: " << um.load_factor()
         << " max_load_factor: " << um.max_load_factor() << endl;

    um.reserve(5);
    for (auto it : um) {
        cout << it.first.name << "\t" << it.first.age  << " bucket:"
             << um.bucket(it.first) << " bucket_size: "
             << um.bucket_size(um.bucket(it.first))<< endl;
    }
    cout << "bucket_count: " << um.bucket_count()
         << " max_bucekt_count: " << um.max_bucket_count() << endl;
    cout << "load_factor: " << um.load_factor()
         << " max_load_factor: " << um.max_load_factor() << endl;


    um.rehash(5);
    for (auto it : um) {
        cout << it.first.name << "\t" << it.first.age  << " bucket:"
             << um.bucket(it.first) << " bucket_size: "
             << um.bucket_size(um.bucket(it.first))<< endl;
    }
    cout << "bucket_count: " << um.bucket_count()
         << " max_bucekt_count: " << um.max_bucket_count() << endl;
    cout << "load_factor: " << um.load_factor()
         << " max_load_factor: " << um.max_load_factor() << endl;

    um.
    cout << __cplusplus << endl;
    return 0;
}
