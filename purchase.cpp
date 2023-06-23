#include "purchase.h"

Purchase::Purchase(const std::string& item, int quantity, double cost)
    : item(item), quantity(quantity), cost(cost) {}

const std::string& Purchase::getItem() const {
    return item;
}

int Purchase::getQuantity() const {
    return quantity;
}

double Purchase::getCost() const {
    return cost;
}

double Purchase::getTotal() const {
    return quantity * cost;
}
