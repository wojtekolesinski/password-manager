#include <iostream>
#include <fstream>
#include "utils.h"
#include "PasswordManager.h"

enum MenuOptions{
    Exit = 0,
    FilterByCategory,
    Sort,
    AddPassword,
    DeletePassword,
    AddCategory,
    DeleteCategory,
    ShowPasswords,
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
    cout << "7. Show passwords" << endl;
    cout << "0. Exit" << endl;
    cin >> choice;

    if (choice > 7 || choice < 0) return getChoice();
    return choice;
}

int getCategory(PasswordManager passwordManager) {
    using std::cout, std::cin, std::endl;

    vector<string> categories = passwordManager.getCategories();
    int choice;
    cout << "Choose a category: " << endl;
    for (int i = 0; i < categories.size(); i++) {
        cout << i+1 << ". " << categories[i] << endl;
    }

    cin >> choice;
    if (choice < 1 || choice > categories.size()) return getCategory(passwordManager);
    return choice - 1;
}

int getSort() {
    using std::cout, std::cin, std::endl;

    int choice;
    cout << "How would you like to sort the passwords?" << endl;
    cout << "1. by name" << endl;
    cout << "2. by category" << endl;
    cin >> choice;

    if (choice != 1 && choice != 2) return getChoice();
    return choice;
}

int getPassword(PasswordManager passwordManager) {
    using std::cin, std::cout, std::endl;

    int choice;
    cout << "Choose which password to delete: " << endl;
    passwordManager.showPasswords();
    cin >> choice;
    return choice - 1;
}

int main(int argc, char *argv[]) {
    using std::cout, std::cin, std::endl;


    string path = argv[1];
    PasswordManager MANAGER = PasswordManager(path);
    MANAGER.load();

    int choice;
    while (true) {
        switch (getChoice()) {
            case Exit:
                MANAGER.shutDown();
                return 0;
            case FilterByCategory:
                choice = getCategory(MANAGER);
                MANAGER.filterByCategory(choice);
                break;
            case Sort:
                choice = getSort();
                MANAGER.sortPasswords(choice);
                break;
            case AddPassword:
                MANAGER.addPassword();
                break;
            case DeletePassword:
                choice = getPassword(MANAGER);
                MANAGER.deletePassword(choice);
                break;
            case AddCategory:
                MANAGER.addCategory();
                break;
            case DeleteCategory:
                choice = getCategory(MANAGER);
                MANAGER.deleteCategory(choice);
                break;
            case ShowPasswords:
                MANAGER.showPasswords();
                break;
            default:
                break;

        }
    }

}

