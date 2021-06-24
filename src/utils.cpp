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

void util::addSorted(Node*& head, Password data, int arg) {

    if (head == nullptr) {
        head = new Node {data, nullptr};
        return;
    }
    Node* next = head;
    Node* previous = nullptr;
    if (arg == 1) {
        if (head->data.getName() > data.getName()) {
            head = new Node{data, next};
            return;
        }
        while (next) {
            if (next->data.getName() > data.getName()) {
                previous->next = new Node{data, next};
                return;
            }
            previous = next;
            next = next->next;
        }
    } else {
        if (head->data.getCategory() > data.getCategory()) {
            head = new Node{data, next};
            return;
        }
        while (next) {
            if (next->data.getCategory() > data.getCategory()) {
                previous->next = new Node{data, next};
                return;
            }
            previous = next;
            next = next->next;
        }
    }
    previous->next = new Node{data, nullptr};

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
    // TODO
    Node* newHead = head;
    Node* nextNode = head;

    while (nextNode->next) {
        if (arg == 1) {
            if (nextNode->data.getName() < newHead->data.getName()) {
                Node* temp = newHead;
                newHead = nextNode;
                newHead->next = temp;
                continue;
            }
            Node* previous = newHead;
            Node* innerNext = newHead->next;
            while (innerNext) {
                if (nextNode->data.getName() < innerNext->data.getName()) {
                    previous->next = nextNode;

                }
            }
        }

        nextNode = nextNode->next;
    }

    head = newHead;
}