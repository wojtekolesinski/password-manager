#include "PasswordManager.h"
#include <iostream>

void PasswordManager::addPassword(string input) {
    string name = util::parseDelimited(input, ";", 0);
    string password = util::parseDelimited(input, ";", 1);
    string category = util::parseDelimited(input, ";", 2);

    password = util::decode(password);
    addCategory(category);

    PasswordManager::passwords.add(new Password(name, password, category));
}

void PasswordManager::showPasswords() {
    std::cout << "NAME\tPASSWORD\tCATEGORY\t\n";
    passwords.show();
}

void PasswordManager::addCategory(string category) {
    for (string cat: categories) {
        if (cat == category)
            return;
    }
    categories.push_back(category);
}

const vector<string> &PasswordManager::getCategories() const {
    return categories;
}


void PasswordManager::filterByCategory(int index) {
    string category = categories[index];
    std::cout << "NAME\tPASSWORD\tCATEGORY\t\n";
    passwords.showFiltered(category);
}