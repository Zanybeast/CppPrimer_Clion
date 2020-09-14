//
// Created by carl on 2020/9/13.
//

#ifndef FOREXERCISES_EMPLOYEE_H
#define FOREXERCISES_EMPLOYEE_H

#include <string>


class Employee {
public:
    Employee();
    Employee(const std::string &name);
    Employee(const Employee &) = delete;
    Employee &operator= (const Employee &) = delete;

    const unsigned id() const { return pid; }

private:
    std::string pname;
    unsigned pid;
    static unsigned p_increment;
};


#endif //FOREXERCISES_EMPLOYEE_H
