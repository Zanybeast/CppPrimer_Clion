//
// Created by carl on 2020/9/4.
//

#ifndef FOREXERCISES_WINDOW_MGR_H
#define FOREXERCISES_WINDOW_MGR_H

#include <string>
#include <iostream>
#include <vector>
#include "Screen.h"

using namespace std;

class Window_mgr {
public:
    //类型别名
    using ScreenIndex = vector<Screen>::size_type ;
    //成员函数
    void clear(ScreenIndex i);
    ScreenIndex addScreen(const Screen&);
private:
    vector<Screen> screens {Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &screen) {
    screens.push_back(screen);
    return screens.size() - 1;
}

#endif //FOREXERCISES_WINDOW_MGR_H
