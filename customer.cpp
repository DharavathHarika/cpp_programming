#include "customer.h"
#include <iostream>

Customer::Customer(const std::string& name, const std::string& email, const std::string& phone)
    : name(name), email(email), phone(phone) {}

void Customer::addPurchase(const Purchase& purchase) {
    purchases.push_back(purchase);
}

void Customer::display() const {
    std::cout << "Name: " << name << "\nEmail: " << email << "\nPhone: " << phone << std::endl;
}

void Customer::displayPurchase() const {
    std::cout << "Item \t\t Price  Quantity  Total" << std::endl;
    for (const Purchase& purchase : purchases) {
        std::cout << purchase.getItem() << "\t\t $" << purchase.getCost() << "  " << purchase.getQuantity()
                  << "  $" << purchase.getTotal() << std::endl;
    }
}

const std::string& Customer::getName() const {
    return name;
}

const std::string& Customer::getEmail() const {
    return email;
}

const std::string& Customer::getPhone() const {
    return phone;
}

const std::vector<Purchase>& Customer::getPurchases() const {
    return purchases;
}

void Customer::setPurchases(const std::vector<Purchase>& purchases) {
    this->purchases = purchases;
}
