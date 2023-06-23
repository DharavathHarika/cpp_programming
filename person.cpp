#include "person.h"

Person::Person() {}

Person::Person(const std::string& name, const std::string& email, const std::string& phone)
    : name(name), email(email), phone(phone) {}

std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

std::string Person::getEmail() const {
    return email;
}

void Person::setEmail(const std::string& email) {
    this->email = email;
}

std::string Person::getPhone() const {
    return phone;
}

void Person::setPhone(const std::string& phone) {
    this->phone = phone;
}
