// -*- compile-command: "clang++ -Wall -o 35non-virtual 35non-virtual.cpp -g
// -std=c++11" -*- 35non-virtual.cpp --

// Copyright (C) 2017 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2017/01/03 01:11:35

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

#include <functional>
#include <iostream>

using namespace std;

////////// NVI //////////
class GameCharacter
{
public:
    explicit GameCharacter(int data) : m_data(data) {}
    ~GameCharacter() {}

    int healthValue() const
    {
        // ...
        cout << "before healthValue" << endl;
        int retVal = doHealthValue();
        cout << "after healthValue" << endl;
        // ...
        return retVal;
    }

private:
    // NVI non-virtual interface
    virtual int doHealthValue() const
    {
        // ...
        cout << "Base data:" << m_data << endl;
        return m_data;
    }
    int m_data;
};

class GamePeople : public GameCharacter
{
public:
    explicit GamePeople(int data) : GameCharacter(data), m_data(data) {}
    ~GamePeople() {}

private:
    virtual int doHealthValue() const
    {
        cout << "derived data:" << m_data + 1 << endl;
        return m_data + 1;
    }
    int m_data;
};

////////// function pointer //////////
class Base;
int
defaultHealthCalc(const Base &)
{
    cout << __func__ << endl;
    return 0;
}
class Base
{
public:
    // function pointer
    // typedef int(*HealthCalcFunc)(const Base&);
    typedef std::function<int(const Base &)> HealthCalcFunc;
    explicit Base(HealthCalcFunc hcf = defaultHealthCalc) : healthFunc(hcf) {}
    ~Base() {}

    int healthValue() const { return healthFunc(*this); }

private:
    HealthCalcFunc healthFunc;
};

class Derived : public Base
{
public:
    explicit Derived(HealthCalcFunc hcf = defaultHealthCalc) : Base(hcf) {}
    ~Derived() {}
};

int
loseHealthQuickly(const Base &)
{
    cout << __func__ << endl;
    return 1;
}

int
loseHealthSlowly(const Base &)
{
    cout << __func__ << endl;
    return 2;
}

short
calcHealth(const Base &)
{
    cout << __func__ << endl;
    return 3;
}

struct HealthCalculator {
    int operator()(const Base &) const
    {
        cout << __func__ << endl;
        return 4;
    }
};

class GameLevel
{
public:
    explicit GameLevel(int l) : m_level(l) {}
    ~GameLevel() {}
    float health(const Base &) const
    {
        cout << __func__ << endl;
        return m_level;
    }

private:
    int m_level;
};

////////// strategy //////////
class Character;
class HealthCalc
{
public:
    HealthCalc() {}
    ~HealthCalc() {}

    virtual int calc(const Character &) const
    {
        cout << __func__ << endl;
        return 5;
    }
};

class DefaultCalc : public HealthCalc
{
public:
    DefaultCalc() : HealthCalc() {}
    ~DefaultCalc() {}
    virtual int calc(const Character &) const
    {
        cout << __func__ << endl;
        return 6;
    }
};

DefaultCalc defaultCalc;
class Character
{
public:
    explicit Character(HealthCalc *pf = &defaultCalc) : pCalc(pf) {}
    ~Character() {}

    virtual int healthValue() const { return pCalc->calc(*this); }

private:
    HealthCalc *pCalc;
};

int
main(void)
{
    GameCharacter *g = new GamePeople(1);
    // GameCharacter *g = new GameCharacter(1);
    g->healthValue();

    Derived d1(loseHealthQuickly);
    Derived d2(loseHealthSlowly);
    Derived d3;
    Derived d4(calcHealth);
    HealthCalculator c;
    Derived d5(c);
    GameLevel currentLevel(11);
    Derived d6(
        std::bind(&GameLevel::health, currentLevel, std::placeholders::_1));

    cout << d1.healthValue() << endl;
    cout << d2.healthValue() << endl;
    cout << d3.healthValue() << endl;
    cout << d4.healthValue() << endl;
    cout << d5.healthValue() << endl;
    cout << d6.healthValue() << endl;

    Character *cr = new Character;
    cout << cr->healthValue() << endl;
    return 0;
}
