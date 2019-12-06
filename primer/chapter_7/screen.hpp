// screen.hpp - screen

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/06/27

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#ifndef SCREEN_HPP
#define SCREEN_HPP
#include <string>
#include <vector>

namespace lyt {
class Screen;

class Screen
{
public:
    // typedef std::string::size_type pos;
    using pos = std::string::size_type;
    Screen()  = default;
    Screen(pos ht, pos wd, char c = ' ') :
        height(ht),
        width(wd),
        contents(ht * wd, c)
    {
    }

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const;
    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream &os) const { os << contents; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    mutable size_t access_ctr;

    friend class Window_mgr;
    // friend void Window_mgr::clear(ScreenIndex);
};

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen &);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

}  // namespace lyt
#endif
