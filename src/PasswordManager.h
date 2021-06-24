#pragma once
#include "utils.h"

class PasswordManager {
private:
    util::List passwords;
    vector<string> categories;

public:
    void addPassword(string password);
    void showPasswords();
    void addCategory(string category);
    const vector<string> &getCategories() const;
    void filterByCategory(int index);
};

