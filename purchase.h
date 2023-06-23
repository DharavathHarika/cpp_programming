#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>

class Purchase {
public:
    Purchase(const std::string& item, int quantity, double cost);

    const std::string& getItem() const;
    int getQuantity() const;
    double getCost() const;
    double getTotal() const;

private:
    std::string item;
    int quantity;
    double cost;
};

#endif
