#include "company.h"
#include <iostream>
#include <fstream>

Company::Company(const std::string& name)
    : name(name) {}

void Company::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

void Company::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void Company::displayEmployees() const {
    for (const Employee& employee : employees) {
        std::cout << employee.getName() << " <" << employee.getEmail()
                  << ">  Phone: " << employee.getPhone() << " Salary: $" << employee.getSalary()
                  << std::endl;
    }
}

void Company::displayCustomers() const {
    if (customers.empty()) {
        std::cout << "Error: No Customers." << std::endl;
    } else {
        int index = 1;
        for (const Customer& customer : customers) {
            std::cout << index << ".) " << customer.getName() << std::endl;
            ++index;
        }
    }
}

void Company::displayCustomerDetails(int customerIndex) const {
    if (customerIndex >= 0 && customerIndex < customers.size()) {
        const Customer& customer = customers[customerIndex];
        std::cout << customer.getName() << " <" << customer.getEmail() << ">  Phone: " << customer.getPhone() << std::endl;
        std::cout << "\nOrder History\n";
        std::cout << "Item                   Price  Quantity   Total\n";
        const std::vector<Purchase>& purchases = customer.getPurchases();
        for (const Purchase& purchase : purchases) {
            std::cout << std::left << std::setw(23) << purchase.getItem()
                      << std::right << std::setw(7) << purchase.getCost()
                      << std::setw(11) << purchase.getQuantity()
                      << std::setw(9) << (purchase.getCost() * purchase.getQuantity()) << std::endl;
        }
    } else {
        std::cout << "Invalid customer index.\n";
    }
}

void Company::addPurchaseToCustomer(int customerIndex, const Purchase& purchase) {
    if (customerIndex >= 0 && customerIndex < customers.size()) {
        customers[customerIndex].addPurchase(purchase);
    } else {
        std::cout << "Invalid customer index.\n";
    }
}

void Company::saveData() const {
    std::string fileName = name + ".dat";
    std::ofstream file(fileName);
    if (file) {
        file << employees.size() << "\n";
        for (const Employee& employee : employees) {
            file << employee.getName() << "\n";
            file << employee.getEmail() << "\n";
            file << employee.getPhone() << "\n";
            file << employee.getSalary() << "\n";
        }

        file << customers.size() << "\n";
        for (const Customer& customer : customers) {
            file << customer.getName() << "\n";
            file << customer.getEmail() << "\n";
            file << customer.getPhone() << "\n";
            const std::vector<Purchase>& purchases = customer.getPurchases();
            file << purchases.size() << "\n";
            for (const Purchase& purchase : purchases) {
                file << purchase.getItem() << "\n";
                file << purchase.getQuantity() << "\n";
                file << purchase.getCost() << "\n";
            }
        }
        file.close();
    } else {
        std::cout << "Error: Failed to save data." << std::endl;
    }
}

Company Company::loadData(const std::string& companyName) {
    std::string filePath = companyName + ".dat";
    std::ifstream file(filePath);
    if (file) {
        Company company(companyName);

        int noOfEmployees;
        file >> noOfEmployees;
        file.ignore(); 

        for (int i = 0; i < noOfEmployees; ++i) {
            std::string name, email, phone;
            double salary;

            std::getline(file, name);
            std::getline(file, email);
            std::getline(file, phone);
            file >> salary;
            file.ignore(); 

            Employee employee(name, email, phone, salary);
            company.addEmployee(employee);
        }

        int noOfCustomers;
        file >> noOfCustomers;
        file.ignore(); 

        for (int i = 0; i < noOfCustomers; ++i) {
            std::string name, email, phone;
            int noOfPurchases;

            std::getline(file, name);
            std::getline(file, email);
            std::getline(file, phone);
            file >> noOfPurchases;
            file.ignore(); 

            Customer customer(name, email, phone);
            for (int j = 0; j < noOfPurchases; ++j) {
                std::string item;
                int quantity;
                double cost;

                std::getline(file, item);
                file >> quantity;
                file >> cost;
                file.ignore(); 

                Purchase purchase(item, quantity, cost);
                customer.addPurchase(purchase);
            }

            company.addCustomer(customer);
        }

        file.close();
        return company;
    } else {
        return Company(companyName);
    }
}

int Company::getCustomerCount() const {
    return customers.size();
}
