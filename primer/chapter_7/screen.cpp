// screen.cpp - screen

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/06/27

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#include "screen.hpp"
#include <iostream>

using namespace lyt;

inline Screen &
Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor  = row + c;
    return *this;
}

inline Screen &
Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &
Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

char
Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

void
Screen::some_member() const
{
    ++access_ctr;
}

void
Window_mgr::clear(ScreenIndex i)
{
    Screen &s  = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}

int
main(void)
{
    Screen s(5, 3);
    const Screen blank(5, 3);
    s.move(0, 0).set('#');
    s.move(4, 2).set('*');
    s.display(std::cout).set('*');
    blank.display(std::cout);

    return 0;
}
