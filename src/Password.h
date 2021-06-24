#pragma once
#include <string>
#include <vector>

using std::string, std::vector;

class Password {
private:
    string name;
    string password;
    string category;
public:
    Password(const string &name, const string &password, const string &category);

    const string &getName() const;

    void setName(const string &name);

    const string &getPassword() const;

    void setPassword(const string &password);

    const string &getCategory() const;

    void setCategory(const string &category);

    std::ostream& operator<< (std::ostream& stream);

    friend std::ostream& operator<< (std::ostream& stream, Password password);
};

