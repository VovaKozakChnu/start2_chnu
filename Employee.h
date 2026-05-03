#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
private:
    int id;
    std::string name;

public:
    Employee();
    Employee(int id, const std::string& name);

    int getId() const;
    std::string getName() const;

    bool operator<(const Employee& other) const;
    bool operator==(const Employee& other) const;
    bool operator!=(const Employee& other) const;

    int operator%(int val) const;

    friend std::ostream& operator<<(std::ostream& os, const Employee& emp);
};

#endif
