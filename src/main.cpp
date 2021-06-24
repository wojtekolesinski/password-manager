#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include "utils.h"
#include "Password.h"
#include "PasswordManager.h"

enum MenuOptions{
    Exit = 0,
    FilterByCategory,
    Sort,
    AddPassword,
    DeletePassword,
    AddCategory,
    DeleteCategory,

};

int getChoice() {
    using std::cout, std::cin, std::endl;

    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Filter passwords by category" << endl;
    cout << "2. Sort passwords" << endl;
    cout << "3. Add a password" << endl;
    cout << "4. Delete a password" << endl;
    cout << "5. Add a category" << endl;
    cout << "6. Delete a category" << endl;
    cout << "0. Exit" << endl;
    cin >> choice;

    if (choice > 6 || choice < 0) return getChoice();
    return choice;
}

int getCategory(PasswordManager passwordManager) {
    using std::cout, std::cin, std::endl;

    vector<string> categories = passwordManager.getCategories();
    int choice;

    for (int i = 0; i < categories.size(); i++) {
        cout << i+1 << ". " << categories[i] << endl;
    }

    cin >> choice;
    if (choice < 0 || choice > categories.size()) return getCategory(passwordManager);
    return choice - 1;
}

int main(int argc, char *argv[]) {
    using std::cout, std::cin, std::endl;

    PasswordManager MANAGER = PasswordManager();

    string path = argv[1];
    std::ifstream file(path);

    string password, input;
    std::getline(file, password);
    do {
        cout << "enter password:" << endl;
        cin >> input;
    } while (!util::authenticate(password, input));

    cout << "CORRECT!" << endl;
    long timestamp;
    file >> timestamp;
    cout << "Last successful login: " << std::ctime(&timestamp);

    string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        MANAGER.addPassword(line);
    }

    MANAGER.showPasswords();

    int i = 0;
    int category;
    while (true) {
        switch (getChoice()) {
            case Exit:
                return 0;
            case FilterByCategory:
                category = getCategory(MANAGER);
                MANAGER.filterByCategory(category);
                break;
            case Sort:
                break;
            case AddPassword:
                break;
            case DeletePassword:
                break;
            case AddCategory:
                break;
            case DeleteCategory:
                break;
            default:
                break;

        }
    }

}
/*
int main() {

    std::cout << util::parseDelimited("main;JKLMNOPRS;private", ";", 0) << std::endl;
    std::cout << util::parseDelimited("main;JKLMNOPRS;private", ";", 1) << std::endl;
    std::cout << util::parseDelimited("main;JKLMNOPRS;private", ";", 2) << std::endl;
}*/
