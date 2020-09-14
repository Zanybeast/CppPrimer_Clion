//
// Created by carl on 2020/9/13.
//

#include "Employee.h"

unsigned Employee::p_increment = 0;

Employee::Employee() {
    pid = p_increment++;
}

Employee::Employee(const std::string &name) {
    pid = p_increment++;
    pname = name;
}