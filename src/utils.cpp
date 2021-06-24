#include "utils.h"
#include <iostream>

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

util::List::List() {}

void util::List::add(Password* data) {
    if (!head) {
        head = new Node{*data, nullptr};
        return;
    }

    Node* nextNode = head;
    while (nextNode->next) {
        nextNode = nextNode->next;
    }
    nextNode->next = new Node{*data, nullptr};
}

void util::List::show() {
    Node* nextNode = head;
    while (nextNode->next) {
        std::cout << nextNode->data << std::endl;
        nextNode = nextNode->next;
    }
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