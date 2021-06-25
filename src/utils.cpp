#include "utils.h"
#include <iostream>
#include <fstream>

string util::decode(const string &password) {
    string result = "";

    for (int i = 0; i < password.length(); i++) {
        result += password[i] - 26;
    }
    return result;
}

string util::encode(const string &password) {
    string result = "";

    for (int i = 0; i < password.length(); i++) {
        result += password[i] + 26;
    }
    return result;
}

bool util::authenticate(string password, string input) {
    return util::decode(password) == input;
}

string util::parseDelimited(string input, string delimiter, int index) {
    int i = 0;

    if (index > 0) {
        int count = 0;
        while (count < index) {
            if(input[i] == delimiter[0])
                count++;
            i++;
        }
    }
    string result;
    while (input[i] != delimiter[0] && i < input.length()) {
        result.push_back(input[i]);
        i++;
    }
    return result;

}

util::List::List() {head = nullptr;}

void util::List::add(Password* data) {
    if (head == nullptr) {
        head = new Node{*data, nullptr};
        return;
    }

    Node* nextNode = head;
    while (nextNode->next) {
        nextNode = nextNode->next;
    }
    nextNode->next = new Node{*data, nullptr};
}

int util::List::length() {
    Node* nextNode = head;
    int counter = 1;
    while (nextNode->next) {
        counter++;
    }
    return counter;
}

void util::List::delByCategory(string category) {
    while (head->data.getCategory() == category) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* nextNode = head->next;
    Node* previous = head;
    while (nextNode) {
        if (nextNode->data.getCategory() == category) {
            Node* temp = nextNode;
            previous->next = nextNode->next;
            delete temp;
        }
        previous = nextNode;
        nextNode = nextNode->next;
    }
}

void util::List::del(int index) {
    if (index > this->length()) {
        return;
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* nextNode = head;
    Node* previous;
    for (int i = 0; i < index; i++) {
        previous = nextNode;
        nextNode = nextNode->next;
    }
    Node* temp = nextNode;
    previous->next = nextNode->next;
    delete temp;
    std::cout << "Password deleted" << std::endl;

}

void util::List::show() {
    Node* nextNode = head;
    int counter = 0;
    while (nextNode->next) {
        std::cout << ++counter << ". " << nextNode->data << std::endl;
        nextNode = nextNode->next;
    }
    std::cout << ++counter << ". " << nextNode->data << std::endl;
}

void util::List::showFiltered(string filter) {
    Node* nextNode = head;
    while (nextNode->next) {
        if (nextNode->data.getCategory() == filter) {
            std::cout << nextNode->data << std::endl;
        }
        nextNode = nextNode->next;
    }
}


void util::List::sort(int arg) {
    if (head == nullptr || head->next == nullptr) return;

    bool sorted;
    do {
        sorted = true;
        Node* nextNode = head;
        while (nextNode->next != nullptr) {
            if ((arg == 1 && nextNode->data.getName() > nextNode->next->data.getName()) ||
                (arg == 2 && nextNode->data.getCategory() > nextNode->next->data.getCategory())) {
                string tempName, tempPass, tempCat;
                tempName = nextNode->data.getName();
                tempPass = nextNode->data.getPassword();
                tempCat = nextNode->data.getCategory();

                nextNode->data.setName(nextNode->next->data.getName());
                nextNode->data.setPassword(nextNode->next->data.getPassword());
                nextNode->data.setCategory(nextNode->next->data.getCategory());

                nextNode->next->data.setName(tempName);
                nextNode->next->data.setPassword(tempPass);
                nextNode->next->data.setCategory(tempCat);
                sorted = false;
            }
            nextNode = nextNode->next;
        }
    } while (!sorted);
}

void util::List::getAsStream(string path) {
    std::ofstream file;
    file.open(path, std::ofstream::app);

    Node* nextNode = head;
    while (nextNode) {
        file << nextNode->data.getName() + ";"
        << util::encode(nextNode->data.getPassword()) + ";"
        << nextNode->data.getCategory()
        << std::endl;
        nextNode = nextNode->next;
    }
    file.close();
}
