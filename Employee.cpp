#include "Employee.h"

Employee::Employee() : id(0), name("Unknown") {}
Employee::Employee(int id, const std::string& name) : id(id), name(name) {}

int Employee::getId() const { return id; }
std::string Employee::getName() const { return name; }

bool Employee::operator<(const Employee& other) const {
    return this->id < other.id;
}

bool Employee::operator==(const Employee& other) const {
    return this->id == other.id && this->name == other.name;
}

bool Employee::operator!=(const Employee& other) const {
    return !(*this == other);
}

int Employee::operator%(int val) const {
    return this->id % val;
}

std::ostream& operator<<(std::ostream& os, const Employee& emp) {
    os << "Emp[" << emp.id << ", " << emp.name << "]";
    return os;
}
