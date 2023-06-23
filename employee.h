#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    Employee(const std::string& name, const std::string& email, const std::string& phone, double salary);

    const std::string& getName() const;
    const std::string& getEmail() const;
    const std::string& getPhone() const;
    double getSalary() const;

private:
    std::string name;
    std::string email;
    std::string phone;
    double salary;
};

#endif
