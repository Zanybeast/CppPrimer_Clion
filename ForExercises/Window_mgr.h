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

private:
    vector<Screen> screens {Screen(24, 80, ' ')};
};

#endif //FOREXERCISES_WINDOW_MGR_H
