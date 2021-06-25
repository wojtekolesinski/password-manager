#pragma once
#include "utils.h"

class PasswordManager {
private:
    util::List passwords;
    vector<string> categories;
    string path;
    string masterPassword;

public:
    PasswordManager(const string &path);
    void addPassword(string password);
    void addPassword();
    void deletePassword(int index);
    void showPasswords();
    bool addCategory(string category);
    void addCategory();
    void deleteCategory(int index);
    const vector<string> &getCategories() const;
    const util::List &getPasswords() const;
    void filterByCategory(int index);
    void sortPasswords(int sort);
    void load();
    void shutDown();
};

