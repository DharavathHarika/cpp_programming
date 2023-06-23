#include "company.h"
#include "employee.h"
#include "customer.h"
#include <iostream>

int main()
{
    std::string companyName;
    std::cout << "Company Name: ";
    std::getline(std::cin, companyName);
    Company company = Company::loadData(companyName);

    while (true)
    {
        std::cout << "    MAIN MENU\n";
        std::cout << "1.) Employees\n";
        std::cout << "2.) Sales\n";
        std::cout << "3.) Quit\n";

        int choice;
        std::cout << "\nChoice? ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            while (true)
            {
                company.displayEmployees();
                char operation;
                std::cout << "(A)dd Employee or (M)ain Menu? ";
                std::cin >> operation;
                std::cin.ignore();

                if (operation == 'A' || operation == 'a')
                {
                    std::string name, email, phone;
                    double salary;

                    std::cout << "Name: ";
                    std::getline(std::cin, name);
                    std::cout << "Email: ";
                    std::getline(std::cin, email);
                    std::cout << "Phone: ";
                    std::getline(std::cin, phone);
                    std::cout << "Salary: ";
                    std::cin >> salary;
                    std::cin.ignore();

                    Employee employee(name, email, phone, salary);
                    company.addEmployee(employee);
                }
                else if (operation == 'M' || operation == 'a')
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid choice. Please enter a valid character\n";
                }
            }
        }
        else if (choice == 2)
        {
            while (true)
            {
                char operation;
                std::cout << "(A)dd Customer, Enter a (S)ale, (V)iew Customer, or (M)ain Menu? ";
                std::cin >> operation;
                std::cin.ignore();

                if (operation == 'A' || operation == 'a')
                {
                    std::string name, email, phone;

                    std::cout << "Name: ";
                    std::getline(std::cin, name);
                    std::cout << "Email: ";
                    std::getline(std::cin, email);
                    std::cout << "Phone: ";
                    std::getline(std::cin, phone);

                    Customer customer(name, email, phone);
                    company.addCustomer(customer);
                }
                else if (operation == 'S' || operation == 's')
                {
                    company.displayCustomers();
                    if (company.getCustomerCount() > 0)
                    {

                        int customerChoice;
                        std::cout << "Choice? ";
                        std::cin >> customerChoice;
                        std::cin.ignore();

                        if (customerChoice >= 1 && customerChoice <= company.getCustomerCount())
                        {
                            std::string item;
                            int quantity;
                            double cost;

                            std::cout << "Item: ";
                            std::getline(std::cin, item);
                            std::cout << "Quantity: ";
                            std::cin >> quantity;
                            std::cout << "Cost: ";
                            std::cin >> cost;
                            std::cin.ignore();

                            Purchase purchase(item, quantity, cost);
                            company.addPurchaseToCustomer(customerChoice - 1, purchase);
                        }
                        else
                        {
                            std::cout << "Invalid choice. Please enter a valid number\n";
                        }
                    }
                }
                else if (operation == 'V' || operation == 'v')
                {
                    company.displayCustomers();
                    if (company.getCustomerCount() > 0)
                    {
                        int customerChoice;
                        std::cout << "Choice? ";
                        std::cin >> customerChoice;
                        std::cin.ignore();

                        if (customerChoice >= 1 && customerChoice <= company.getCustomerCount())
                        {
                            company.displayCustomerDetails(customerChoice - 1);
                        }
                        else
                        {
                            std::cout << "Invalid choice. Please enter a valid number\n";
                        }
                    }
                }
                else if (operation == 'M' || operation == 'm')
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid choice. Please enter a valid character\n";
                }
            }
        }
        else if (choice == 3)
        {
            // Save data and exit
            company.saveData();
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please enter a valid number.\n";
        }
    }

    return 0;
}
