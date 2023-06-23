#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person();
    Person(const std::string& name, const std::string& email, const std::string& phone);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getEmail() const;
    void setEmail(const std::string& email);

    std::string getPhone() const;
    void setPhone(const std::string& phone);

private:
    std::string name;
    std::string email;
    std::string phone;
};

#endif
