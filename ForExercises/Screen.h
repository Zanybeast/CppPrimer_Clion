//
// Created by carl on 2020/9/4.
//

#ifndef FOREXERCISES_SCREEN_H
#define FOREXERCISES_SCREEN_H

#include <string>
#include <iostream>

using namespace std;

class Screen {
public:
    //友元函数
    friend class Window_mgr;
    //类型别名
    typedef string::size_type pos;
    //构造函数
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {  }
    //成员函数
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);

    void some_member() const;
    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(ostream &os) {
        do_display(os); return *this;
    }
    const Screen &display(ostream &os) const {
        do_display(os); return *this;
    }

    pos size() const;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    mutable size_t access_ctr;

    void do_display(ostream &os) const { os << contents; }
};

Screen::pos Screen::size() const {
    return height * width;
}

void Screen::some_member() const {
    ++access_ctr;
}

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}
inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}
#endif //FOREXERCISES_SCREEN_H
