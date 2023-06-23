#include "employee.h"

Employee::Employee(const std::string& name, const std::string& email, const std::string& phone, double salary)
    : name(name), email(email), phone(phone), salary(salary) {}

const std::string& Employee::getName() const {
    return name;
}

const std::string& Employee::getEmail() const {
    return email;
}

const std::string& Employee::getPhone() const {
    return phone;
}

double Employee::getSalary() const {
    return salary;
}
