#ifndef COMPANY_H
#define COMPANY_H

#include "employee.h"
#include "customer.h"
#include <vector>
#include <string>

class Company {
private:
    std::string name;
    std::vector<Employee> employees;
    std::vector<Customer> customers;

public:
    Company(const std::string& name);
    void addEmployee(const Employee& employee);
    void addCustomer(const Customer& customer);
    void displayEmployees() const;
    void displayCustomers() const;
    void displayCustomerDetails(int customerIndex) const;
    void addPurchaseToCustomer(int customerIndex, const Purchase& purchase);
    void saveData() const;
    static Company loadData(const std::string& companyName);
    int getCustomerCount() const;
};

#endif
