#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "purchase.h"
#include <vector>
#include <string>

class Customer {
public:
    Customer(const std::string& name, const std::string& email, const std::string& phone);

    void addPurchase(const Purchase& purchase);
    void display() const;
    void displayPurchase() const;
    const std::string& getName() const;
    const std::string& getEmail() const; 
    const std::string& getPhone() const; 
    const std::vector<Purchase>& getPurchases() const;
    void setPurchases(const std::vector<Purchase>& purchases);

private:
    std::string name;
    std::string email;
    std::string phone;
    std::vector<Purchase> purchases;
};

#endif
