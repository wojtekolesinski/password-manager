#include "PasswordManager.h"
#include <iostream>
#include <ctime>
#include <fstream>

void PasswordManager::addPassword(string input) {
    string name = util::parseDelimited(input, ";", 0);
    string password = util::parseDelimited(input, ";", 1);
    string category = util::parseDelimited(input, ";", 2);

    password = util::decode(password);
    addCategory(category);
    PasswordManager::passwords.add(new Password(name, password, category));
}

void PasswordManager::addPassword() {
    using std::cout, std::cin, std::endl;

    string name, password, category;
    cout << "Enter the name of your password:" << endl;
    cin >> name;
    cout << "Enter your password:" << endl;
    cin >> password;
    cout << "Choose a category: " << endl;

    int choice{0};
    do {
        for (int i = 0; i < categories.size(); i++) {
            cout << i + 1 << ". " << categories[i] << endl;
        }

        cin >> choice;
    } while (choice < 1 || choice > categories.size());
    category = categories[choice - 1];
    PasswordManager::passwords.add(new Password(name, password, category));
}

void PasswordManager::deletePassword(int index) {
    passwords.del(index);
}

void PasswordManager::showPasswords() {
    std::cout << "NAME\tPASSWORD\tCATEGORY\t\n";
    passwords.show();
}

bool PasswordManager::addCategory(string category) {
    for (string cat: categories) {
        if (cat == category)
            return false;
    }
    categories.push_back(category);
    return true;
}

void PasswordManager::addCategory() {
    using std::cout, std::cin, std::endl;

    string category;
    cout << "Enter your category: " << endl;
    cin >> category;
    if(!addCategory(category)) {
        cout << "Category already exists!" << endl;
        return;
    }
    cout << "Category added successfully";
}

void PasswordManager::deleteCategory(int index) {
    passwords.delByCategory(categories[index]);
    std::cout << "Category " << categories[index] << " deleted successfully" << std::endl;
    categories.erase(categories.begin() + index);
}

const vector<string> &PasswordManager::getCategories() const {
    return categories;
}

void PasswordManager::filterByCategory(int index) {
    string category = categories[index];
    std::cout << "NAME\tPASSWORD\tCATEGORY\t\n";
    passwords.showFiltered(category);
}

void PasswordManager::sortPasswords(int sort) {
    showPasswords();
    passwords.sort(sort);
    showPasswords();
}

const util::List &PasswordManager::getPasswords() const {
    return passwords;
}

PasswordManager::PasswordManager(const string &path) : path(path) {}

void PasswordManager::load() {
    using std::cout, std::cin, std::endl;

    std::ifstream file(path);

    string password, input;
    std::getline(file, password);
    do {
        cout << "enter password:" << endl;
        cin >> input;
    } while (!util::authenticate(password, input));

    masterPassword = password;
    cout << "CORRECT!" << endl;
    long timestamp;
    file >> timestamp;
    cout << "Last successful login: " << std::ctime(&timestamp);

    string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        addPassword(line);
    }
}

void PasswordManager::shutDown() {
    std::ofstream file;
    file.open(path, std::ofstream::trunc | std::ofstream::in);
    file << masterPassword << std::endl;
    file << std::time(0) << std::endl;
    file.close();

    passwords.getAsStream(path);

}
