#include "Password.h"

Password::Password(const string &name, const string &password, const string &category) : name(name),
                                                                                                   password(password),
                                                                                                   category(
                                                                                                           category) {}


const string &Password::getName() const {
    return name;
}

void Password::setName(const string &name) {
    Password::name = name;
}

const string &Password::getPassword() const {
    return password;
}

void Password::setPassword(const string &password) {
    Password::password = password;
}

const string &Password::getCategory() const {
    return category;
}

void Password::setCategory(const string &category) {
    Password::category = category;
}

std::ostream& operator<< (std::ostream& stream, Password password) {
    return stream << password.name + "\t" << password.password + "\t" << password.category;
}