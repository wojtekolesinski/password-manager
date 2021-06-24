#pragma once
#include "Password.h"

namespace util {
    string encode(const string &password);
    string decode(const string &password);
    bool authenticate(string password, string input);
    string parseDelimited(string input, string delimiter, int index);

    struct Node {
        Password data;
        Node* next;
    };

    void addSorted(Node*& head, Password data, int arg);

    class List {
    public:
        List();
        void add(Password* data);
        void delByCategory(string category);
        void del(int index);
        int length();
        void show();
        void showFiltered(string filter);
        void sort(int arg);
    private:
        Node* head;
    };
}

